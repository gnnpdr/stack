#ifndef _ERRORS_H_
#define _ERRORS_H_

#define DEBUG
#ifdef DEBUG
#include <assert.h>
#include <stdlib.h>

//----------------CONSTS--ENUMS----------------
static const size_t ERRORS_AMT      = 15;
static const size_t ERROR_VALUE_SIZE_T = 993;
static const int    ERROR_VALUE_INT    = -8;

enum Errors
{
    ALL_RIGHT,
    ALLOCATION_ERROR,
    BUFFER_OVERFLOW,
    HASH_ERROR,
    VALUE_ERROR,
    R_CAN_ERROR,
    RET_ERROR,
    FILE_ERROR,
    CLOSE_ERROR,
    UNKNOWN
};

//------------STRUCTS------------------------

struct Err_param
{
    Errors err_num;

    const char* file;
    const char* func;
    int line;
};

struct ErrList
{
    Err_param* list;
    size_t head;
};

//-----------------DEFINES------------------

#define LOCATION_DEF const char *const file, const char *const func, int line
#define LOCATION __FILE__, __FUNCTION__, __LINE__ 

//=================MAKE--ERR==========================

#define ERROR(err_num)  list_push(list, LOCATION, err_num);

#define FILE_CHECK(file)    do                                                  \
                            {                                                   \
                                if (file == nullptr)                            \
                                {                                               \
                                    ERROR(FILE_ERROR)                           \
                                    return;                                     \
                                }                                               \
                            }while(0);

#define ALLOCATION_CHECK_PTR(buf)   do                                          \
                                    {                                           \
                                        if (buf == nullptr)                     \
                                        {                                       \
                                            ERROR(ALLOCATION_ERROR)             \
                                            return nullptr;                     \
                                        }                                       \
                                    }while(0);

#define ALLOCATION_CHECK_VOID(buf) do                                           \
                            {                                                   \
                                if (buf == 0)                                   \
                                {                                               \
                                    ERROR(ALLOCATION_ERROR)                     \
                                    return;                                     \
                                }                                               \
                            }while(0);

#define CLOSE_CHECK         do                                                  \
                            {                                                   \
                                if(close_res != 0)                              \
                                {                                               \
                                    ERROR(CLOSE_ERROR)                          \
                                    return;                                     \
                                }                                               \
                            }while(0);


//=================RET================================


#define FATAL_ERR       do                                                                                                              \
                        {                                                                                                               \
                            if (list.head != 0)                                                                                         \
                            {                                                                                                           \
                                printf("you have problem number %d\n", list.list[0].err_num);                                           \
                                for (size_t i = 0; i < list.head; i++)                                                                  \
                                    printf("in file %s, func %s, line %d\n", list.list[i].file, list.list[i].func, list.list[i].line);  \
                                dump(&stk, LOCATION, &list);                                                                            \
                                return 1;                                                                                               \
                            }                                                                                                           \
                        } while (0);    

#define ERR_RET_VOID     do                                                     \
                        {                                                       \
                            if (list->head != 0)                                \
                            {                                                   \
                                ERROR(RET_ERROR)                                \
                                return;                                         \
                            }                                                   \
                        }while(0);




//-----------------FUNCS-----------------

void error_list_ctor(ErrList *const list);
void list_push(ErrList *const list, LOCATION_DEF, Errors err);
void error_list_dtor(ErrList *const list);

#else
#define ERROR(err_num) 
#define FILE_CHECK(file) 
#define ALLOCATION_CHECK_PTR(buf) 
#define ALLOCATION_CHECK_VOID(buf) 
#define WRITE_CHECK 
#define CLOSE_CHECK 


#endif      //DEBUG


#endif //_ERRORS_H_