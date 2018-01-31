/*
 * OpenYggdrasil
 * Author: Gregoire LOENS, Hugo SOSZYNSKI
 *
 */

#include "types.h"
#include "lib.h"
#define __GDT__
#include "gdt.h"

/*
 * Init a segment descriptor
 * 'desc' is the linear address of the descriptor to init
 */
static void init_gdt_desc(u32 base, u32 limit, u8 access, u8 other,
		   struct gdtdesc* desc)
{
    desc->lim0_15 = (limit & 0xffff);
    desc->base0_15 = (base & 0xffff);
    desc->base16_23 = (base & 0xff0000) >> 16;
    desc->acces = access;
    desc->lim16_19 = (limit & 0xf0000) >> 16;
    desc->other = (other & 0xf);
    desc->base24_31 = (base & 0xff000000) >> 24;
    return;
}

void gdt_init(void)
{
    /*
     * Segment descriptors init
     */
    init_gdt_desc(0x0, 0x0, 0x0, 0x0, &kgdt[0]);
    init_gdt_desc(0x0, 0xFFFFF, 0x9B, 0x0D, &kgdt[1]);      /* code */
    init_gdt_desc(0x0, 0xFFFFF, 0x93, 0x0D, &kgdt[2]);      /* data */
    init_gdt_desc(0x0, 0x0, 0x97, 0x0D, &kgdt[3]);          /* stack */


    kgdtr.limite = GDT_SIZE;
    kgdtr.base = GDT_BASE;

    /* Writting the gdt in memory */
    memcpy((void*)kgdtr.base, (void*)kgdt, kgdtr.limite);

    /* Loading the gdtr register */
    asm("lgdtl (kgdtr)");

    /* Loading the segment */
    asm(
    "    movw $0x10, %ax\n"
    "    movw %ax, %ds\n"
    "    movw %ax, %es\n"
    "    movw %ax, %fs\n"
    "    movw %ax, %gs\n"
    "    ljmp $0x08, $next\n"
    "next:\n"
    );
}