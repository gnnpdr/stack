#include <stdio.h>

#include "check.h"
#include "stack.h"
#include "stack_operations.h"

int main()
{
    Stack stk = {};

    #ifdef DEBUG
    stk.left_canary = LEFT_CANARY;  //ограждение структуры
    stk.right_canary = RIGHT_CANARY;
    #endif

    CTOR(&stk);

    enter_element(&stk);
    enter_element(&stk);

    del_element(&stk, &element);
    del_element(&stk, &element);

    dtor(&stk);

    return 0;
}