#ifndef _CTOR_H_
#define _CTOR_H_

#include <stdlib.h>
#include "check.h"

#define AMOUNT 5
#define DELTA 2
//#define STACK_CTOR(stk)\
ctor()

void ctor(Stack* stk);

void change_capacity(Stack* stk);
void more_capacity(Stack* stk);
void less_capacity(Stack* stk);

void cool_realloc(Stack* stk);

void dtor(Stack* stk);

#endif //_CTOR_H_