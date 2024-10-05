#include <stdio.h>

#include "check.h"
#include "stack.h"
#include "user.h"
#include "stack_operations.h"

int main()
{
    Stack stk = {};

    #ifdef DEBUG
    stk.left_canary = left_canary_value;
    stk.right_canary = right_canary_value;
    stk.hash = start_hash;
    #endif

    CHECK_FUNC(CTOR(&stk))

    CHECK_FUNC(enter_element(&stk))

    CHECK_FUNC(del_element(&stk))
    dump(&stk POSITION);

    dtor(&stk);

    return 0;
}