#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/version.h>
#include <linux/vermagic.h>

#include <linux/types.h>
#include <linux/kdev_t.h>

/* MODULE_LICENSE("Dual BSD/GPL"); */
MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Angelo Yin");
MODULE_DESCRIPTION("Hello world experiment");
MODULE_VERSION("1.0.0");
MODULE_ALIAS("AngeloHello");

static int hello_init(void)
{
	printk(KERN_ALERT "Hello, world\n");
	printk(KERN_ALERT "The process is \"%s\" (pid %i)\n",
	       current->comm, current->pid);

	printk(KERN_ALERT "UTS_RELEASE:%s", UTS_RELEASE);
	printk(KERN_ALERT "LINUX_VERSION_CODE:%d", LINUX_VERSION_CODE);
	printk(KERN_ALERT "KERNEL_VERSION:%d", KERNEL_VERSION(2, 6, 10));

	dev_t dev;
	int major = 1;
	int minor = 2;
	dev = MKDEV(major, minor);
	printk(KERN_ALERT "dev_t:%d", dev);
	printk(KERN_ALERT "MAJOR:%d", MAJOR(dev));
	printk(KERN_ALERT "MINOR:%d", MINOR(dev));

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "Goodbye, beautiful world\n");
}

void export_test(void)
{
}
EXPORT_SYMBOL(export_test);

module_init(hello_init);
module_exit(hello_exit);
