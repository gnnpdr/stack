#include <stdio.h>

#include "check.h"

#ifdef DEBUG

void dump(Stack* stk ON_DEBUG(, const char* file, const char* func, const int code_str))
{   //вставить сюда кучу assertов, чтобы эта штука никогда не падала
    //assert(stk != nullptr);

    printf("Stack [stk]\n");

    printf("called from %s: %d (%s)\n", file, code_str, func);
    printf("name %s born at %s: %d (%s)\n", stk->origin_file, stk->origin_str, stk->origin_func);

    //printf("{\nleft canary  = %x\n", );  //дописать значение hexspeak

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
    assert(stk->data != nullptr);

    if (stk == nullptr)
        return NOT_PTR;

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

void stack_assert_func(Stack* stk ON_DEBUG(, const char* file, const char* func, const int code_str)) // хочется, чтобы именно эта функция принимала текущее занчение файла и тд
{
    if (errors(stk) != ALL_RIGHT)
        dump(stk, file, func, code_str);
}

#endif