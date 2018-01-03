##
## OpenYggdrasil
## Authors: Gregoire LOENS Hugo SOSZYNSKI
##

NAME		=	OpenYggdrasil

BOOTNAME	=	bootsect

GCC		=	gcc

NASM		=	nasm

LD		=	ld

CFLAGS  +=  -Iincludes/ -m32 -fno-pic

KERNELSRC	=	$(SRCDIR)kernel/kernel.c \
                $(SRCDIR)kernel/screen.c \
                $(SRCDIR)kernel/gdt_init.c \
                $(SRCDIR)lib/memcpy.c

BOOTSRC		=	$(SRCDIR)sector_protege.asm

SRCDIR		=	sources/

KERNELOBJ	=	$(KERNELSRC:.c=.o)



all:	floppyA

floppyA: kernel boot
	cat bootsect OpenYggdrasil /dev/zero | dd of=floppyA bs=512 count=2880
	qemu-system-i386 "floppyA"

kernel: $(KERNELOBJ)
	$(LD) -m elf_i386 --oformat binary -Ttext 1000 $(KERNELOBJ) -o $(NAME)

boot:
	$(NASM) -i $(SRCDIR) -f bin -o $(BOOTNAME) sources/sector_protege.asm

clean:
	rm -rf $(KERNELOBJ)

fclean: clean
	rm -rf $(BOOTNAME) $(NAME) floppyA
