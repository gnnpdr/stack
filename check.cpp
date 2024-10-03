#include <stdio.h>

#include "check.h"

void dump(Stack* stk ADV_POS)
{
    stack_element_t* start_ptr = stk->data;
    size_t size = stk->size;
    size_t capacity = stk->capacity;

    printf("Stack [%x]\n", (size_t)stk);  //???

    printf("called from %s: %d (%s)\n", file, code_str, func);
    printf("name stk born at %s: %d (%s)\n", stk->origin_file, stk->origin_str, stk->origin_func);

    printf("{\nleft canary = %x\n", (size_t)start_ptr[0]);
    printf("{\nright canary = %x\n", (size_t)start_ptr[capacity + ADD_IN]);

    printf("array data address %p\n", start_ptr);
    printf("capacity = %d\n", capacity);
    printf("size = %d\n", size);
    printf("array data [%x]\n{\n", (size_t)start_ptr);
    for (size_t i = 0; i < capacity; i++)
    {
        if(i < size)
            printf(" * ");
        else
            printf("  ");
        printf("[%d] = %lf\n", i, start_ptr[i]);
    }
    printf(" }\n}");
}

StkErrors check(Stack* stk)  //ассерты только здесь, эта функция тормозит все ошибки и все ок
{
    assert(stk != nullptr);
    assert(stk->data != nullptr);

    size_t size = stk->size;
    stack_element_t* start_ptr = stk->data;

    if (stk == nullptr)
    {
        printf("no place for arrays\n");
        return NO_PLACE;
    }

    if (stk->size > stk->capacity)
    {
        printf("program crossed the line\n");
        return OVERFLOW_;
    }
        
    for (size_t i = 0; i < size; i++)
    {
        if (start_ptr[i] == POISON)
        {
            printf("elements were not add\n");  //может возникнуть проблема при смене размера (уменьшение)?
            return VALUE_PROBLEM;
        }
    }

    if (stk->hash != stk_hash(stk))
    {
        printf("strange rearrangement in the array, hash is incorrect\n");
        return HASH_PROBLEM;
    }

    return ALL_RIGHT;
}
/*
void stack_assert_func(Stack* stk ADV_POS)
{
    if (check(stk) != ALL_RIGHT)
        dump(stk, file, func, code_str);
}
*/
unsigned long long stk_hash(Stack* stk)   //вызвать в stack_actions,добавить проверку в errors
{
    unsigned long long hash = START_HASH;
    stack_element_t* start_ptr = stk->data;
    size_t size = stk->size;
    int elem_num = 0;

    while (elem_num < size)
    {
        hash = hash * 33  + start_ptr[elem_num  + ADD_IN];
        elem_num++;
    }
        
    return hash;
}
