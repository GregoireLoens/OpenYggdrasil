/*
 * OpenYggdrasil
 * Author: Gregoire LOENS, Hugo SOSZYNSKI
 *
 */

#ifndef OPENYGGDRASIL_GDT_H
# define OPENYGGDRASIL_GDT_H

#include "types.h"

#define GDT_BASE 0x0
#define GDT_SIZE 0xFF

/* Segment descriptor */
struct gdtdesc {
    u16 lim0_15;
    u16 base0_15;
    u8 base16_23;
    u8 acces;
    u8 lim16_19 : 4;
    u8 other : 4;
    u8 base24_31;
} __attribute__ ((packed));

/* GDTR Register */
struct gdtr {
    u16 limite ;
    u32 base ;
} __attribute__ ((packed));

#ifdef __GDT__
struct gdtdesc kgdt[GDT_SIZE];
struct gdtr kgdtr;
#else
extern struct gdtdesc kgdt[GDT_SIZE];
extern struct gdtr kgdtr;
#endif

void gdt_init(void);

#endif /* !OPENYGGDRASIL_GDT_H */
