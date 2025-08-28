#include "output.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

//Escape последовательности, цветной.

void prnt_roots(int* num_of_roots, Roots* Roots) // Вывод корней

// Передавать через структуры
{
    double* x1 = &Roots->x1;
    double* x2 = &Roots->x2;
    
    switch (*num_of_roots){
        case ZERO_ROOTS:
            printf("No roots of the equation\n");
            break;

        case ONE_ROOT:
            printf("x = %lg\n", *x1);
            break;

        case TWO_ROOTS:
            printf("x1 = %lg x2 = %lg\n", *x1, *x2);
            break;

        case ERR:
            printf("All roots satisfy the equation\n");
            break;
    }
}