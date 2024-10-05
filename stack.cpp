#include <stdio.h>

#include "stack.h"

StkErrors ctor(Stack* stk, const char* file, const char* func, const int code_str)
{
    #ifdef DEBUG
    stk->origin_file = file;
    stk->origin_str = code_str;
    stk->origin_func = func;
    #endif

    stk->size = 0;
    stk->capacity = stk_amount;
    size_t capacity = stk->capacity;
    stack_element_t* start_ptr = 0;

    start_ptr = (stack_element_t*)calloc(capacity + CANARY_CAPACITY_ADD, sizeof(stack_element_t));
    if (start_ptr == nullptr)
    {
        printf("no place for arrays\n");   //пропишем здесь, тк после этого вернутся в main, обходя assert_func, где должна былаа вывестись надпись
        return NO_PLACE;                   //делаем проверку отдельно, не через чек, тк не хотим в структуру фигню писать
    }
    
    for (size_t i = 0; i < capacity; i++)
        start_ptr[i + LEFT_CANARY_ADD] = poison;

    #ifdef DEBUG
    start_ptr[0] = left_canary_value;
    start_ptr[capacity + LEFT_CANARY_ADD] = right_canary_value;
    #endif

    stk->data = start_ptr; //сначала делаем все нужное в памяти, а потом просто присваеваем этот кусок элементу структуры

    ASSERT_STK(stk)

    return ALL_RIGHT;
}

void dtor(Stack* stk)
{
    free(stk->data);
}