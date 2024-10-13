#include <stdio.h>

#include "user.h"

StkErrors enter_element(Stack* stk, StkErrors* err)
{
    CHECK_STK(stk, err)

    printf("what do you want to add?\n");
    stack_element_t element = 0;
    scanf("%lf", &element);

    size_t amount = 0;
    printf("how many times?\n");
    scanf("%d", &amount);

    if (stk->data[stk->size] != poison)
        stk->size++;

    for (size_t i = 0; i < amount; i++)
    {
        push(stk, element, err);
        RETURN(*err)
    }
        
    CHECK_STK(stk, err)
    return ALL_RIGHT;
}

StkErrors del_element(Stack* stk, StkErrors* err)
{
    CHECK_STK(stk, err)

    size_t amount = 0;
    printf("how many elements do you want to del?\n");
    scanf("%d", &amount);

    if (stk->data[stk->size] == poison && stk->size != 0)
        stk->size--;

    for (size_t i = 0; i < amount; i++)
    {
        pop(stk, err);
        RETURN(*err)
    }

    stk->size++;
        
    CHECK_STK(stk, err)
    return ALL_RIGHT;
}