// #include <TXLib.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <unistd.h>

#include "solve.h"
#include "unit_test.h"
#include "clear.h"
#include "solveCom.h"
#include "solveFile.h"


int main(int argc, char *argv[])
{
    printf(CYAN "Solving square equations!!!\n\n" RESET);

    int comm = 0;
    int opt = 0;
    // FILE *output = stdout;

    while ((opt = getopt(argc, argv, "stf")) != -1) {
        switch (opt) {

            case 't':
                TestsolveSquare();
                break;

            case 's':
                solveCom(argv + optind);
                optind += 3;
                break;

            case 'f':
                solveFile(argv + optind);
                optind += 1;
                break;

            default:
                return 1;
        }
    }

    printf("\n\nNew equation: " BLUE "Enter\n" RESET);
    printf("To the end: " BLUE "e" RESET "\n\n");

    comm = clear_input_buffer();

    while (comm != 'e'){ // Решает уравнения, пока не EOF

        if (comm == 't') {
            TestsolveSquare();

        } else {
            solveSquare();   // Решение квадратного уравнения
        // printf("Enter to continue");
        }

        printf("\n\nNew equation: " BLUE "Enter\n" RESET);
        printf("To the end: " BLUE "e" RESET "\n\n");

        comm = clear_input_buffer();   // Получает предпоследнее значение (до Enter)

    }
}
