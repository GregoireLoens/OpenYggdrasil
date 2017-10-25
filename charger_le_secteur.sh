make
cat bootsect kernel /dev/zero | dd of=floppyA bs=512 count=2880
qemu-system-x86_64 "floppyA"
