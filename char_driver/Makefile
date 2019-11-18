obj-m += first_char.o
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
test:
	# We put a — in front of the rmmod command to tell make to ignore
	# an error in case the module isn’t loaded.
	-sudo rmmod first_char
	# Clear the kernel log without echo
	sudo dmesg -C
	# Insert the module
	sudo insmod first_char.ko
	# Display the kernel log
	dmesg
