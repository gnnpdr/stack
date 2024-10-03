#include <stdio.h>

#include "check.h"

#ifdef DEBUG

void dump(Stack* stk , const char* file, const char* func, const int code_str)
{   //вставить сюда кучу assertов, чтобы эта штука никогда не падала

    printf("Stack [%x]\n", (size_t)stk);

    
    printf("name stk born at %s: %d (%s)\n", stk->origin_file, stk->origin_str, stk->origin_func);

    printf("{\nleft canary = %x\n", (size_t)stk->data[0]);
    printf("{\nright canary = %x\n", (size_t)stk->data[stk->capacity + 1]);

    printf("array data address %p\n", stk->data);
    printf("capacity = %d\n", stk->capacity);
    printf("size = %d\n", stk->size);
    printf("array data [%x]\n   {\n ", (size_t)stk->data);
    for (size_t i = 0; i < stk->capacity; i++)
    {
        if(i < stk->size)
            printf("        * ");
        else
            printf("          ");
        printf("        [%d] = %lf\n", i, stk->data[i]);
    }
    printf("    }\n}");
}

int check(Stack* stk)  //ассерты только здесь, эта функция тормозит все ошибки и все ок
{
    assert(stk != nullptr);
    assert(stk->data != nullptr);

    if (stk == nullptr)
        return NOT_PTR;

    if (stk->capacity <= 0)
        return NO_PLACE;

    if (stk->size > stk->capacity)
        return OVERFLOW;

    for (size_t i = 0; i < stk->size; i++)
    {
        if (*(stk->data + i) == POISON)
            return VALUE_PROBLEM;
    }

    if (stk->hash != stk_hash(stk))
        return HASH_PROBLEM;
}

void stack_assert_func(Stack* stk ADV_POS)
{
    if (check(stk) != ALL_RIGHT)
        dump(stk, file, func, code_str);
}

unsigned long long stk_hash(Stack* stk)   //вызвать в stack_actions,добавить проверку в errors
{
    unsigned long long hash = 0;
    int elem_num = 0;
    while (elem_num < stk->size)
    {
        hash = hash * 33  + *(stk->data + elem_num); //переделать с учетом того, что что тут исключающее или
        elem_num++;
    }
        
    return hash;
}


called()
{
    printf("called from %s: %d (%s)\n", file, code_str, func);
}
#endif