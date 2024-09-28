#include <stdio.h>

#include "ctor.h"

void ctor(Stack* stk)
{
    assert(stk != nullptr);
    
    stk->size = 0;
    stk->capacity = AMOUNT;
    stk->data = (stack_element_t*)calloc(stk->capacity, sizeof(stack_element_t));  //надо понять, как бы поудобнее разместить функции изменения размера, чтобы они выполнялись самостоятельно на определенном элементе

    stack_assert_func(stk);
}

void change_capacity(Stack* stk)
{
    assert(stk != nullptr);

    if (stk->size = stk->capacity)
        more_size(stk);

    if (stk->size = stk->capacity/4)
        less_size(stk);
}

void more_size(Stack* stk)
{
    assert(stk != nullptr);

    stk->capacity = stk->capacity * DELTA;
    cool_realloc(stk);
}


void less_size(stk != nullptr)
{
    assert();

    stk->capacity = stk->capacity / DELTA;
    stk->data = (stack_element_t*)realloc(stk->capacity, sizeof(stack_element_t));
}

void cool_realloc(Stack* stk)
{
    assert(stk != nullptr);

    stk->data = (stack_element_t*)realloc(stk->capacity, sizeof(stack_element_t));
    while (int i = stk->capacity/2; i <= stk->capacity; i++)
        *(stk->data + i) = 0; 

}

void dtor(Stack* stk)
{
    assert(stk != nullptr);

    free(stk->data);
}