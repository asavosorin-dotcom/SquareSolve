#include "unit_test.h"
#include "solve.h"
#include "const.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

void TestsolveSquare(void) // Команда выполняющая тесты
{
    typedef struct {
        Coefficients TestCoef;
        Roots TestRoots;
        int NumRoots;
    } Tests; // Структура для прогона тестов c кэфами, корнями и числом корней


    Tests testTab[4] = {0}; // get_test_amount
    int i = 0;

    FILE *tests = fopen ("tests.txt", "r");
    assert (tests);

// Лучше for

    // while (readTest(tests, &testTab[i].TestCoef, &testTab[i].TestRoots, &testTab[i].NumRoots)) { // Заносит данные из файла в testTab
    //     i++;
    // }

    for (; i < 4; i++) {
        readTest(tests, &testTab[i].TestCoef, &testTab[i].TestRoots, &testTab[i].NumRoots);
    }

    fclose(tests);

    int size = sizeof(testTab) / sizeof(testTab[0]);

    for (int i = 0; i < size; i++)
    {
        Coefficients TestCoef = testTab[i].TestCoef;
        Roots TestRoots = testTab[i].TestRoots;
        int NumRoots = testTab[i].NumRoots;
        test(TestCoef, TestRoots, NumRoots);
    }
}

void test(Coefficients TestCoef, Roots ExpectRoots, int ExpectNumRoots) // Тестирует прогу
{
    Roots TestRoots = {0, 0};
    int nRoots = roots(&TestCoef, &TestRoots); // Тут должна быть структура, в которой будут лежать кэфы и корни
    
    if (!(TestRoots.x1 == ExpectRoots.x1 && TestRoots.x2 == ExpectRoots.x2))
        printf(RED "FAILED: roots(%lg, %lg, %lg), x1 = %lg, x2 = %lg (should be x1 = %lg, x2 = %lg)" RESET "\n", TestCoef.a, TestCoef.b, TestCoef.c, TestRoots.x1, TestRoots.x2, ExpectRoots.x1, ExpectRoots.x2);
    
    else if (!(nRoots == ExpectNumRoots))
        printf(RED "FAILED: roots(%lg, %lg, %lg) number of roots = %d (should be %d)" RESET "\n", TestCoef.a, TestCoef.b, TestCoef.c, nRoots, ExpectNumRoots);
    
    else printf(GREEN "OK" RESET "\n");
}

int readTest(FILE *tests, Coefficients* TestCoef, Roots* TestRoots, int* NumRoots)
{
    int numVar = fscanf(tests, "%lg  %lg  %lg  %lg  %lg  %d", &TestCoef->a, &TestCoef->b, &TestCoef->c, &TestRoots->x1, &TestRoots->x2, NumRoots);

    // if (numVar == 6)
    // {
    //     return 1;
    // }

    return 0;
}

// void get_test_amount(Tests* )
