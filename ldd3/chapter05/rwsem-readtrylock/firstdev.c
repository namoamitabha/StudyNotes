#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/version.h>
#include <linux/vermagic.h>

#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <asm/uaccess.h>

#include <linux/rwsem.h>

/* MODULE_LICENSE("Dual BSD/GPL"); */
MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Angelo Yin");
MODULE_DESCRIPTION("Hello world experiment");
MODULE_VERSION("1.0.0");
MODULE_ALIAS("AngeloHello");

dev_t dev;
unsigned int count = 4;

struct qset {
	void **data;
	struct qset *next;
};

#define QUANTUM_DEFAULT 4000
#define QSET_DEFAULT 1000

struct fdev {
	struct qset *data;
	int major;
	int minor;
	unsigned long size;
	int quantum_count;
	int qset_count;
	/* struct semaphore sem; */
	struct rw_semaphore sem;
	struct cdev cdev;
};

struct fdev *fdev_p;

static void fdev_exit(void);

int fdev_trim(struct fdev *dev)
{
	pr_alert("trim existing data");
	struct qset *next, *dptr;
	int qset_count = dev->qset_count;
	int i = 0;

	for (dptr = dev->data; dptr; dptr = next) {
		if (dptr->data) {
			for (i = 0; i < qset_count; i++)
				kfree(dptr->data[i]);
			kfree(dptr->data);
			dptr->data = NULL;
		}
		next = dptr->next;
		kfree(dptr);
	}
	dev->size = 0;
	dev->quantum_count = QUANTUM_DEFAULT;
	dev->qset_count = QSET_DEFAULT;
	dev->data = NULL;
	return 0;
}

struct qset *fdev_follow(struct fdev *dev, int n)
{
	struct qset *qs = dev->data;

	if (!qs) {
		qs = dev->data = kmalloc(sizeof(struct qset), GFP_KERNEL);
		if (qs == NULL)
			return NULL;
		memset(qs, 0, sizeof(struct qset));
	}

	while (n--) {
		if (!qs->next) {
			qs->next = kmalloc(sizeof(struct qset), GFP_KERNEL);
			if (qs->next == NULL)
				return NULL;
			memset(qs->next, 0, sizeof(struct qset));
		}
		qs = qs->next;
		continue;
	}

	return qs;
}


loff_t fdev_llseek(struct file *filp, loff_t off, int whence)
{
	pr_alert("fdev_llseek");

	return 0;
}

ssize_t fdev_read(struct file *filp, char __user *buf, size_t count,
		  loff_t *f_pos)
{
	struct fdev *dev = filp->private_data;

	pr_alert("fdev_read, major=%d, minor=%d", dev->major, dev->minor);

	struct qset *dptr;
	int quantum_count = dev->quantum_count;
	int qset_count = dev->qset_count;
	int itemsize = quantum_count * qset_count;
	int item, s_pos, q_pos, rest;
	ssize_t retval = 0;
	
	if (!down_read_trylock(&dev->sem))
		return -ERESTARTSYS;

	if (*f_pos >= dev->size)
		goto out;

	if (*f_pos + count > dev->size)
		count = dev->size - *f_pos;

	item = (long)*f_pos / itemsize;
	rest = (long)*f_pos % itemsize;
	s_pos = rest / quantum_count;
	q_pos = rest % quantum_count;

	pr_alert("f_pos=%d, item=%d, rest=%d, s_pos=%d, q_pos=%d, count=%d",
		 f_pos, item, rest, s_pos, q_pos, count);

	dptr = fdev_follow(dev, item);

	if (dptr == NULL || !dptr->data || !dptr->data[s_pos])
		goto out;

	if (count > quantum_count - q_pos)
		count = quantum_count - q_pos;

	if (copy_to_user(buf, dptr->data[s_pos] + q_pos, count)) {
		retval = -EFAULT;
		goto out;
	}
	*f_pos += count;
	retval = count;
out:
	up_read(&dev->sem);
	return retval;
}

ssize_t fdev_write(struct file *filp, const char __user *buf, size_t count,
		   loff_t *f_pos)
{
	ssize_t retval = -ENOMEM;
	struct fdev *dev = filp->private_data;

	pr_alert("fdev_write, major=%d, minor=%d", dev->major, dev->minor);

	int quantum_count = dev->quantum_count;
	int qset_count = dev->qset_count;
	int item, itemsize, rest, s_pos, q_pos;

	if (!down_write_trylock(&dev->sem))
		return -ERESTARTSYS;

	itemsize = quantum_count * qset_count;
	item = (long)*f_pos / itemsize;
	rest = (long)*f_pos % itemsize;
	s_pos = rest / quantum_count;
	q_pos = rest % quantum_count;

	pr_alert("f_pos=%d, item=%d, rest=%d, s_pos=%d, q_pos=%d, count=%d",
		 f_pos, item, rest, s_pos, q_pos, count);

	struct qset *dptr;

	dptr = fdev_follow(dev, item);
	if (dptr == NULL)
		goto out;

	if (!dptr->data) {
		dptr->data = kmalloc(qset_count * sizeof(char *), GFP_KERNEL);
		if (!dptr->data)
			goto out;
		memset(dptr->data, 0, qset_count * sizeof(char *));
	}
	if (!dptr->data[s_pos]) {
		dptr->data[s_pos] = kmalloc(quantum_count, GFP_KERNEL);
		if (!dptr->data[s_pos])
			goto out;
	}
	if (count > quantum_count - q_pos)
		count = quantum_count - q_pos;
	if (copy_from_user(dptr->data[s_pos] + q_pos, buf, count)) {
		retval = -EFAULT;
		goto out;
	}
	*f_pos += count;
	retval = count;

	if (dev->size < *f_pos)
		dev->size = *f_pos;
out:
	up_write(&dev->sem);
	return retval;
}

