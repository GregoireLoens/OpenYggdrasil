##
## OpenYggdrasil
## Authors: Gregoire LOENS Hugo SOSZYNSKI
##

NAME		=	OpenYggdrasil

BOOTNAME	=	boostsect

GCC		=	gcc

NASM		=	nasm

LD		=	ld

KERNELSRC	=	kernel.c

BOOTSRC		=	$(SRCDIR)sector_protege.asm

SRCDIR		=	sources/

KERNELOBJ	=	$(OBJ:.c=.o)



all:	kernel boot

kernel:
	$(LD) --oformat binary -Ttext 1000 $(KERNELOBJ) -o $(NAME)  

boot:
	$(NASM) -i $(SRCDIR) -f bin -o $(BOOTNAME) $(BOOSTSRC)

clean:
	rm -rf $(KERNELOBJ)

fclean: clean
	rm -rf $(BOOTNAME) $(NAME)
