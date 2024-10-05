#include <stdio.h>

#include "user.h"

StkErrors enter_element(Stack* stk)
{
    ASSERT_STK(stk)

    printf("what do you want to add?\n");
    stack_element_t element = 0;
    scanf("%lg", &element);

    size_t amount = 0;
    printf("how many times?\n");
    scanf("%d", &amount);

    for (size_t i = 0; i < amount; i++)
        CHECK_FUNC(push(stk, element))

    ASSERT_STK(stk)
    return ALL_RIGHT;
}

StkErrors del_element(Stack* stk)
{
    ASSERT_STK(stk)

    size_t amount = 0;
    printf("how many elements do you want to del?\n");
    scanf("%d", &amount);

    for (size_t i = 0; i < amount; i++)
        CHECK_FUNC(pop(stk))

    ASSERT_STK(stk)
    return ALL_RIGHT;
}