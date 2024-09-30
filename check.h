#ifndef _CHECK_H_
#define _CHECK_H_

#include <assert.h>
#include <math.h>

#define ASSERT (stk ...) stack_assert_func(stk, __FILE__, __func__, __LINE__);

#define DEBUG
    #define ON_DEBUG(code) code
#else
    #define ON_DEBUG(code)
#endif

enum Problem
{
    ALL_RIGHT,
    NO_PLACE,
    ARRAY_LIMIT_PROBLEM,
    FILLING_PROBLEM,
    NOT_PTR
};

typedef double stack_element_t;

struct Stack
{
    #ifdef DEBUG  //надо как-то поумнее сделать, чтоюы весь код одним макросом, а не через ifdef

    const char* origin_file;
    const int* origin_str;
    const char* origin_func;

    #endif

    stack_element_t* data;
    size_t size;
    size_t capacity;
};


void dump(Stack* stk, const char* file, const char* func, const int code_str);
int errors(Stack* stk);

void stack_assert_func(Stack* stk, const char* file, const char* func, const int code_str);

#endif //_CHECK_H_