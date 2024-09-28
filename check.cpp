#include <stdio.h>

#include "check.h"

void dump(Stack* stk);
{
    printf("array data address %p\n", stk->data);

    printf("capacity %d\n", stk->capacity)

    for (int i = 0; i < stk->size; i++)
    {
        printf("element №%d value %lf\n", i, stk->data[i]);
        printf("element №%d address %p\n", i, stk->data + i);
    }
}

int errors(Stack* stk)
{
    if (capacity <= 0)
        return NO_PLACE;

    if (size > capacity)
        return ARRAY_LIMIT_PROBLEM;

    for (int i = 0; i < stk->size; i++)
    {
        if (stk->data + i == 0)
            return FILLING_PROBLEM;
    }
}

void stack_assert_func(Stack* stk) // про местоположение в коде не поняла, как рассмотреть весь код как файл через аргументы?
{
    if (errors(stk) != ALL_RIGHT)
    {
        dump(&stk);
        assert(0);                  //я прописала конкретные проблемы в enum, как это можно использовать? как код ошибки?
    }
}