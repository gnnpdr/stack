#include <stdio.h>

#include "stack_operations.h"

StkErrors push(Stack* stk, stack_element_t element)
{
    ASSERT_STK(stk)

    stack_element_t* start_ptr = stk->data;
    size_t size = stk->size;
    size_t capacity = stk->capacity;

    if (size >= capacity)
    {
        size_t new_capacity = capacity * delta;
        CHECK_FUNC(change_capacity(stk, new_capacity, capacity))
    }

    start_ptr[size + LEFT_CANARY_ADD] = element;
    size++;
    stk->size = size;
    stk->hash = stk_hash(stk);

    ASSERT_STK(stk)
    return ALL_RIGHT;
}

StkErrors change_capacity(Stack* stk, size_t new_capacity, size_t capacity)
{
    ASSERT_STK(stk)

    stack_element_t* start_ptr = stk->data;

    start_ptr = (stack_element_t*)realloc(start_ptr, (new_capacity + CANARY_CAPACITY_ADD)*sizeof(stack_element_t));
    if (start_ptr == nullptr)
    {
        printf("no place\n");
        return NO_PLACE;
    }

    if (new_capacity > capacity)
    {
        for (size_t i = 0; i < capacity + LEFT_CANARY_ADD; i++)
            start_ptr[capacity + LEFT_CANARY_ADD + i] = poison;
    }
    else 
        memset(start_ptr + new_capacity + LEFT_CANARY_ADD, 0, new_capacity + LEFT_CANARY_ADD);
    
    start_ptr[new_capacity + LEFT_CANARY_ADD] = left_canary_value;

    stk->capacity = new_capacity;
    stk->data = start_ptr;

    ASSERT_STK(stk)
    return ALL_RIGHT;
}

StkErrors pop(Stack* stk)
{
    ASSERT_STK(stk)

    size_t size = stk->size;
    size_t capacity = stk->capacity;
    stack_element_t* start_ptr = stk->data;

    if (size <= (capacity / double_delta))
    {
        size_t new_capacity = capacity / delta;
        CHECK_FUNC(change_capacity(stk, new_capacity, capacity))
    }
    
    start_ptr[size] = poison;
    size--;
    stk->size = size;
    stk->hash = stk_hash(stk);

    ASSERT_STK(stk)
    return ALL_RIGHT;
}