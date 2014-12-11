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

/* MODULE_LICENSE("Dual BSD/GPL"); */
MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Angelo Yin");
MODULE_DESCRIPTION("Hello world experiment");
MODULE_VERSION("1.0.0");
MODULE_ALIAS("AngeloHello");

dev_t dev;
unsigned int count = 4;

struct firstdev {
	int major;
	int minor;
	struct cdev cdev;
};

struct firstdev *firstdev_p;

static void firstdev_exit(void);

loff_t fdev_llseek(struct file *filp, loff_t off, int whence)
{
	pr_alert("fdev_llseek");
	return 0;
}

ssize_t fdev_read(struct file *filp, char __user *buf, size_t count,
		  loff_t *f_pos)
{
	struct firstdev *dev = filp->private_data;

	pr_alert("fdev_read, major=%d, minor=%d", dev->major, dev->minor);
	return 0;
}

ssize_t fdev_write(struct file *filp, const char __user *buf, size_t count,
		   loff_t *f_pos)
{
	struct firstdev *dev = filp->private_data;

	pr_alert("fdev_write, major=%d, minor=%d", dev->major, dev->minor);
	return 0;
}

long fdev_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	pr_alert("fdev_ioctl");
	return 0;
}

int fdev_open(struct inode *inode, struct file *filp)
{
	struct firstdev *dev;

	dev = container_of(inode->i_cdev, struct firstdev, cdev);
	filp->private_data = dev;

	pr_alert("fdev_open, major=%d, minor=%d", dev->major, dev->minor);

	return 0;
}

int fdev_release(struct inode *inode, struct file *filp)
{
	struct firstdev *dev = filp->private_data;

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

static int firstdev_init(void)
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



	firstdev_p = kmalloc_array(count, sizeof(struct firstdev), GFP_KERNEL);
	if (!firstdev_p) {
		result = -ENOMEM;
		pr_alert("kmalloc firstdev_p failed.");
		goto fail;
	} else {
		pr_alert("kmalloc firstdev_p successful.");
	}

	memset(firstdev_p, 0, count * sizeof(struct firstdev));

	int i, major, devno;

	major = MAJOR(dev);

	for (i = 0; i < count; ++i) {
		struct firstdev *p = &firstdev_p[i];

		devno = MKDEV(major, i);
		p->major = major;
		p->minor = i;
		cdev_init(&p->cdev, &fops);
		p->cdev.owner = THIS_MODULE;
		p->cdev.ops = &fops;
		err = cdev_add(&p->cdev, devno, 1);
		if (err)
			pr_alert("Error %d adding firstdev %d", err, i);
		else
			pr_alert("Successful adding firstdev %d", i);
	}
	return 0;
fail:
	firstdev_exit();
	return result;
}

static void firstdev_exit(void)
{
	int i;

	if (firstdev_p) {
		for (i = 0; i < count; ++i) {
			cdev_del(&firstdev_p[i].cdev);
			pr_alert("cdev_del(&firstdev_p[i].cdev)-%d", i);
		}
		kfree(firstdev_p);
		pr_alert("kfree(firstdev_p);");
	}

	unregister_chrdev_region(dev, count);

	pr_alert("unregister_chrdev_region(first, count);");

	pr_alert("Goodbye, beautiful world\n");
}

void export_test(void)
{
}
EXPORT_SYMBOL(export_test);

module_init(firstdev_init);
module_exit(firstdev_exit);