long fdev_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	pr_alert("fdev_ioctl");
	return 0;
}

int fdev_open(struct inode *inode, struct file *filp)
{
	struct fdev *dev;

	dev = container_of(inode->i_cdev, struct fdev, cdev);
	filp->private_data = dev;
	pr_alert("fdev_open, major=%d, minor=%d", dev->major, dev->minor);

	int minor = iminor(inode);
	int major = imajor(inode);

	pr_alert("iminor(inode)=%d", minor);
	pr_alert("imajor(inode)=%d", major);

	pr_alert("MODE:%x", (filp->f_flags & O_ACCMODE));

	if ((filp->f_flags & O_ACCMODE) == O_WRONLY) {
		pr_alert("O_WRONLY MODE");
		if (!down_write_trylock(&dev->sem))
			return -ERESTARTSYS;
		fdev_trim(dev);
		up_write(&dev->sem);
	} else if ((filp->f_flags & O_ACCMODE) == O_RDONLY) {
		pr_alert("O_RDONLY MODE");
	} else {
		pr_alert("MODE:%x", (filp->f_flags & O_ACCMODE));
	}

	return 0;
}

int fdev_release(struct inode *inode, struct file *filp)
{
	struct fdev *dev = filp->private_data;

	pr_alert("fdev_release, major=%d, minor=%d", dev->major, dev->minor);

	return 0;
}

const struct file_operations fops = {
	.owner	= THIS_MODULE,
	.llseek	= fdev_llseek,
	.read	= fdev_read,
	.write	= fdev_write,
	.unlocked_ioctl	= fdev_ioctl,
	.open	= fdev_open,
	.release	= fdev_release,
};

static int fdev_init(void)
{
	int result = 0;
	char *name = "firstdev";

	pr_alert("DEVICE:%s\n", name);
	pr_alert("The process is \"%s\" (pid %i)\n",
	       current->comm, current->pid);
	pr_alert("UTS_RELEASE:%s", UTS_RELEASE);
	pr_alert("KERNEL_VERSION:%d", KERNEL_VERSION(2, 6, 10));

	unsigned int firstminor = 0;
	int err;

	err = alloc_chrdev_region(&dev, firstminor, count, name);
	if (!err) {
		pr_alert("alloc_chrdev_region successful.");
		pr_alert("dev_t:%d,Major=%d,Minor=%d",
			dev, MAJOR(dev), MINOR(dev));
	} else {
		pr_alert("alloc_chrdev_region failed.");
	}

	fdev_p = kmalloc_array(count, sizeof(struct fdev), GFP_KERNEL);
	if (!fdev_p) {
		result = -ENOMEM;
		pr_alert("kmalloc fdev_p failed.");
		goto fail;
	} else {
		pr_alert("kmalloc fdev_p successful.");
	}

	memset(fdev_p, 0, count * sizeof(struct fdev));

	int i, major, devno;

	major = MAJOR(dev);
	for (i = 0; i < count; ++i) {
		struct fdev *devp = &fdev_p[i];

		init_rwsem(&devp->sem);
		devno = MKDEV(major, i);
		devp->major = major;
		devp->minor = i;

		devp->quantum_count = QUANTUM_DEFAULT;
		devp->qset_count = QSET_DEFAULT;

		cdev_init(&devp->cdev, &fops);
		devp->cdev.owner = THIS_MODULE;
		devp->cdev.ops = &fops;
		err = cdev_add(&devp->cdev, devno, 1);
		if (err)
			pr_alert("Error %d adding firstdev %d", err, i);
		else
			pr_alert("Successful adding firstdev %d", i);
	}
	return 0;
fail:
	fdev_exit();
	return result;
}

static void fdev_exit(void)
{
	int i;

	if (fdev_p) {
		for (i = 0; i < count; ++i) {
			fdev_trim(fdev_p + i);
			cdev_del(&fdev_p[i].cdev);
			pr_alert("cdev_del(&fdev_p[i].cdev)-%d", i);
		}
		kfree(fdev_p);
		pr_alert("kfree(fdev_p);");
	}
	unregister_chrdev_region(dev, count);
	pr_alert("unregister_chrdev_region(first, count);");
	pr_alert("Goodbye, beautiful world\n");
}

void export_test(void)
{
}
EXPORT_SYMBOL(export_test);

module_init(fdev_init);
module_exit(fdev_exit);
