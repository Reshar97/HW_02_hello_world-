PWD := $(shell pwd)
KERNEL_DIR ?= /lib/modules/$(shell uname -r)/build

DRV_NAME := hello
obj-m := $(DRV_NAME).o

.PHONY: build run remove install uninstall clean check format

build:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules

run:
	insmod $(PWD)/$(DRV_NAME).ko

remove:
	rmmod $(DRV_NAME).ko

install:
	cp $(DRV_NAME).ko /lib/modules/$(shell uname -r)
	/sbin/depmod -a
	/sbin/modprobe $(DRV_NAME)

uninstall:
	/sbin/modprobe -r $(DRV_NAME)
	rm -f /lib/modules/$(shell uname -r)/$(DRV_NAME).ko
	/sbin/depmod -a

clean: 
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean

format:
	clang-format hello.c

check:
	if [ -f check.sh ]; then \
		bash check.sh; \
		elif [ -f main.py ]; then \
		./main.py hello; \
		else \
		echo "Файл проверки (check.sh или check.py) не найден."; \
		fi
