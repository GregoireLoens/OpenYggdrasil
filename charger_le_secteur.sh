make
cat bootsect OpenYggdrasil /dev/zero | dd of=floppyA bs=512 count=2880
qemu-system-i386 "floppyA"
