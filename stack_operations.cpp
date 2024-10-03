#include <stdio.h>

#include "stack_operations.h"

enter_element(Stack* stk)
{
    printf("bro, what do you want to add to this cool stack??!\n");
    stack_element_t element = 0;
    scanf("%ld", &element);

    size_t amount = 0;
    printf("how many times, buddy?\n");
    scanf("%d", &amount);

    for (size_t i = 0; i < amount; i++)
    {
        check_capacity(stk); //проверка доступной памяти
        push(stk, element);  //добавление элемента
        check_hash();        //пересчет хэша
    }
}

check_capacity(Stack* stk)
{
    size_t size = stk->size;
    size_t capacity = stk->capacity;
    stack_element_t* start_ptr = stk->data;

    if (size == capacity)
    {
        start_prt[capacity + 1] = POISON;  //убрали канарейку
        capacity = capacity * DELTA;
        stk->capacity = capacity;          //изменение параметра объема
        memset(start_ptr + capacity + ADD_IN, POISON, capacity);
    }

    else if (size == capacity/4)
    {
        capacity = capacity/DELTA;
        stk->capacity = capacity;
        memset(stk->data + capacity + ADD_IN, 0, capacity + ADD_IN); //очистить в нули то, что осталось от стэка - канарейку и пойсон
    }

    

    start_ptr = (stack_element_t*)realloc(start_ptr, capacity*sizeof(stack_element_t));  //изменили объем массива
    
    CHECK();   //стоит?
    stk->data = ptr;
    stk->data[capacity + 1] = LEFT_CANARY;  //поставили канарейку
    CHECK(stk);  //главным образом на канарейки и и размер, те найдено ли место, все дела 
}

check_hash(Stack* stk)
{
    stk->hash = stk_hash(stk);
    CHECK;
}

int push(Stack* stk, stack_element_t element)
{
    CHECK(stk);

    stk->size++;
    stk->data[stk->size] = element; //сделать поправку на канарейку

    CHECK(stk);
}

del_element()
{
    size_t amount = 0;

    printf("how much&\n");
    scanf("%d", &amount);

    for (size_t i = 0; i < amount; i++)
    {
        check_capacity();
        pop();
        check_hash();
        CHECK();
    }
}

int pop(Stack* stk, stack_element_t* output)
{
    CHECK(stk);

    stk->data[stk->size] = POISON;
    stk->size--;

    CHECK(stk);
}

