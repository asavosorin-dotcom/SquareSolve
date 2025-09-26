#include "unit_test.h"
#include "solve.h"
#include "const.h"
#include "count_str.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>



void TestsolveSquare(void) // Команда выполняющая тесты
{
    typedef struct {
        Coefficients TestCoef;
        Root TestRoots;
        int NumRoots;
    } Tests; // Структура для прогона тестов c кэфами, корнями и числом корней
    
    FILE *tests = fopen ("tests.txt", "r");
    assert (tests);

    size_t size = count_str(tests); // Количесвто строк

    Tests* testTab = (Tests* )calloc(size, sizeof(Tests));
    // Tests testTab[4] = {0}; // get_test_amount

    fseek(tests, 0, SEEK_SET);
    
    for (int i = 0; i < (int) size; i++) {
        Coefficients* TestCoef = &testTab[i].TestCoef;
        Root* TestRoots = &testTab[i].TestRoots;
        int *NumRoots = &testTab[i].NumRoots;
        
        fscanf(tests, "%lg  %lg  %lg  %lg  %lg  %d", &TestCoef -> a, &TestCoef -> b, &TestCoef->c, &TestRoots->x1, &TestRoots->x2, NumRoots);
    }

    fclose(tests);

    for (int i = 0; i < (int) size; i++)
    {
        Coefficients TestCoef = testTab[i].TestCoef;
        Root TestRoots = testTab[i].TestRoots;
        int NumRoots = testTab[i].NumRoots;
        test(TestCoef, TestRoots, NumRoots);
    }

    printf("\n\n");

    free(testTab);
}

void test(Coefficients TestCoef, Root ExpectRoots, int ExpectNumRoots) // Тестирует прогу
{
    Root TestRoots = {0, 0};
    int nRoots = roots(&TestCoef, &TestRoots); // Тут должна быть структура, в которой будут лежать кэфы и корни
    
    if (!(comparison(TestRoots.x1, ExpectRoots.x1) == 0) && comparison(TestRoots.x2, ExpectRoots.x2) == 0)
        printf(RED "FAILED: roots(%lg, %lg, %lg), x1 = %lg, x2 = %lg (should be x1 = %lg, x2 = %lg)" RESET "\n", TestCoef.a, TestCoef.b, TestCoef.c, TestRoots.x1, TestRoots.x2, ExpectRoots.x1, ExpectRoots.x2);
    
    else if (!(nRoots == ExpectNumRoots))
        printf(RED "FAILED: roots(%lg, %lg, %lg) number of roots = %d (should be %d)" RESET "\n", TestCoef.a, TestCoef.b, TestCoef.c, nRoots, ExpectNumRoots);
    
    else printf(GREEN "OK" RESET "\n");
}

// void get_test_amount(Tests* )
