#include <stdio.h>

#include "check.h"
#include "ctor.h"
#include "stack_actions.h"

#define CHECK_ if (!err) err =

int main()
{
    Stack stk = {};
    
    ctor(&stk);
    
    bool err = 0;

    stack_element_t element = 0;

    CHECK_ push(&stk);
    CHECK_ push(&stk);

    CHECK_ pop(&stk, &element);
    CHECK_ pop(&stk, &element);

    dtor(&stk);

    return 0;
}