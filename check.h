#ifndef _CHECK_H_
#define _CHECK_H_

#include <assert.h>
#include <math.h>

#define DEBUG

typedef double stack_element_t;

#ifdef DEBUG
    static const stack_element_t poison = 13;
    static const unsigned long long left_canary_value = 0xC001;
    static const unsigned long long right_canary_value = 0xC001;
    static const unsigned long long start_hash = 5381;
    #define CANARY_CAPACITY_ADD 2
    #define LEFT_CANARY_ADD 1

    #define CHECK_FUNC(func)    do                              \
                                {                               \
                                    if(func != ALL_RIGHT)       \
                                        return PROBLEM;         \
                                } while(0);

    #define ASSERT_STK(stk)     do                              \
                                {                               \
                                    if(check(stk) != ALL_RIGHT) \
                                    {                           \
                                        dump(stk POSITION);     \
                                        return PROBLEM;         \
                                    }                           \
                                } while(0);

    #define POSITION , __FILE__, __func__, __LINE__
#else
    #define CANARY_CAPACITY_ADD 
    #define LEFT_CANARY_ADD 
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
void print_stk_elements(stack_element_t* start_ptr, size_t capacity, size_t size);
StkErrors check(Stack* stk);

void stack_assert_func(Stack* stk, const char* file, const char* func, const int code_str);

unsigned long long stk_hash(Stack* stk);

#endif //_CHECK_H_