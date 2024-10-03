#ifndef _CTOR_H_
#define _CTOR_H_

#include <stdlib.h>
#include <string.h>
#include "check.h"

#define AMOUNT 5
#define DELTA 2
#define POISON 13

#define CTOR(stk) ctor(stk POSITION)

void ctor(Stack* stk ADV_POS);

void change_capacity(Stack* stk);
void more_capacity(Stack* stk);
void less_capacity(Stack* stk);

void cool_realloc(Stack* stk);

void dtor(Stack* stk);

#endif //_CTOR_H_