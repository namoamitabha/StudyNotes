#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

static int hello_init(void)
{
	printk(KERN_ALERT "Hello, world\n");
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
