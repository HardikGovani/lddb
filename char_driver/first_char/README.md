* Testing the Example *
1> complie the module/char driver : sudo make all
2> test the module: sudo make test 
--> it will insert the module & gives the major number
3> now create device file with same MAJOR number
sudo mknod /dev/first_char c MAJOR 0
---> replace 'MAJOR' with output major number
4> now we can grab content from the device:
cat /dev/first_char

-- That's all!!!

