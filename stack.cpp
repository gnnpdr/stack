#include <stdio.h>

#include "stack.h"

void ctor(Stack* stk ADV_POS)
{
    #ifdef DEBUG
    stk->origin_file = file;
    stk->origin_str = line;
    stk->origin_func = func;
    #endif

    stk->size = 0;
    stk->capacity = AMOUNT;
    size_t capacity = stk->capacity;
    stack_element_t* start_ptr = 0;

    start_ptr = (stack_element_t*)calloc(capacity + ADD_CAP, sizeof(stack_element_t));

    CHECK(stk);  //проверить, что считает хэш и правильно он это делает, надо ли сюда эту функцию

    #ifdef DEBUG
    start_ptr[0] = LEFT_CANARY;
    start_ptr[capacity + ADD_IN] = RIGHT_CANARY;
    #endif

    memset(start_ptr + ADD_IN, POISON, capacity);

    stk->data = start_ptr; //сначала делаем все нужное в памяти, а потом просто присваеваем этот кусок элементу структуры
}

void change_capacity(Stack* stk, size_t capacity)
{
    CHECK(stk);
    if 

    if (stk->size == stk->capacity)
        more_capacity(stk);

    if (stk->size == stk->capacity/4)
        less_capacity(stk);

    CHECK(stk);
}

/*void more_capacity(Stack* stk)
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

    #ifdef DEBUG
    *(stk->data) = stk->left_canary;
    *(stk->data + stk->capacity + 2) = stk->right_canary;
    #endif

    ASSERT(stk ON_DEBUG(, __FILE__, __func__, __LINE__));
}
*/
void cool_realloc(Stack* stk)
{
    ASSERT(stk ON_DEBUG(, __FILE__, __func__, __LINE__));

    stk->data = (stack_element_t*)realloc(stk->data, stk->capacity*sizeof(stack_element_t));
    memset(stk->data + stk->size, POISON, stk->size);

    #ifdef DEBUG
    *(stk->data) = stk->left_canary;
    *(stk->data + stk->capacity + 2) = stk->right_canary;
    #endif

    ASSERT(stk ON_DEBUG(, __FILE__, __func__, __LINE__));
}

void dtor(Stack* stk)
{
    ASSERT(stk ON_DEBUG(, __FILE__, __func__, __LINE__));

    free(stk->data);

    ASSERT(stk ON_DEBUG(, __FILE__, __func__, __LINE__));
}