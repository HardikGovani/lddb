#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>

static dev_t char_null; // Global variable for the first device number
static struct cdev c_dev; // Global variable for the character device structure
static struct class *cl; // Global variable for the device class

static int my_open(struct inode *i, struct file *f)
{
    printk(KERN_INFO "Driver: open()\n");
    return 0;
}

static int my_close(struct inode *i, struct file *f)
{
    printk(KERN_INFO "Driver: close()\n");
    return 0;
}

static ssize_t my_read(struct file *f, char __user *buf, size_t len, loff_t *off)
{
    printk(KERN_INFO "Driver: read()\n");
    return 0;
}

static ssize_t my_write(struct file *f, const char __user *buf, size_t len,
    loff_t *off)
{
    printk(KERN_INFO "Driver: write()\n");
    return len;
}

static struct file_operations pugs_fops =
{
    .owner = THIS_MODULE,
    .open = my_open,
    .release = my_close,
    .read = my_read,
    .write = my_write
};

static int __init char_null_init(void) /* Constructor */
{
    int ret;
    struct device *dev_ret;

    printk(KERN_INFO "Namaskar: char_null registered");
    if ((ret = alloc_chrdev_region(&char_null, 0, 1, "hardik")) < 0)
    {
        return ret;
    }
    if (IS_ERR(cl = class_create(THIS_MODULE, "chardrv")))
    {
        unregister_chrdev_region(char_null, 1);
        return PTR_ERR(cl);
    }
    if (IS_ERR(dev_ret = device_create(cl, NULL, char_null, NULL, "mynull")))
    {
        class_destroy(cl);
        unregister_chrdev_region(char_null, 1);
        return PTR_ERR(dev_ret);
    }

    cdev_init(&c_dev, &pugs_fops);
    if ((ret = cdev_add(&c_dev, char_null, 1)) < 0)
    {
        device_destroy(cl, char_null);
        class_destroy(cl);
        unregister_chrdev_region(char_null, 1);
        return ret;
    }
    return 0;
}

static void __exit char_null_exit(void) /* Destructor */
{
    cdev_del(&c_dev);
    device_destroy(cl, char_null);
    class_destroy(cl);
    unregister_chrdev_region(char_null, 1);
    printk(KERN_INFO "Alvida: char_null unregistered");
}

module_init(char_null_init);
module_exit(char_null_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("G.Hardik <govanihardik@gmail.com>");
MODULE_DESCRIPTION("char_null / Implemntation.");
