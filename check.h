#ifndef _CHECK_H_
#define _CHECK_H_

#include <assert.h>
#include <math.h>

#define DEBUG

#ifdef DEBUG
    #define ADD_CAP 2
    #define ADD_IN 1
    #define LEFT_CANARY 0xC00F
    #define RIGHT_CANARY 0xC00F
    #define START_HASH 5381
    #define POISON 13

    #define CHECK_FUNC(func)    do                        \
                                {                         \
                                    if(func != ALL_RIGHT) \
                                        return 0;         \
                                } while (0);

    #define ASSERT_STK(stk)     do                              \
                                {                               \
                                    if(check(stk) != ALL_RIGHT) \
                                    {                           \
                                        dump(stk POSITION);     \
                                        return PROBLEM;         \
                                    }                           \
                                } while (0);

    #define POSITION , __FILE__, __func__, __LINE__
#else
    #define ADD
    #define POSITION
#endif

#ifdef DEBUG
enum StkErrors
{
    ALL_RIGHT,
    NO_PLACE,
    PROBLEM,
    BUFFER_OVERFLOW,
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


void dump(Stack* stk, const char* file, const char* func, const int code_str);
StkErrors check(Stack* stk);

void stack_assert_func(Stack* stk, const char* file, const char* func, const int code_str);

unsigned long long stk_hash(Stack* stk);

#endif //_CHECK_H_