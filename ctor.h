#ifndef _CTOR_H_
#define _CTOR_H_

#include <stdlib.h>
#include "check.h"

struct Stack
{
    stack_element_t* data; //
    size_t size;
    size_t capacity;
};

typedef double stack_element_t;
#define AMOUNT 5
#define DELTA 2

void ctor(Stack* stk, size_t );

void more_size(Stack* stk);
void less_size(Stack* stk);

void dtor(Stack* stk);

#endif //_CTOR_H_