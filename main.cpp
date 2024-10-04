#include <stdio.h>

#include "check.h"
#include "stack.h"
#include "stack_operations.h"

int main()
{
    Stack stk = {};

    #ifdef DEBUG
    int check_res = ALL_RIGHT;
    stk.left_canary = LEFT_CANARY;
    stk.right_canary = RIGHT_CANARY;
    stk.hash = START_HASH;
    #endif

    RESULT CTOR(&stk);     //надо так сделать, чтобы чек получал строчку, а дамп выводил ее
    dump(&stk POSITION);

    RESULT enter_element(&stk);
    dump(&stk POSITION);

    RESULT del_element(&stk);
    dump(&stk POSITION);

    dtor(&stk);

    ASSERT;
    return 0;
}