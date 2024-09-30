#include <stdio.h>

#include "ctor.h"

void ctor(Stack* stk ON_DEBUG(, const char* file, const int line, const char* func))
{
    ASSERT(stk ON_DEBUG(, __FILE__, __func__, __LINE__));

    #ifdef DEBUG
    stk->origin_file = file;
    stk->origin_str = &line;
    stk->origin_func = func;
    #endif

    stk->size = 0;
    stk->capacity = AMOUNT;

    stk->data = (stack_element_t*)calloc(stk->capacity, sizeof(stack_element_t));

    ASSERT(stk ON_DEBUG(, __FILE__, __func__, __LINE__));
}

void change_capacity(Stack* stk)
{
    ASSERT(stk ON_DEBUG(, __FILE__, __func__, __LINE__));

    if (stk->size = stk->capacity)
        more_capacity(stk);

    if (stk->size = stk->capacity/4)
        less_capacity(stk);

    ASSERT(stk ON_DEBUG(, __FILE__, __func__, __LINE__));
}

void more_capacity(Stack* stk)
{
    ASSERT(stk ON_DEBUG(, __FILE__, __func__, __LINE__));

    stk->capacity = stk->capacity * DELTA;
    cool_realloc(stk);

    ASSERT(stk ON_DEBUG(, __FILE__, __func__, __LINE__));
}


void less_capacity(Stack* stk)
{
    ASSERT(stk ON_DEBUG(, __FILE__, __func__, __LINE__));

    stk->capacity = stk->capacity / DELTA;
    stk->data = (stack_element_t*)realloc(stk->data, stk->capacity*sizeof(stack_element_t));

    ASSERT(stk ON_DEBUG(, __FILE__, __func__, __LINE__));
}

void cool_realloc(Stack* stk)
{
    ASSERT(stk ON_DEBUG(, __FILE__, __func__, __LINE__));

    stk->data = (stack_element_t*)realloc(stk->data, stk->capacity*sizeof(stack_element_t));

    memset(stk->data + stk->size, NAN, stk->size);

    ASSERT(stk ON_DEBUG(, __FILE__, __func__, __LINE__));
}

void dtor(Stack* stk)
{
    ASSERT(stk ON_DEBUG(, __FILE__, __func__, __LINE__));

    free(stk->data);

    ASSERT(stk ON_DEBUG(, __FILE__, __func__, __LINE__));
}