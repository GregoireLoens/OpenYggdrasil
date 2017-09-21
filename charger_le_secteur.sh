nasm -f bin -o bootsect sources/sector.asm
cat bootsect /dev/zero | dd of=floppyA bs=512 count=28
qemu-system-x86_64 "floppyA"
