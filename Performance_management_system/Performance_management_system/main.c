#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
int num = 0;
int main()
{
	welcome();
	logn_page();
	int i;
	while ((i = choice()) != 3)
	{
		switch (i)
		{
		case 1:
			sign_in();
			break;
		case 2:
			sign_up();
			break;
		default:
			printf("Invalid input!\n");
			break;
		}
	}
	return 1;
}