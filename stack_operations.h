#ifndef _PUSH_H_
#define _PUSH_H_

#include "stack.h"

StkErrors push(Stack* stk, stack_element_t element, StkErrors* err);

StkErrors pop(Stack* stk, StkErrors* err);
StkErrors change_capacity(Stack* stk, size_t new_capacity, size_t capacity, StkErrors* err);

#endif //_PUSH_H_