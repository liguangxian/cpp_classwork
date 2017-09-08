#pragma once
#pragma once

#include "lite_stack.h"

#include <stdio.h>


void instructions(void);

void printElement(char data)
{
	printf("%c ", data);
}
int main()
{
	LiteStackPtr pStack = 0;

	char item;

	instructions();
	printf("? ");
	int choice;
	scanf("%d", &choice);

	while (choice != 4)
	{

		switch (choice)
		{

		case 1:
		{
			printf("Enter a character: ");
			scanf("\n%c", &item);
			lite_stack_push(&pStack, item);
		}
		break;
		case 2:
		{
			if (!lite_stack_empty(pStack))
			{
				item = lite_stack_pop(&pStack);
				printf("\'%c\' has been destackd.\n", item);
			}

		}
		break;

		case 3:
		{
			printf("stack elements:\n");
			lite_stack_foreach(pStack, printElement);
			printf("\n");
		}
		break;

		default:
			printf("Invalid choice.\n\n");
			instructions();
			break;
		}

		printf("? ");
		scanf("%d", &choice);
	}

	printf("End of run.\n");
	return 0;
}

void instructions(void)
{
	printf("Enter your choice:\n"
		"   1 to add an item to the queue\n"
		"   2 to remove an item from the queue\n"
		"   3 show all elements in the queue\n"
		"   4 to end\n");
}