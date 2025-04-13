#include <stdio.h>

#include "../include/stk.h"

static void change_capacity(Stack *const stk, ErrList *const list);

//---------------------CTOR-DTOR-----------------------------------------------------------------------

void stk_ctor(Stack *const stk, ErrList *const list)
{
    STK_ASSERT

    stk->size = 0;
    stk->capacity = START_STK_SIZE;

    stk->size = LEFT_CANARY_ADD;
    size_t capacity = stk->capacity;
    stack_element_t* data = stk->data;

    data = (stack_element_t*)calloc(capacity CANARY_CAPACITY_ADD, sizeof(stack_element_t));
    ALLOCATION_CHECK_VOID(data)
    
    for (size_t i = 0; i < capacity; i++)
        data[i] = POISON;

    stk->data = data;

    #ifdef DEBUG
    data[0] = L_CAN_VAL;
    data[capacity LEFT_CANARY_ADD] = R_CAN_VAL;
    #endif
}

void stk_dtor(Stack *const stk)
{
    free(stk->data);
}

//------------FUNCTIONS-------------------------------------------------------------------------------------------------


void stk_push(Stack *const stk, stack_element_t element, ErrList *const list)
{
    STK_ASSERT

    size_t size     = stk->size;
    size_t capacity = stk->capacity;

    if (size >= capacity)
    {
        change_capacity(stk, list);
        ERR_RET_VOID
    }
    
    stack_element_t* data = stk->data;

    data[size] = element;

    #ifdef DEBUG
    stk->hash = stk_hash(stk);
    #endif

    check(stk, list);
    ERR_RET_VOID

    size++;
    stk->size = size;
}

void change_capacity(Stack *const stk, ErrList *const list)
{
    STK_ASSERT

    size_t size = stk->size;
    size_t capacity = stk->capacity;
    stack_element_t* data = stk->data;

    size_t new_capacity = 0;

    if (size >= capacity)
        new_capacity = capacity * DELTA;
    else
        new_capacity = capacity / DELTA;

    data = (stack_element_t*)realloc(data, (new_capacity CANARY_CAPACITY_ADD) * sizeof(stack_element_t));
    ALLOCATION_CHECK_VOID(data)
    
    for (size_t i = 0; i <= capacity; i++)
        data[capacity + i] = POISON;

    #ifdef DEBUG
    data[new_capacity LEFT_CANARY_ADD] = R_CAN_VAL;
    #endif

    stk->capacity = new_capacity;
    stk->data = data; 

    stk->size = size;

    #ifdef DEBUG

    stk->hash = stk_hash(stk);
    #endif

    check(stk, list);
    ERR_RET_VOID
}

void stk_pop(Stack *const stk, stack_element_t* elem, ErrList *const list)
{
    STK_ASSERT
    assert(elem);

    check(stk, list);
    ERR_RET_VOID

    size_t size = stk->size;
    size_t capacity = stk->capacity;

    if (size == (capacity / DOUBLE_DELTA) && size > MIN_STK_SIZE)
    {
        change_capacity(stk, list);
        ERR_RET_VOID
    }

    stack_element_t* data = stk->data;
    
    *elem = data[size];
    data[size] = POISON;
    size--;

    stk->size = size;
    stk->data = data;

    #ifdef DEBUG
    stk->hash = stk_hash(stk);
    #endif

    check(stk, list);
    ERR_RET_VOID
}