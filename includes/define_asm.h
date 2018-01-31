#ifndef DEFINE_ASM_H
# define DEFINE_ASM_H

/* disable interruption */
#define cli asm("cli"::)

/* enable interruption */
#define sti asm("sti"::)

/* write an octet on the port */
#define outb(port,value) \
        asm volatile ("outb %%al, %%dx" :: "d" (port), "a" (value));

/* write an octet on the port with a delay */
#define outbp(port,value) \
        asm volatile ("outb %%al, %%dx; jmp 1f; 1:" :: "d" (port), "a" (value));

/* read on the port */
#define inb(port) ({    \
        unsigned char _v;       \
        asm volatile ("inb %%dx, %%al" : "=a" (_v) : "d" (port)); \
        _v;     \
})

#endif /* DEFINE_ASM_H */
