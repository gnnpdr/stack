#include <stdio.h>

#include "check.h"
#include "stack.h"
#include "user.h"
#include "stack_operations.h"

int main()
{
    StkErrors err = ALL_RIGHT;

    Stack stk = {};
    printf("canary add %d  left can %d\n", CANARY_CAPACITY_ADD, LEFT_CANARY_ADD);

    #ifdef DEBUG
    stk.left_canary = left_canary_value;
    stk.right_canary = right_canary_value;
    stk.hash = start_hash;
    #endif

    ctor(&stk, __FILE__, __func__, __LINE__, &err);
    //RETURN(err) 

    enter_element(&stk, &err);
    //RETURN(err)
    del_element(&stk, &err);
    //RETURN(err) 

    //dump(&stk POSITION);      //ifdef

    dtor(&stk);

    //print_stk_elements(stk.data, stk.capacity, stk.size);
    printf("%lg", stk.data[stk.size]);
    return 0;
}