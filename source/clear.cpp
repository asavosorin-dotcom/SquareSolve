#include "clear.h"
#include <stdio.h>

#define BUFSIZE 1000000

int bufp = 0; // Последняя пустая ячейка в буфере

int buffer[BUFSIZE];

int clear_input_buffer(void)
{
    int c = 0, d = 0; 

    while ((c = getchar()) != '\n' && c != EOF ) {
        d = c;
    }   
    return d;

}

int getch(void) {
    return (bufp > 0) ? buffer[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ERROR: Buffer is full");

    else {
        buffer[bufp++] = c;
    }
}