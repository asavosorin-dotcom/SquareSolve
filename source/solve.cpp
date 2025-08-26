#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "solve.h"
#include "input.h"
#include "output.h"

int solveSquare(void){
    Coefficients Coef = {0, 0, 0};
    Roots Roots = {0, 0};
    //Структура, делаешь структуру квадратного уравнения

    printf("Enter the equation in the format: ax^2 + bx + c = 0\n");

    if (!input_coef(&Coef)){ // Считывание данных
        return 0; // Прерывает решение уравнения при неправильном вводе
    }

    int num_of_roots = roots(&Coef, &Roots);
    prnt_roots(&num_of_roots, &Roots.x1, &Roots.x2); // Вывод корней

    return 1;
}

int comparison(double num1, double num2) // 1 - если num1 > num2
{
    double difference = num1 - num2;

    if (difference > ERRATE)
        return 1;

    else if (difference <= ERRATE && difference > -1 * ERRATE)
        return 0;

    else
        return -1;
}

int roots(Coefficients *Coef, Roots *Roots) // Решает квадратное уравнение
{

    double a = Coef -> a;
    double b = Coef -> b;
    double c = Coef -> c;
    double *x1 = &Roots -> x1;
    double *x2 = &Roots -> x2;

    if (comparison(a, 0) == 0){ // a == 0
        if (comparison(b, 0) == 0) // b == 0
            return (comparison(c, 0) == 0) ? ERR : ZERO_ROOTS;
        else {
            *x1 = *x2 = -c / b;
            return ONE_ROOT;
        }
    } else { // уравнение квадратное c = 0 !!!!!!!
        
        if (c == 0){
            *x1 = 0;
            *x2 = solveLine(a, b);

            minax(x1, x2);
            
            return TWO_ROOTS;
        }

        double disc = b * b - 4 * a * c;

        if (comparison(disc, 0) == 0){ //D = 0 в пределах погрешности
            *x1 = *x2 = -b / (2 *a);
            return ONE_ROOT;

        } else if (disc < -1 * ERRATE){
            return ZERO_ROOTS;

        } else {
            double sqrt_d = sqrt(disc);
            *x1 = (-b + sqrt_d) / (2 * a);
            *x2 = (-b - sqrt_d) / (2 * a);
        
            minax(x1, x2);
        
            return TWO_ROOTS;
        }
    }
}

void minax(double* x1, double* x2) //!< Расставляет корни по возрастранию
{
    double minnum = min(*x1, *x2);
    double maxnum = max(*x1, *x2);
    *x1 = minnum;
    *x2 = maxnum;
}

double min(double a, double b) //!< Минимальное из двух чисел
{
    return (comparison(a, b) == -1) ? a : b;
}

double max(double a, double b) //!< Максимальное из двух чисел
{
    return (comparison(a, b) == 1) ? a : b;
}

double solveLine(double a, double b) //!< Решение линейного уравнения вида ax + b
{
    assert(a != 0);
    return -b / a;
}
