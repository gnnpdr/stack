#include <stdio.h>

#include "check.h"
#include "stack.h"
#include "stack_operations.h"

int main()
{
    Stack stk = {};

    #ifdef DEBUG
    stk.left_canary = LEFT_CANARY;
    stk.right_canary = RIGHT_CANARY;
    stk.hash = START_HASH;
    #endif

    CHECK_FUNC(CTOR(&stk))

    CHECK_FUNC(enter_element(&stk))

    CHECK_FUNC(del_element(&stk))

    dtor(&stk);

    return 0;
}