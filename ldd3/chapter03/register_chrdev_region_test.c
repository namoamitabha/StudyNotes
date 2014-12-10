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

dev_t first = MKDEV(300, 0);
unsigned int count = 5;

static int register_chrdev_region_init(void)
{
	pr_alert("Hello, world\n");
	pr_alert("The process is \"%s\" (pid %i)\n",
	       current->comm, current->pid);

	pr_alert("UTS_RELEASE:%s", UTS_RELEASE);
	/* pr_alert("LINUX_VERSION_CODE:%d", LINUX_VERSION_CODE); */
	pr_alert("KERNEL_VERSION:%d", KERNEL_VERSION(2, 6, 10));

	char *name = "register_chrdev_region_test";
	int error;

	error = register_chrdev_region(first, count, name);
	pr_alert("error=%d", error);

	if (!error) {
		pr_alert("Major=%d, minor=%d",
			 MAJOR(first), MINOR(first));

		pr_alert("register chardev region successful");

	} else {
		pr_alert("register chardev region failed. error:%d", error);
	}

	return 0;
}

static void register_chrdev_region_exit(void)
{
	unregister_chrdev_region(first, count);
	pr_alert("unregister_chrdev_region, Major=%d, minor=%d",
		 MAJOR(first), MINOR(first));

	pr_alert("Goodbye, beautiful world\n");
}

void export_test(void)
{
}
EXPORT_SYMBOL(export_test);

module_init(register_chrdev_region_init);
module_exit(register_chrdev_region_exit);
