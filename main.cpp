//#include <TXLib.h>

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

int main(int argc, char *argv[])
{
    printf(CYAN "Solving square equations!!!\n\n" RESET);

    int opt = 0;

    while ((opt = getopt(argc, argv, "st")) != -1) {
        switch (opt) {
            
            case 't':
                testRun();
                break;

        }
    }
    

    if (argc != 4){
        printf("Invalif numbers of arguments\n");
    } else {
        solveCom(argv); // Функция, которая запускает квадратку с аргументами из командной строки

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
            testRun();

            comm = clear_input_buffer();
        }
    }
}