#ifndef _CHECK_H_
#define _CHECK_H_

#include <assert.h>
#include <math.h>

#include "errors.h"

//#define DEBUG

typedef double stack_element_t;
static const stack_element_t POISON = 228;

struct Stack
{
    #ifdef DEBUG
    unsigned long long left_canary;
    const char* origin_file;
    int origin_str;
    const char* origin_func;
    unsigned long long hash;
    unsigned long long right_canary;
    #endif

    stack_element_t* data;
    size_t size;
    size_t capacity;
};


#ifdef DEBUG
    
    static const unsigned long long L_CAN_VAL = 0xC001;
    static const unsigned long long R_CAN_VAL = 0xC001;
    static const unsigned long long START_HASH = 5381;

    #define CANARY_CAPACITY_ADD + 2
    #define LEFT_CANARY_ADD + 1
#else
    #define CANARY_CAPACITY_ADD + 0
    #define LEFT_CANARY_ADD + 0
    
#endif

void dump(Stack* stk, const char* file, const char* func, const int code_str, ErrList *const list);
unsigned long long stk_hash(Stack* stk);
void print_stk_elements(Stack* stk, FILE *const log_file);

void check(Stack* stk, ErrList *const list);

#endif //_CHECK_H_