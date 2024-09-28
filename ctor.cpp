#include <stdio.h>

#include "ctor.h"

void ctor(Stack* stk)
{
    assert(stk != nullptr);
    
    stk->size = 0;
    stk->capacity = AMOUNT;
    stk->data = (stack_element_t*)calloc(stk->capacity, sizeof(stack_element_t));

    stack_assert_func(stk);
}

void change_capacity(Stack* stk)
{
    assert(stk != nullptr);

    if (stk->size = stk->capacity)
        more_capacity(stk);

    if (stk->size = stk->capacity/4)
        less_capacity(stk);
}

void more_capacity(Stack* stk)
{
    assert(stk != nullptr);

    stk->capacity = stk->capacity * DELTA;
    cool_realloc(stk);
}


void less_capacity(Stack* stk)
{
    assert(stk != nullptr);

    stk->capacity = stk->capacity / DELTA;
    stk->data = (stack_element_t*)realloc(stk->data, stk->capacity*sizeof(stack_element_t));
}

void cool_realloc(Stack* stk)
{
    assert(stk != nullptr);

    stk->data = (stack_element_t*)realloc(stk->data, stk->capacity*sizeof(stack_element_t));

    for (int i = stk->capacity / DELTA; i <= stk->capacity; i++)
        *(stk->data + i) = 0; 
}

void dtor(Stack* stk)
{
    assert(stk != nullptr);

    free(stk->data);
}