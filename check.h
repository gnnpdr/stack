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
    #define POSITION , __FILE__, __func__, __LINE__
    #define ADV_POS , const char* file, const char* func, const int line
    #define CHECK(stk) stack_assert_func(stk POSITION)
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
    O_VERFLOW,
    HASH_PROBLEM,
    VALUE_PROBLEM,
    NOT_PTR,
    UNKNOWN
};
#endif

typedef double stack_element_t;

struct Stack
{
    #ifdef DEBUG
    const unsigned long long left_canary;
    const char* origin_file;
    int origin_str;
    const char* origin_func;
    unsigned long hash;
    const unsigned long long right_canary;
    #endif

    stack_element_t* data;
    size_t size;
    size_t capacity;
};


void dump(Stack* stk , const char* file, const char* func, const int code_str);
int check(Stack* stk);

void stack_assert_func(Stack* stk, const char* file, const char* func, const int code_str);

unsigned long long stk_hash(Stack* stk);

#endif //_CHECK_H_