#include <stdio.h>

#include "push.h"

int push(Stack* stk)
{
    assert(stk != nullptr);

    stk->size = stk->size + 1;

    stack_element_t input = 0;
    scanf("%lf", &input);

    *(stk->data + stk->size) = input;

    return errors(stk);
}

int pop(Stack* stk, stack_element_t* output)
{
    assert(stk != nullptr);

    *(output) = *(stk->data + stk->size);
    *(stk->data + stk->size) = 0;
    stk->size = stk->size - 1;

    return errors(stk);
}