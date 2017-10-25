##
## OpenYggdrasil
## Authors: Gregoire LOENS Hugo SOSZYNSKI
##

NAME		=	OpenYggdrasil

BOOTNAME	=	bootsect

GCC		=	gcc

NASM		=	nasm

LD		=	ld

CFLAGS  +=  -Iincludes/ -m32

KERNELSRC	=	$(SRCDIR)kernel/kernel.c \
                $(SRCDIR)kernel/screen.c

BOOTSRC		=	$(SRCDIR)sector_protege.asm

SRCDIR		=	sources/

KERNELOBJ	=	$(KERNELSRC:.c=.o)



all:	kernel boot

kernel: $(KERNELOBJ)
	$(LD) -m elf_i386 --oformat binary -Ttext 1000 $(KERNELOBJ) -o $(NAME)

boot:
	$(NASM) -i $(SRCDIR) -f bin -o $(BOOTNAME) sources/sector_protege.asm

clean:
	rm -rf $(KERNELOBJ)

fclean: clean
	rm -rf $(BOOTNAME) $(NAME)
