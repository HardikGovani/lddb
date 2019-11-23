
#include<linux/module.h>
#include<linux/init.h>
#include<linux/interrupt.h>

#define SHARED_IRQ 1  

static int irq = SHARED_IRQ, my_dev_id, irq_counter =0;

//// param of irq line. 
module_param(irq, int, S_IRUGO);

//// ISR imple. 
static irqreturn_t my_interrupt(int irq, void *dev_id){
    irq_counter++;
    printk(KERN_INFO "IN THE ISR: COUNTER = %d\n",irq_counter);
    return IRQ_NONE;
}


/// request one irq line. 
static int __init my_init(void){
    if(request_irq(irq, my_interrupt,IRQF_SHARED, "my_interrupt", &my_dev_id))  /// reg & request. 
        return -1;
    printk(KERN_INFO "ISR LODEDD SUCCESS!\n");
    return 0;
}

/////////// exit one.
static void __exit my_exit(void){
    synchronize_irq(irq);
    free_irq(irq,&my_dev_id);
    printk(KERN_INFO "ISR UNLOADEDD SUCESS!\n");
}

///// macro. 
module_init(my_init);
module_exit(my_exit);


MODULE_AUTHOR("G.HARDIK");
MODULE_LICENSE("GPL"); 
