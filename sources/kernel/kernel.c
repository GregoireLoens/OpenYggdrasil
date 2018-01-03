/*
 * OpenYggdrasil
 * Author: Gregoire LOENS, Hugo SOSZYNSKI
 *
 */

#include "gdt.h"
#include "screen.h"

void _start(void)
{
    clear();
    curs_y = 18;
    curs_attr = 0b00011010;
    print("Booting OpenYggdrasil...\n");

    print("[..] Loading gdt\n");
    gdt_init();
    asm(
    "    movw $0x18, %ax\n"
    "    movw %ax, %ss\n"
    "    movl $0x20000, %esp"
    );
    print("[OK] Gdt loaded\n");

    main();
}

int main(void)
{
    curs_attr = DEFAULT_CURSOR_ATTRIBUTE;
    print("Welcome to OpenYggdrasil\n");
    while(1);
}


