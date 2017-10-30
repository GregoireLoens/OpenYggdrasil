/*
 * OpenYggdrasil
 * Author: Gregoire LOENS, Hugo SOSZYNSKI
 *
 */


#ifndef OPENYGGDRASIL_SCREEN_H
# define OPENYGGDRASIL_SCREEN_H

# include "types.h"

/*
 * Screen info macros
 */

# define SCREEN_COLUMNS 160 /* 80 x 2 */
# define SCREEN_LINES 25
# define RAMSCREEN 0xB8000 /* Start of the video memory */
# define SIZESCREEN (SCREEN_COLUMNS * SCREEN_LINES) /* 4000, bytes nbr of the full screen */
# define SCREENLIM (RAMSCREEN + SIZESCREEN) /* Address after the last byte of the video memory */
# define DEFAULT_CURSOR_ATTRIBUTE 0b00000111 /* White on black, without sur-intensity, without blink */

/*
 * Defining the clear() macro. No need to do a function here.
 */

# define clear() scrollup(SCREEN_LINES)

/*
 * Global cursor attributes
 */

extern char curs_x; /* The X pos of the cursor (between 0 and 80) */
extern char curs_y; /* The Y pos of the cursor (between 0 and 24) */
extern char curs_attr; /* The attributes of the chars to be print */

/*
 * Functions
 */

void scrollup(unsigned int n);
void putcar(uchar c);
void print(char* string);


#endif /* OPENYGGDRASIL_SCREEN_H */
