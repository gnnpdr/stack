#include <stdio.h>

#include "check.h"

#ifdef DEBUG

void dump(Stack* stk ON_DEBUG(, const char* file, const char* func, const int code_str))
{   //вставить сюда кучу assertов, чтобы эта штука никогда не падала

    printf("Stack [%x]\n", stk);

    printf("called from %s: %d (%s)\n", file, code_str, func);
    printf("name stk born at %s: %d (%s)\n", stk->origin_file, stk->origin_str, stk->origin_func);

    printf("{\nleft canary = %x\n", stk->left_canary);
    printf("{\nright canary = %x\n", stk->right_canary);

    printf("array data address %p\n", stk->data);
    printf("capacity = %d\n", stk->capacity);
    printf("size = %d\n", stk->size);
    printf("array data [%x]\n   {\n ", stk->data);
    for (int i = 0; i < stk->capacity; i++)
    {
        if(i < stk->size)
            printf("        * ");
        else
            printf("          ");
        printf("        [%d] = %lf\n", i, stk->data[i]);
    }
    printf("    }\n}");
}

int errors(Stack* stk)  //я так поняла, что по идее ассерты только здесь, эта функция тормозит все ошибки и все ок
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

void hash(Stack* stk)   //где бы так ее вызвать? в stack_actions? надо выводить оба значения при всех операциях, добавить в errors
{
    unsigned long hash = stk->hash;
    stack_element_t elem = *(stk->data)
    while ((&elem)++) //проверить порядок функций
        hash = hash * 33  + elem;
    stk->hash = hash;  // надо сохранять и старое и новое, менять их
}

#endif