#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
int num = 0;
int main()
{

	Node *header = (Node*)malloc(sizeof(Node));
	memset(header, 0, sizeof(Node));
	welcome();
	navigation();
	//while ();
	int i;
	while ((i = choice()) != 15)
	{
		switch (i)
		{
		case 1:
			insert_data(&header);
			processList(header);
			break;
		case 2:
		{
			char id[ARRAY_SIZE];
			//char *ch = 0 ;
			fputc("input delete ID:\n", stdout);
			//fputs("input delete ID:\n", stdout);
			memset(id, 0, sizeof(id));
			scanf("%s", id);
			delete_data(&header, id);
			processList(header);
		}
		break;
		case 3:
			search_data(&header);
			break;
		case 4:
		{
			char id[ARRAY_SIZE];
			//char *ch = 0 ;
			fputs("input update ID:\n", stdout);
			memset(id, 0, sizeof(id));
			scanf("%s", id);
			update_data(&header, id);
		}
		break;
		case 5:
			write_file_memory(header);
			break;
		case 6:
			WriteFile(header);
			break;
		case 7:
			read_file();
			break;
		case 8:
			if (write_list(&header) != 0)
			{
				processList(header);
			}
			break;
		case 9:
			sort_page();
			sort_choice(header);
			navigation();
			break;
		case 10:
			list_insert_data(&header);
			processList(header);
			break;
		case 11:
			format(&header);
			break;
		default:
			printf("please input choice again!\n");
			break;
		}
	}
	return 1;
}