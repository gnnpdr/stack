#ifndef _CTOR_H_
#define _CTOR_H_

#include <stdlib.h>
#include <string.h>
#include "check.h"

#define AMOUNT 5
#define DELTA 2

#define CTOR(stk, ...) ctor(stk __VA_ARGS__); //работает?

void ctor(Stack* stk ON_DEBUG(, const char* file, const int line, const char* func));

void change_capacity(Stack* stk);
void more_capacity(Stack* stk);
void less_capacity(Stack* stk);

void cool_realloc(Stack* stk);

void dtor(Stack* stk);

#endif //_CTOR_H_