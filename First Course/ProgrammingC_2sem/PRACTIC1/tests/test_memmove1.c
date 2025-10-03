#include <stdio.h>
#include <string.h>


void main () 
{
    char str[] = "memmove can be very useful......";
    puts(str);
	memmove(str + 20, str + 15, 11);
    puts(str);
}


