nasm -i sources/ -f bin -o bootsect sources/sector_protege.asm
nasm -f bin -o kernel sources/mini_kernel.asm
cat bootsect kernel /dev/zero | dd of=floppyA bs=512 count=2880
qemu-system-x86_64 "floppyA"
