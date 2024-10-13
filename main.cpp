#include <stdio.h>

#include "check.h"
#include "stack.h"
#include "user.h"
#include "stack_operations.h"

int main()
{
    StkErrors err = ALL_RIGHT;

    Stack stk = {};

    #ifdef DEBUG
    stk.left_canary = left_canary_value;
    stk.right_canary = right_canary_value;
    stk.hash = start_hash;
    #endif

    ctor(&stk, __FILE__, __func__, __LINE__, &err);

    enter_element(&stk, &err);
    del_element(&stk, &err);
    enter_element(&stk, &err);
    del_element(&stk, &err);

    print_stk_elements(stk.data, stk.capacity, stk.size);

    dtor(&stk);

    return 0;
}