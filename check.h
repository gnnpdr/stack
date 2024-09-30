#ifndef _CHECK_H_
#define _CHECK_H_

#include <assert.h>
#include <math.h>

#define DEBUG

#ifdef DEBUG
    #define ON_DEBUG(...) __VA_ARGS__
    #define ASSERT(stk, ...) stack_assert_func(stk __VA_ARGS__);
#else
    #define ON_DEBUG(code)
#endif

#ifdef DEBUG
enum Problem
{
    ALL_RIGHT,
    NO_PLACE,
    ARRAY_LIMIT_PROBLEM,
    FILLING_PROBLEM,
    NOT_PTR
};
#endif

typedef double stack_element_t;

struct Stack
{
    #ifdef DEBUG
    const int left_canary = 0xCOOL;  //ошибка, как этим пользоваться? и как бы так сделать, чтобы эта ячейка не менялась
    const char* origin_file;
    const int* origin_str;
    const char* origin_func;
    unsigned long hash = 5381;
    const int right_canary = 0xCOOL;
    #endif

    stack_element_t* data;
    size_t size;
    size_t capacity;
};


void dump(Stack* stk ON_DEBUG(, const char* file, const char* func, const int code_str));
int errors(Stack* stk);

void stack_assert_func(Stack* stk ON_DEBUG(, const char* file, const char* func, const int code_str));

unsigned long hash(char *str);

#endif //_CHECK_H_