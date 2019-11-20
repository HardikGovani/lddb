
** step to execute **

1> Build the driver (pen_info.ko file) by running make.
2> Load the driver using insmod pen_info.ko.
3> Plug-in the pen drive (after making sure that usb-storage driver is not already loaded).
4> Unplug-out the pen drive.
5> Check the output of dmesg for the logs.
6> Unload the driver using rmmod pen_info.

