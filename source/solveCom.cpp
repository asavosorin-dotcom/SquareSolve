#include "solveCom.h"
#include "solve.h"
#include "output.h"

void solveCom(char* argv[]) {
    Coefficients Coef = {atof(*(argv++)), atof(*(argv++)), atof(*(argv++))};
    Roots Roots = {0, 0};

    int num_of_roots = roots(&Coef, &Roots);
    prnt_roots(&num_of_roots, &Roots); // Вывод корней

}