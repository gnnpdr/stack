#include <stdio.h>

#include "include/check.h"
#include "include/stk.h"
#include "include/user.h"

int main()
{
    ErrList list = {};
    error_list_ctor(&list);

    Stack stk = {};

    #ifdef DEBUG
    stk.left_canary = L_CAN_VAL;
    stk.right_canary = R_CAN_VAL;
    stk.hash = START_HASH;
    #endif

    stk_ctor(&stk, &list);
    FATAL_ERR

    enter_elements(&stk, &list);
    FATAL_ERR
    del_elements(&stk, &list);
    FATAL_ERR

    dump(&stk, LOCATION, &list);

    stk_dtor(&stk);
    error_list_dtor(&list);

    return 0;
}