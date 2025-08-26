//#include <TXLib.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "solve.h"
#include "unit_test.h"
#include "clear.h"
#include "solveCom.h"

//getopts

int main(int argc, char *argv[])
{
    printf(CYAN "Solving square equations!!!\n\n" RESET);

    if (argc != 4){
        printf("Invalif numbers of arguments\n");
    } else {
        solveCom(argv);// Функция, которая запускает квадратку с аргументами из командной строки

        printf("\n\n");
    }
     

    //atoi

    //error, choose option

    int comm = 0;
    while (comm != 'e'){ // Решает уравнения, пока не EOF
        solveSquare();   // Решение квадратного уравнения
        // printf("Enter to continue");

        printf("\n\n");
        
        printf("New equation: Enter\n");
        printf("To the end: " BLUE "e" RESET "\n\n");

        comm = clear_input_buffer();   // Получает предпоследне.е значение (последнее до Enter)
        
        printf("\n");
        
        if (comm == 't') {
            TestsolveSquare();
            printf("\n\n");
        
            printf("New equation: Enter\n");
            printf("To the end: " BLUE "e" RESET "\n");
        
            printf("\n");

            comm = clear_input_buffer();
        }
    }
}