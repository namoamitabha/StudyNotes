#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/version.h>
#include <linux/vermagic.h>

#include <linux/types.h>
#include <linux/kdev_t.h>

#include <linux/fs.h>

/* MODULE_LICENSE("Dual BSD/GPL"); */
MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Angelo Yin");
MODULE_DESCRIPTION("Hello world experiment");
MODULE_VERSION("1.0.0");
MODULE_ALIAS("AngeloHello");

dev_t dev;
unsigned int count = 5;

static int alloc_chrdev_region_init(void)
{
	pr_alert("Hello, world\n");
	pr_alert("The process is \"%s\" (pid %i)\n",
	       current->comm, current->pid);

	pr_alert("UTS_RELEASE:%s", UTS_RELEASE);
	/* pr_alert("LINUX_VERSION_CODE:%d", LINUX_VERSION_CODE); */
	pr_alert("KERNEL_VERSION:%d", KERNEL_VERSION(2, 6, 10));

	char *name = "alloc_chrdev_region_test";
	unsigned int firstminor = 0;
	int err;

	err = alloc_chrdev_region(&dev, firstminor, count, name);
	if (err) {
		pr_alert("alloc_chrdev_region successful.");
		pr_alert("dev_t:%d,Major=%d,Minor=%d", dev, MAJOR(dev), MINOR(dev));
	} else {
		pr_alert("alloc_chrdev_region failed.");
	}

	return 0;
}

static void alloc_chrdev_region_exit(void)
{
	unregister_chrdev_region(dev, count);
	pr_alert("	unregister_chrdev_region(first, count);");

	pr_alert("Goodbye, beautiful world\n");
}

void export_test(void)
{
}
EXPORT_SYMBOL(export_test);

module_init(alloc_chrdev_region_init);
module_exit(alloc_chrdev_region_exit);
