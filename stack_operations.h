#ifndef _PUSH_H_
#define _PUSH_H_

#include "stack.h"

//static const int delta = 2;
//static const int double_delta = 4;

StkErrors enter_element(Stack* stk);
StkErrors push(Stack* stk, stack_element_t element);
StkErrors del_element(Stack* stk);
StkErrors pop(Stack* stk);
StkErrors change_capacity(Stack* stk, size_t new_capacity, size_t capacity);

#endif //_PUSH_H_