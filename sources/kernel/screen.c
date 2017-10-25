/*
 * OpenYggdrasil
 * Author: Gregoire LOENS, Hugo SOSZYNSKI
 *
 */

#include "screen.h"

char curs_x = 0;
char curs_y = 17;
char curs_attr = DEFAULT_CURSOR_ATTRIBUTE;


void scrollup(unsigned int n)
{
    uchar* video;
    uchar* tmp;

    for (video = (uchar *)(RAMSCREEN); video < (uchar *)(SCREENLIM); video += 2)
    {
        tmp = (video + n * SCREEN_COLUMNS);
        if (tmp < (uchar *)(SCREENLIM))
        {
            *video = *tmp;
            *(video + 1) = *(tmp + 1);
        }
        else
        {
            *video = 0;
            *(video + 1) = 0b00000111;
        }
    }
    curs_y -= n;
    if (curs_y < 0)
        curs_y = 0;
}

void putcar(uchar c)
{
    unsigned char*  video;

    switch (c){
        case '\n':
            curs_x = 0;
            ++curs_y;
            break;
        case '\t':
            curs_x += 8 - (curs_x % 8);
            break;
        case '\r':
            curs_x = 0;
            break;
        default:
            video = (unsigned char *) (RAMSCREEN + 2 * curs_x  + SCREEN_COLUMNS * curs_y);
            *video = c;
            *(video + 1) = curs_attr;
            ++curs_x;
            if (curs_x > 79)
            {
                curs_x = 0;
                ++curs_y;
            }
    }
    if (curs_y > 24)
        scrollup(curs_y - 24);
}


void print(char* string)
{
    while (*string)
    {
        putcar(*string);
        string++;
    }
}

