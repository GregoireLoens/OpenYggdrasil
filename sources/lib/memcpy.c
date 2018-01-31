/*
 * OpenYggdrasil
 * Author: Gregoire LOENS, Hugo SOSZYNSKI
 *
 */

void* memcpy(void* dest, const void* src, unsigned int n)
{
    char* d = dest;
    char* s = src;

    while (n--)
	*d++ = *s++;
    return dest;
}