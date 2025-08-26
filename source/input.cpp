#include "input.h"
#include "struct.h"
#include "const.h"
#include "clear.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

int input_coef(Coefficients *Coef) 
{
    double *a = &Coef -> a;
    double *b = &Coef -> b;
    double *c = &Coef -> c;

    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    assert(a != c);
    assert(b != c);
    assert(a != b);

    printf(BLUE "Enter a: " RESET);
    scan(a);

    printf(BLUE "Enter b: " RESET);
    scan(b);

    printf(BLUE "Enter c: " RESET);
    scan(c);

    return 1;
}

void scan(double* num) // Проверка записи формата и считывание числа
{
    while (scanf("%lg", num) == 0){
        
        printf("Format error, try again\n");
        clear_input_buffer();
    }
    clear_input_buffer();
}