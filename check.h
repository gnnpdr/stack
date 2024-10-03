#ifndef _CHECK_H_
#define _CHECK_H_

#include <assert.h>
#include <math.h>

#define DEBUG

#ifdef DEBUG
    #define ADD_CAP 2
    #define ADD_IN 1
    #define LEFT_CANARY 0xC
    #define RIGHT_CANARY 0xC
    #define START_HASH 5381
    #define STRUCT_CAPACITY 3
    #define POISON 13
    #define POSITION , __FILE__, __func__, __LINE__
    #define ADV_POS , const char* file, const char* func, const int code_str
    #define CHECK(stk) check(stk)
    #define ASSERT if(check_res != ALL_RIGHT) dump(&stk POSITION)
    #define RESULT if(check_res == ALL_RIGHT) check_res = 
#else
    #define ADD
    #define POSITION 
    #define ADV_POS 
    //#define ON_DEBUG(code)
#endif

#ifdef DEBUG
enum StkErrors
{
    ALL_RIGHT,
    NO_PLACE,
    OVERFLOW_,
    HASH_PROBLEM,
    VALUE_PROBLEM,
    UNKNOWN
};
#endif

typedef double stack_element_t;

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


void dump(Stack* stk ADV_POS);
StkErrors check(Stack* stk);

void stack_assert_func(Stack* stk ADV_POS);

unsigned long long stk_hash(Stack* stk);

#endif //_CHECK_H_