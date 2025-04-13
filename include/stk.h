#ifndef _STK_H_
#define _STK_H_

#include "check.h"


static const size_t DELTA          = 2;
static const size_t DOUBLE_DELTA   = 4;
static const size_t START_STK_SIZE = 4;

static const size_t MIN_STK_SIZE = 3;

#define STK_ASSERT  do                  \
                    {                   \
                        assert(stk);    \
                        assert(list);   \
                    } while(0);


void stk_ctor(Stack *const stk, ErrList *const list);
void stk_dtor(Stack *const stk);

void stk_push(Stack *const stk, stack_element_t element, ErrList *const list);
void stk_pop(Stack *const stk, stack_element_t* elem, ErrList *const list);


#endif //_STK_H_