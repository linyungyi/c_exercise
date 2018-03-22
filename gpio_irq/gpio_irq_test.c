// Last Update:2016-05-05 09:12:58
/**
 * @File: gpio_irq_test.c
 * @Brief: Test GPIO interrupt using Linux Device Tree.
 * @Author: Sanford Wen, shengfan.wen@archermind.com
 * @Version: 0.1
 * @Created: 2016-05-04
 */


#include <linux/module.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/interrupt.h>
#if defined(CONFIG_OF)
#include <linux/of.h>
#include <linux/of_irq.h>
#endif

static irqreturn_t eint_handler(int irq, void *arg)
{
    printk("Hello, here.~~~~~~~~~\n");

    return IRQ_HANDLED;
}

static int gpio_irq_probe(struct platform_device *dev)
{
#if defined(CONFIG_OF)
    struct device_node * node;
    struct pinctrl *pinctrl;
    struct pinctrl_state *pin_default;
    struct pinctrl_state *pin_eint;
    int irq;
    int ret;
    
    node = dev->dev.of_node;
    if (node == NULL)
    {
        printk(KERN_ERR "The driver is not probe by device tree.\n");
        return -ENODEV;
    }

    pinctrl = devm_pinctrl_get(&dev->dev);

    pin_default = pinctrl_lookup_state(pinctrl, "pin_default");

    pin_eint = pinctrl_lookup_state(pinctrl, "pin_cfg");

    pinctrl_select_state(pinctrl, pin_eint);

    irq = irq_of_parse_and_map(node, 0);

    printk("irq = %d\n", irq);

    ret =  request_irq(irq, eint_handler, IRQF_TRIGGER_FALLING, "ALS-eint", NULL);

    if (ret)
    {
        printk(KERN_ERR "Register irq error.\n");
        return -EINVAL;
    }

    enable_irq(irq);

    return 0;

#endif
}

static void gpio_irq_shutdown(struct platform_device *dev)
{

}

#ifdef CONFIG_OF
static const struct of_device_id als_ps_of_match[] = {
    {.compatible = "mediatek,als_ps",},
    {},  
};
#endif


static struct platform_driver gpio_irq_driver = {
    .probe = gpio_irq_probe,
    .shutdown = gpio_irq_shutdown,
    .driver = {
        .name = "gpio_irq_test",
#if defined(CONFIG_OF)
        .of_match_table = als_ps_of_match,
#endif
    }
};



static int gpio_irq_init(void)
{
    return platform_driver_register(&gpio_irq_driver);
}

static void gpio_irq_exit(void)
{
    platform_driver_unregister(&gpio_irq_driver);
}

module_init(gpio_irq_init);
module_exit(gpio_irq_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Shengfan.Wen, shengfan.wen@archermind.com");
