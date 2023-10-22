#include <linux/init.h> 
#include <linux/kernel.h>
#include <linux/module.h> 
#include <linux/moduleparam.h> 
#include <linux/printk.h> 
#include <linux/stat.h> 
 
MODULE_LICENSE("GPL"); 
  
static int myage = 0;  
static char *myname = "nobody"; 
static int mybirthday[2] = {0, 0}; 
static int arr_argc = 0; 
  
module_param(myage, int, 0000); 
MODULE_PARM_DESC(myage, "My age"); 
module_param(myname, charp, 0000); 
MODULE_PARM_DESC(myname, "My name"); 
module_param_array(mybirthday, int, &arr_argc, 0000);
MODULE_PARM_DESC(mybirthday, "An array for birthday date");

static int __init proc_init(void) 
{ 
    pr_info("Hello, world\n"); 
    
    pr_info("my age is: %d\n", myage); 
    pr_info("my name is: %s\n", myname); 
    pr_info("my birthday is: %d/%d\n",mybirthday[0], mybirthday[1]);
    return 0;
} 
 
static void __exit proc_exit(void) 
{ 
    pr_info("Goodbye, world\n");
} 
 
module_init(proc_init); 
module_exit(proc_exit);
