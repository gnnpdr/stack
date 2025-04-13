#include <stdio.h>

#include "../include/user.h"

void enter_elements(Stack *const stk, ErrList *const list)
{
    STK_ASSERT
    check(stk, list);
    ERR_RET_VOID

    printf("what element do you want to add?\n");
    stack_element_t element = 0;
    scanf("%lf", &element);

    size_t amt = 0;
    printf("how many times?\n");
    scanf("%ld", &amt);

    printf("hello %d\n", stk->size);

    if (stk->data[stk->size] != POISON)
        stk->size++;

    for (size_t i = 0; i < amt; i++)
    {
        stk_push(stk, element, list);
        ERR_RET_VOID
    }
}

void del_elements(Stack* stk, ErrList *const list)
{
    STK_ASSERT
    check(stk, list);
    ERR_RET_VOID

    size_t amt = 0;
    printf("how many elements do you want to del?\n");
    scanf("%ld", &amt);

    if (stk->data[stk->size] == POISON && stk->size)
        stk->size--;

    double element = 0;
    for (size_t i = 0; i < amt; i++)
    {
        stk_pop(stk, &element, list);
        ERR_RET_VOID
    }

    stk->size++;
}