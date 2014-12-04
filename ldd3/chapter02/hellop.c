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

static char *whom = "world";
static int howmany = 1;
module_param(whom, charp, S_IRUGO);
module_param(howmany, int, S_IRUGO);

static int hello_init(void)
{
	int i = 0;

	for (i = 0; i < howmany; ++i) {
		printk(KERN_ALERT "Hello, %s\n", whom);
	}

	printk(KERN_INFO "The process is \"%s\" (pid %i)\n",
	       current->comm, current->pid);

	printk(KERN_ALERT "UTS_RELEASE:%s", UTS_RELEASE);
	printk(KERN_ALERT "LINUX_VERSION_CODE:%d", LINUX_VERSION_CODE);
	printk(KERN_ALERT "KERNEL_VERSION:%d", KERNEL_VERSION(2, 6, 10));
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

/* module param using example */
/* $ sudo insmod hellop.ko howmany=10 whom="Mom" */
