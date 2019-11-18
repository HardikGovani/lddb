* this is simple null char driver *
-> make all
-> insmod char_null.ko
-> dmesg | tail -10 
-> echo "Hi There this is my first null char driver" > /dev/mynull

