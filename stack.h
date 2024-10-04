#ifndef _CTOR_H_
#define _CTOR_H_

#include <stdlib.h>
#include <string.h>
#include "check.h"

#define AMOUNT 6
#define DELTA 2

#define CTOR(stk) ctor(stk POSITION)

StkErrors ctor(Stack* stk ADV_POS);

void dtor(Stack* stk);

#endif //_CTOR_H_