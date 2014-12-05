obj-m := dev_t_test.o register_chrdev_region_test.o

ifneq ($(KERNELRELEASE),)
	obj-m := dev_t_test.o register_chrdev_region_test.o
else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean

endif


# insmod: ERROR: could not insert module r_chrdev_rg_test.ko: Invalid module format
