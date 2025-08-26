#ifndef STRUCT_H
#define STRUCT_H

//! Структура, в которой будут храниться коэффициенты a, b, c типа double

typedef struct {
        double a;
        double b;
        double c;
    } Coefficients;

//! Структура для хранения корней x1, x2 типа double

typedef struct { 
    double x1;
    double x2;
} Roots;

#endif 