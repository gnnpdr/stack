#include <stdio.h>

#include "../include/check.h"

#ifdef DEBUG
void dump(Stack* stk, const char* file, const char* func, const int code_str, ErrList *const list)
{
    assert(stk);
    assert(file);
    assert(func);

    FILE* log_file = fopen("log_file.txt", "w");
    FILE_CHECK(log_file)

    stack_element_t* data = stk->data;
    size_t size = stk->size;
    size_t capacity = stk->capacity;

    fprintf(log_file, "Stack [%lx]\n", (size_t)stk);

    fprintf(log_file, "called from %s: %d (%s)\n", file, code_str, func);
    fprintf(log_file, "name stk born at %s: %d (%s)\n", stk->origin_file, stk->origin_str, stk->origin_func);

    fprintf(log_file ,"\nleft canary = %#lx\n", (size_t)data[0]);
    fprintf(log_file ,"right canary = %#lx\n\n", (size_t)data[capacity LEFT_CANARY_ADD]);

    fprintf(log_file, "array data address %p\n", data);
    fprintf(log_file, "capacity = %ld\n", capacity);
    fprintf(log_file, "size = %ld\n", size);
    fprintf(log_file, "array data [%lx]\n\nDATA\n", (size_t)data);
    
    print_stk_elements(stk, log_file);
    ERR_RET_VOID

    fclose(log_file);
}


void check(Stack* stk, ErrList *const list)
{
    assert(stk);
    assert(list);
    assert(stk->data);

    size_t capacity = stk->capacity;
    stack_element_t* data = stk->data;

    if (!stk)
    {
        printf("allocation\n");
        ERROR(ALLOCATION_ERROR)
    }

    if (stk->size > stk->capacity)
    {
        printf("overflow\n");
        ERROR(BUFFER_OVERFLOW)
    } 

    if(data[0] != R_CAN_VAL)
    {
        printf("can err\n");
        ERROR(R_CAN_ERROR);
    } 
        
    if(data[capacity LEFT_CANARY_ADD] != R_CAN_VAL)
    {
        printf("can err\n");
        ERROR(R_CAN_ERROR);
    }    

    if (stk->hash != stk_hash(stk))
    {
        printf("hash_err\n");
        ERROR(HASH_ERROR)
    } 
}


unsigned long long stk_hash(Stack* stk)
{
    assert(stk);

    unsigned long long hash = START_HASH;
    stack_element_t* data = stk->data;
    size_t size = stk->size;
    if (data[size] == POISON)
        size--;

    size_t elem_num = 0 LEFT_CANARY_ADD;

    while (elem_num <= size)
    {
        hash = hash * 33  + (unsigned long long)data[elem_num];
        elem_num++;
    }

    return hash;
}
#endif

void print_stk_elements(Stack* stk, FILE *const log_file)
{
    assert(stk);
    assert(log_file);

    size_t capacity = stk->capacity;
    size_t size = stk->size;
    stack_element_t* data = stk->data;

    for (size_t i = 0 LEFT_CANARY_ADD; i < capacity; i++)
    {
        if(i < size)
            fprintf(log_file, " * ");
        else
            fprintf(log_file, "   ");
        if (data[i] == POISON)
            fprintf(log_file, "[%ld] = %lf (POISON)\n", i, POISON);
        else
            fprintf(log_file, "[%ld] = %lf\n", i, data[i]);
    }
}