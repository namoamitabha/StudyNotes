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

static int dev_t_test_init(void)
{
	pr_alert("Hello, world\n");
	pr_alert("The process is \"%s\" (pid %i)\n",
	       current->comm, current->pid);

	pr_alert("UTS_RELEASE:%s", UTS_RELEASE);
	/* pr_alert("LINUX_VERSION_CODE:%d", LINUX_VERSION_CODE); */
	pr_alert("KERNEL_VERSION:%d", KERNEL_VERSION(2, 6, 10));

	dev_t dev;
	int major = 1;
	int minor = 2;

	dev = MKDEV(major, minor);
	pr_alert("dev_t:%d", dev);
	pr_alert("MAJOR:%d", MAJOR(dev));
	pr_alert("MINOR:%d", MINOR(dev));

	return 0;
}

static void dev_t_test_exit(void)
{
	pr_alert("Goodbye, beautiful world\n");
}

void export_test(void)
{
}
EXPORT_SYMBOL(export_test);

module_init(dev_t_test_init);
module_exit(dev_t_test_exit);
