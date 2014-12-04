#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/version.h>
#include <linux/vermagic.h>

/* MODULE_LICENSE("Dual BSD/GPL"); */
MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Angelo Yin");
MODULE_DESCRIPTION("Hello world experiment");
MODULE_VERSION("1.0.0");
MODULE_ALIAS("AngeloHello");

static int hello_init(void)
{
	pr_debug("Hello, world\n");
	pr_debug("The process is \"%s\" (pid %i)\n",
	       current->comm, current->pid);

	pr_debug("UTS_RELEASE:%s", UTS_RELEASE);
	pr_debug("LINUX_VERSION_CODE:%d", LINUX_VERSION_CODE);
	pr_debug("KERNEL_VERSION:%d", KERNEL_VERSION(2, 6, 10));
	return 0;
}

static void hello_exit(void)
{
	pr_debug("Goodbye, beautiful world\n");
}

void export_test(void)
{
}
EXPORT_SYMBOL(export_test);

module_init(hello_init);
module_exit(hello_exit);
