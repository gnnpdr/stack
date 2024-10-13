#include <stdio.h>

#include "stack_operations.h"

StkErrors push(Stack* stk, stack_element_t element, StkErrors* err)
{
    CHECK_STK(stk, err)

    stack_element_t* data = stk->data;
    size_t           size      = stk->size;
    size_t           capacity  = stk->capacity;

    if (size >= capacity)
    {
        size_t new_capacity = capacity * delta;
        change_capacity(stk, new_capacity, capacity, err);
        RETURN(*err)
    }

    data[size] = element;
    size++;
    stk->size = size;
    
    #ifdef DEBUG
    stk->hash = stk_hash(stk);
    #endif

    CHECK_STK(stk, err)
    return ALL_RIGHT;
}

StkErrors change_capacity(Stack* stk, size_t new_capacity, size_t capacity, StkErrors* err)
{
    CHECK_STK(stk, err)

    stack_element_t* data = stk->data;

    data = (stack_element_t*)realloc(data, (new_capacity CANARY_CAPACITY_ADD)*sizeof(stack_element_t));
    #ifdef DEBUG
    if (data == nullptr)
    {
        printf("no place\n");
        return NO_PLACE;
    }
    #endif 

    if (new_capacity > capacity)
    {
        for (size_t i = 0; i <= capacity LEFT_CANARY_ADD; i++)
            data[capacity LEFT_CANARY_ADD + i] = poison;
    }

    stk->capacity = new_capacity;
    stk->data = data;

    #ifdef DEBUG
    data[new_capacity LEFT_CANARY_ADD] = right_canary_value;
    
    #endif

    CHECK_STK(stk, err)
    return ALL_RIGHT;
}

StkErrors pop(Stack* stk, StkErrors* err)
{
    CHECK_STK(stk, err)

    size_t size = stk->size;
    size_t capacity = stk->capacity;
    stack_element_t* data = stk->data;

    if (size == (capacity / double_delta))
    {
        size_t new_capacity = capacity / delta;
        change_capacity(stk, new_capacity, capacity, err);
        RETURN(*err)
    }
    
    data[size] = poison;
    size--; 
    stk->size = size;

    stk->data = data;

    #ifdef DEBUG
    stk->hash = stk_hash(stk);
    #endif

    CHECK_STK(stk, err)
    return ALL_RIGHT;
}