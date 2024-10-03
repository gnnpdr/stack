#ifndef _PUSH_H_
#define _PUSH_H_

#include "stack.h"

StkErrors enter_element(Stack* stk);
StkErrors check_capacity(Stack* stk);
StkErrors check_hash(Stack* stk);
StkErrors push(Stack* stk, stack_element_t element);
StkErrors del_element(Stack* stk);
StkErrors pop(Stack* stk);

#endif //_PUSH_H_