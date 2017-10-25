/*
 * OpenYggdrasil
 * Author: Gregoire LOENS, Hugo SOSZYNSKI
 *
 */

#include "screen.h"


    void _start(void)
    {
        curs_y = 18;
        print("Alcoolemie aigue en contexte festif\n");
        print("Bonjour je suis OpenYggdrasil\n");
        scrollup(2);

        while (1);
    }


