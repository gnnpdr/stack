#include <stdio.h>

#include "stack_actions.h"

int push(Stack* stk)
{
    ASSERT(stk ON_DEBUG(, __FILE__, __func__, __LINE__));

    change_capacity(stk);

    stk->size = stk->size + 1;
    stack_element_t input = 0;
    scanf("%lf", &input);

    *(stk->data + stk->size) = input;

    ASSERT(stk ON_DEBUG(, __FILE__, __func__, __LINE__));
}

int pop(Stack* stk, stack_element_t* output)
{
    ASSERT(stk ON_DEBUG(, __FILE__, __func__, __LINE__));

    change_capacity(stk);

    *output = *(stk->data + stk->size);
    *(stk->data + stk->size) = 0;
    stk->size = stk->size - 1;

    ASSERT(stk ON_DEBUG(, __FILE__, __func__, __LINE__));
    //return errors(stk);
}