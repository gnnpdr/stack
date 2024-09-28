#ifndef _CHECK_H_
#define _CHECK_H_

#include <assert.h>
#include <math.h>

enum Problem
{
    ALL_RIGHT,
    NO_PLACE,
    ARRAY_LIMIT_PROBLEM,
    FILLING_PROBLEM
};

typedef double stack_element_t;

struct Stack
{
    stack_element_t* data;
    size_t size;
    size_t capacity;
};

void dump(Stack* stk);
int errors(Stack* stk);

void stack_assert_func(Stack* stk);

#endif //_CHECK_H_