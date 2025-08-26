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

    // Tests testTab[] = {
    //  a   b   c   x1  x2  roots ТАБЛИЧКА!!!
        // 1, -5,  6,  2,  3,  2,    // Два корня
        // 0,  0,  0,  0,  0, -1,    // Удовлетворяют все корни
        // 1, -2,  1,  1,  1,  1,    // Один корень
        // 1,  2,  3,  0,  0,  0     // Нет корней
    // };
//argc argv командная строка !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    Tests testTab[4] = {0};
    int i = 0;

    FILE *tests = fopen ("123.txt", "r");
    assert (tests);

    while (readTest(tests, &testTab[i].TestCoef, &testTab[i].TestRoots, &testTab[i].NumRoots)) { // Заносит данные из файла в testTab
        i++;
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

    if (numVar == 6)
    {
        return 1;
    }

    return 0;
}