#include "solveFile.h"


void solveFile(char* argv[]) {
    FILE *file = fopen(*argv, "r");

    Coefficients Coefs = {0, 0, 0};
    Roots Roots = {0, 0};

    fscanf(file, "%lg %lg %lg", &Coefs.a, &Coefs.b, &Coefs.c); // Получение коэффициентов из файла

    int num_of_roots = roots(&Coefs, &Roots); // Поиск корней
    prnt_roots(&num_of_roots, &Roots); // Вывод корней
}