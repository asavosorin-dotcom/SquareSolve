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

//getopts
//make
//WSL
//g++, warnings

int main(int argc, char *argv[])
{
    printf(RED "Solving square equations!!!\n\n" RESET);
    //printf("dsovjodpjgqe[ig]\n");

    int comm = 0;

    int opt = 0;
    
    if (argc == 4){

        solveCom(argv); // Функция, которая запускает квадратку с аргументами из командной строки

    // } else {
        // printf("Invalif numbers of arguments\n");

        // printf("\n\n");
    }

    while ((opt = getopt(argc, argv, "st")) != -1) {
        switch (opt) {

            case 't':
            TestsolveSquare();
                break;

        }

    }
    
    printf("\n\nNew equation: " BLUE "Enter\n" RESET);
    printf("To the end: " BLUE "e" RESET "\n\n");

    comm = clear_input_buffer();

     

    //atoi

    //error, choose option

    while (comm != 'e'){ // Решает уравнения, пока не EOF
        
        if (comm == 't') {
            TestsolveSquare();

        } else {
            solveSquare();   // Решение квадратного уравнения
        // printf("Enter to continue");
        }

        printf("\n\nNew equation: " BLUE "Enter\n" RESET);
        printf("To the end: " BLUE "e" RESET "\n\n");

        comm = clear_input_buffer();   // Получает предпоследнее значение (последнее до Enter)

    }
}