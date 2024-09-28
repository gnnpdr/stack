#include <stdio.h>

#include "check.h"

void dump(Stack* stk)
{
    assert(stk != nullptr);

    printf("array data address %p\n", stk->data);

    printf("capacity %d\n", stk->capacity);

    for (int i = 0; i < stk->size; i++)
    {
        printf("element №%d value %lf\n", i, stk->data[i]);
        printf("element №%d address %p\n", i, stk->data + i);
    }
}

int errors(Stack* stk)
{
    assert(stk != nullptr);

    if (stk->capacity <= 0)
        return NO_PLACE;

    if (stk->size > stk->capacity)
        return ARRAY_LIMIT_PROBLEM;

    for (int i = 0; i < stk->size; i++)
    {
        if (*(stk->data + i) == 0)  //проверка, конечно, не очень, ведь мы ограничиваем диапазон возможных значений. Можно ли заполнить все нанами или типа того?
            return FILLING_PROBLEM;
    }
}

void stack_assert_func(Stack* stk) // про местоположение в коде не поняла, как рассмотреть весь код как файл через аргументы?
{
    assert(stk != nullptr);

    if (errors(stk) != ALL_RIGHT)
    {
        dump(stk);
        assert(0);                  //я прописала конкретные проблемы в enum, как это можно использовать? как код ошибки?
    }
}