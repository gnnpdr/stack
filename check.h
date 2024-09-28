#ifndef _CHECK_H_
#define _CHECK_H_

enum Problem
{
    ALL_RIGHT;
    NO_PLACE;
    ARRAY_LIMIT_PROBLEM;
    FILLING_PROBLEM;
}

void dump(Stack* stk);
int errors(Stack* stk);

void stack_assert_func(Stack* stk);

#endif //_CHECK_H_