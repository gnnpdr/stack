#include <stdio.h>

#include "stack_operations.h"

StkErrors enter_element(Stack* stk)
{
    StkErrors check_res = ALL_RIGHT;

    printf("what do you want to add?\n");
    stack_element_t element = 0;
    scanf("%lg", &element);

    size_t amount = 0;
    printf("how many times?\n");
    scanf("%d", &amount);

    for (size_t i = 0; i < amount; i++)
    {
        RESULT check_capacity(stk); //проверка доступной памяти, выделение при необходимости
        RESULT push(stk, element);  //добавление элемента
    }

    return check_res;
}

StkErrors check_capacity(Stack* stk)
{
    int check_res = ALL_RIGHT;
    size_t size = stk->size;
    size_t capacity = stk->capacity;
    stack_element_t* start_ptr = stk->data;

    if (size == capacity)
    {
        memset(start_ptr + capacity, POISON, capacity + ADD_IN);  //проставили пойсон в новые ячейки, убрали канарейку
        capacity = capacity * DELTA;
        RESULT change_capacity(stk);
    }

    else if (size == capacity/4)
    {
        capacity = capacity/DELTA;
        memset(stk->data + capacity + ADD_IN, 0, capacity + ADD_IN); //очистить в нули то, что осталось от стэка - канарейку и пойсон
        RESULT change_capacity(stk);
    }

    return CHECK(stk);  //проверка на канарейки и и размер, те найдено ли место, все дела 
}


StkErrors change_capacity(Stack* stk)
{
    size_t size = stk->size;
    size_t capacity = stk->capacity;
    stack_element_t* start_ptr = stk->data;

    start_ptr = (stack_element_t*)realloc(start_ptr, capacity*sizeof(stack_element_t));  //изменили объем массива
    if (start_ptr == nullptr)
    {
        printf("no place for arrays\n");
        return NO_PLACE;        //делаем проверку отдельно, не через чек, тк не хотим в структуру фигню писать
    }
        
    start_ptr[capacity + ADD_IN] = LEFT_CANARY;  //поставили канарейку

    stk->capacity = capacity;          //изменение значений в структуре
    stk->data = start_ptr;

    return CHECK(stk);
}

StkErrors check_hash(Stack* stk)
{
    stk->hash = stk_hash(stk);
    return CHECK(stk);
}

StkErrors push(Stack* stk, stack_element_t element)
{
    stk->data[stk->size + ADD_IN] = element;
    stk->size++;

    check_hash(stk);

    return CHECK(stk);                       //проверка была в другой функции, так что здесь поставим только в конце
}

StkErrors del_element(Stack* stk)
{
    StkErrors check_res = ALL_RIGHT;

    size_t amount = 0;
    printf("how many elements do you want to del?\n");
    scanf("%d", &amount);

    for (size_t i = 0; i < amount; i++)
    {
        RESULT check_capacity(stk); //проверка доступной памяти, выделение при необходимости
        RESULT pop(stk);            //удаление элемента
    }
    
    return check_res;
}

StkErrors pop(Stack* stk)
{
    stk->data[stk->size] = POISON;
    stk->size--;

    check_hash(stk);

    return CHECK(stk);
}