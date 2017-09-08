#include "lite_stack.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#ifdef _DEBUG
static const int ALLOC_STEP = 2;
#else
static const int ALLOC_STEP = 100;

#endif // DEBUG




void lite_stack_push(LiteStackPtr* ptr, const char data)
{
	assert(ptr != 0);
	//考虑空队列
	if (*ptr == 0)
	{
		*ptr = calloc(1, sizeof(LiteStack));
	}
	//考虑队列内部数据空间不足时扩容
	if ((*ptr)->size + 1 > (*ptr)->capacity)
	{
		//给数据成员分配空间
		(*ptr)->data = realloc((*ptr)->data, (*ptr)->capacity + ALLOC_STEP);
		(*ptr)->capacity = (*ptr)->capacity + ALLOC_STEP;
	}
	//给队列内部数据按索引赋值(尾部)
	(*ptr)->data[(*ptr)->size] = data;
	(*ptr)->size += 1;

}
char lite_stack_pop(LiteStackPtr* ptr)
{
	assert(ptr != 0 && (*ptr) != 0 && (*ptr)->size != 0);

	char ret = (*ptr)->data[(*ptr)->size - 1];

	char* pdata = malloc((*ptr)->capacity);
	memcpy(pdata, (*ptr)->data, ((*ptr)->size - 1));
	free((*ptr)->data);
	(*ptr)->data = pdata;

	//memmove((*ptr)->data, (*ptr)->data + 1, (*ptr)->size - 1);

	(*ptr)->size -= 1;

	return ret;
}

bool lite_stack_empty(LiteStackPtr stack)
{
	assert(stack != 0);
	return stack->size == 0;
}

void lite_stack_foreach(LiteStackPtr stack, LITE_FUNC func)
{
	assert(stack);
	for (int i = 0; i < stack->size; i++)
	{
		func(stack->data[i]);
	}
}