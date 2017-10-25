/*
 * OpenYggdrasil
 * Author: Gregoire LOENS, Hugo SOSZYNSKI
 *
 */


#ifndef OPENYGGDRASIL_SCREEN_H
# define OPENYGGDRASIL_SCREEN_H

# include "types.h"

# define SCREEN_COLUMNS 160 /* 80 x 2 */
# define SCREEN_LINES 25
# define RAMSCREEN 0xB8000 /* debut de la memoire video */
# define SIZESCREEN (SCREEN_COLUMNS * SCREEN_LINES) /* 4000, nombres d'octets d'une page texte */
# define SCREENLIM (RAMSCREEN + SIZESCREEN)

# define DEFAULT_CURSOR_ATTRIBUTE 0b00000111 /* blanc sur noir sans cligno et int */

extern char curs_x;
extern char curs_y;
extern char curs_attr;

/*
 * function definition
 */

void scrollup(unsigned int n);
void putcar(uchar c);
void print(char* string);


#endif /* OPENYGGDRASIL_SCREEN_H */
