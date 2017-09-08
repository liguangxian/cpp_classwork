
#ifndef __LITE_STACK_h__
#define __LITE_STACK_h__

#include <stdbool.h>

typedef struct _LiteStack
{
	char *data;
	int size;
	int capacity;
}LiteStack, *LiteStackPtr;

typedef void(*LITE_FUNC)(char);


void lite_stack_push(LiteStackPtr* ptr, const char data);
char lite_stack_pop(LiteStackPtr* ptr);

void lite_stack_foreach(LiteStackPtr, LITE_FUNC);

bool lite_stack_empty(LiteStackPtr);



#endif