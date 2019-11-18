//simple hello world linux module //

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Hardik Govani");
MODULE_DESCRIPTION("A simple example Linux module.");
MODULE_VERSION("0.01");

static int __init first_init(void) {
	printk(KERN_INFO "Hello, World! This is my First Linux Module\n");
 return 0;
}

static void __exit first_exit(void) {
 printk(KERN_INFO "Goodbye, World!\n");
}

module_init(first_init);
module_exit(first_exit);
