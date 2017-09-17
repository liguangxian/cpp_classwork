#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
void welcome()
{
	printf("\t\t\t********WELCOME PERFORMANCE MANAGEMENT SYSTEM*****\n\n");
}
void navigation()
{
	printf("\t\t\t************* MANAGEMENT SYSTEM ******************\n"
		   "\t\t\t*                                                *\n"
		   "\t\t\t*        1 to   插入成绩信息 .                   *\n"
		   "\t\t\t*        2 to   删除成绩信息 .                   *\n"
		   "\t\t\t*        3 to   查找学生信息 .                   *\n"
		   "\t\t\t*        4 to   修改学生信息 .                   *\n"
		   "\t\t\t*        5 to   信息保存到数据库 .               *\n"
		   "\t\t\t*        6 to   将数据导出到指定文件 .           *\n"
		   "\t\t\t*        7.to   将数据库的文件输出到屏幕 !       *\n"
		   "\t\t\t*        8.to   将数据库中的文件写到缓冲区 !     *\n"
		   "\t\t\t*        9.to   数据排序                         *\n"
		   "\t\t\t*        10.to  插入学生信息 .                   *\n"
		   "\t\t\t*        11.to  格式化数据库                     *\n"
	       "\t\t\t*        12.to  格式化缓冲区                     *\n"
	       "\t\t\t*        13.to  修改用户信息                     *\n"
		   "\t\t\t*        15.to  结束程序!                        *\n"
		   "\t\t\t*                                                *\n"
		   "\t\t\t*                                                *\n"
	       "\t\t\t****** Capyright @ 2017-9-12 liguangxian *********\n");
}
int choice()
{
	char choice[ARRAY_SIZE];
	loop:printf("Please input yours choice:");
	scanf("%s", choice);
	int a = atoi(choice);
	return a;
	/*int s = strlen(choice);
	if (s == 1)
	{
		int a = (int)choice;
		return a;
	}
	else if (s == 2)
	{
		int a = (int)choice;
		if()
	}*/
	//int a =(int)choice;
	/*for (int i = 0; i < strlen(choice); i++)
	{
		if (choice[i] >= '9'&&choice[i] <= '0')
		{
			goto loop;
		}
		a = (int)choice;
		
	}
	return a;*/
}
Student AssignData(void)         
{

	Node *nptr = (Node*)malloc(sizeof(Node));
	memset(nptr, 0, sizeof(Node));
	fputs("input student number(0001~9999),name,sex(0 is Man ,other is Woman):\n", stdout);
	scanf("%s%s%d", nptr->data.id, &nptr->data.name,  &nptr->data.sex);
	fputs("input student Chinese,Math,English score:\n", stdout);
	scanf("%d%d%d", &nptr->data.score[0], &nptr->data.score[1], &nptr->data.score[2]);
	nptr->data.sum = sum(nptr->data.score[0], nptr->data.score[1], nptr->data.score[2]);
	nptr->data.average= (double)(sum(nptr->data.score[0], nptr->data.score[1], nptr->data.score[2]) / SUB);
	return nptr->data;
}
int insert_data(NodePtr *nptr)
{
	Student data = AssignData();
	NodePtr firNode = *nptr;
	NodePtr midNode = *nptr;
	NodePtr secNode = *nptr;
	NodePtr triNode = *nptr;
	if (secNode->next != 0 || secNode->data.name[0] != 0)
	{
		do
		{
			//if (*(secNode->data.id) == *data.id)      *data.id==0;  *(secNode->data.id)==0 equal secNode->data.id[0] equal data.id[0]
				if (strcmp(secNode->data.id, data.id)==0)//peNode->name ==data is error
			{
				printf("\n***************** Name Is Exist! ****************\n\n");
				return -1;
			}

			midNode = secNode;
			secNode = secNode->next;
		} while (midNode->next != 0);
	}
	if (firNode->data.name[0] == 0)
	{
		Assignment(firNode, data);
		num++;
	}
	else
	{
		while (firNode->next != NULL)
		{
			firNode = firNode->next;
			
		}
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		memset(pNewNode, 0, sizeof(Node));
		firNode->next = pNewNode;
		Assignment(pNewNode, data);
		num++;
	}
	return 1;
}
int list_insert_data(NodePtr *curNode)
{
	Student data = AssignData();
	NodePtr peNode = *curNode;

	NodePtr midNode = *curNode;
	NodePtr secNode = *curNode;
	NodePtr triNode = *curNode;
	int position = 0;
	fputs("Input insert position(position 代表插入的第几个位置，（0~int））:\n", stdout);
	scanf("%d", &position);
	//fputs("input name,sex,lastName,firstName,balance,address(代表从第address位开始输入):\n", stdout);
	//scanf("%s%d%s%s%d%d", name, &sex, &lastName, &firstName, &balance, &key);
	if (peNode->next != 0 || peNode->data.name[0] != 0)
	{
		do
		{
			if (*(peNode->data.name) == *data.name)
				//if (strcmp(peNode->name, data)==0)//peNode->name ==data is error
			{
				printf("name is exist!\n");
				return -1;
			}

			midNode = peNode;
			peNode = peNode->next;
		} while (midNode->next != 0);
	}
	if (position > num)
	{
		printf("Exceeds the entered address value!\n");
		return -1;
	}
	else {
		for (int i = 1; i <= position; i++)
		{
			triNode = secNode;
			secNode = secNode->next;
		}
	}
	NodePtr pCurNode = secNode;
	if (triNode == secNode)
	{
		*curNode = (NodePtr)malloc(sizeof(Node));
		memset(*curNode, 0, sizeof(Node));
		if (pCurNode->data.name[0] == 0)
		{
			Assignment(*curNode, data);
			/*strcpy((*curNode)->name, data);
			(*curNode)->sex = sex;
			(*curNode)->balance = balance;
			strcpy((*curNode)->lastName, lastName);
			strcpy((*curNode)->firstName, firstName);*/
		}
		else
		{
			(*curNode)->next = pCurNode;
			Assignment(*curNode, data);
			/*strcpy((*curNode)->name, data);
			(*curNode)->sex = sex;
			(*curNode)->balance = balance;
			strcpy((*curNode)->firstName, firstName);
			strcpy((*curNode)->lastName, lastName);*/
		}

		num++;
	}
	else
	{
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		memset(pNewNode, 0, sizeof(Node));
		//2.插入节点的next赋值给新node
		triNode->next = pNewNode;
		pNewNode->next = pCurNode;
		//3. 
		Assignment(pNewNode, data);
		/*strcpy(pNewNode->name, data);
		pNewNode->sex = sex;
		pNewNode->balance = balance;
		strcpy(pNewNode->firstName, firstName);
		strcpy(pNewNode->lastName, lastName);*/
		num++;
	}
	return 0;
}
void Assignment(Node *pNode, Student data)
{
	strcpy(pNode->data.id, data.id);
	pNode->data.sex = data.sex;
	strcpy(pNode->data.name, data.name);
	pNode->data.score[0]=data.score[0];
	pNode->data.score[1] = data.score[1];
	pNode->data.score[2] = data.score[2];
	pNode->data.sum = data.sum;
	pNode->data.average = data.average;
}
void processList(NodePtr header)
{
	Node * PriNode = header;
	printf("Row\tID\tName\tsex\tChinese\tMath\tEnglish\tSum\tAverage\n");
	printf("-----------------------------------------------------------------------\n");
	int i = 1;
	while (PriNode)
	{
		if (header->data.id[0] == 0)
		{
			printf("\n**********************  No Data!  ***************************\n\n");
			printf("-----------------------------------------------------------------------\n");
			return;
		}
		printf("%d:\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%.2lf\n", i,PriNode->data.id, PriNode->data.name, PriNode->data.sex == MALE ? "Man" : "Women", PriNode->data.score[0], PriNode->data.score[1], PriNode->data.score[2],PriNode->data.sum,PriNode->data.average);

		PriNode = PriNode->next;
		i++;
	}
	
	printf("----------------------------------------------------------------------\n");
	fputs("\n", stdout);
}
int delete_data(NodePtr *ppNode, const char* id)
{
	NodePtr pNode = *ppNode;
	NodePtr preNode = *ppNode;
	if (pNode->next == 0)
	{
		if ((*ppNode)->data.name[0] == 0)
		{
			printf("Seorry memory not have this number!\n");
			return -1;
		}
		else if (strcmp(pNode->data.id, id) == 0)
		{
			num--;
			*ppNode = (*ppNode)->next;
			free(pNode);
			/*Node *again = (Node*)malloc(sizeof(Node));
			memset(again, 0, sizeof(Node));
			*ppNode = again;*/
			*ppNode = NULL;
			return 1;
		}
	}

	int i = 1;
	do {

		if (strcmp(pNode->data.id, id) == 0)
		{
			if (i == 1)
			{
				num--;
				*ppNode = pNode->next;
				free(pNode);
				break;
			}
			preNode->next = pNode->next;
			num--;
			free(pNode);
			break;
		}
		i++;
		preNode = pNode;
		pNode = pNode->next;
	} while (preNode->next != 0);
}
const char* deId()
{
	char id[ARRAY_SIZE];
	//char *ch = 0 ;
	fputs("input update ID:\n", stdout);
	memset(id, 0, sizeof(id));
	scanf("%s", id);
	return id;
}
int update_data(NodePtr *ptr, const char* id)
{
	NodePtr pNode = *ptr;
	int i;
	for (i = 1; i <= num; i++)
	{


		if (strcmp(pNode->data.id, id) == 0)
		{
			printf("Update data:Chinese,Math,English,Sex:\n");
			scanf("%d%d%d%d", &pNode->data.score[0], &pNode->data.score[1], &pNode->data.score[2], &pNode->data.sex);
			pNode->data.sum = sum(pNode->data.score[0], pNode->data.score[1], pNode->data.score[2]);
			pNode->data.average = (double)pNode->data.sum / SUB;
			priData(&pNode, id);
			printf("Update seccess!\n");
			return 1;
		}
		pNode = pNode->next;

	}
	if (i == num + 1)
	{
		printf("No Find this name data!\n");
		return -1;
	}
	return -1;
}
void priData(NodePtr *list, const char* id)
{
	NodePtr PriNode = *list;
	printf("Row\tID\tName\tsex\tChinese\tMath\tEnglish\tSum\tAverage\n");
	printf("---------------------------------------------------------------------------------------\n");

	printf("\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%.2lf\n", PriNode->data.id, PriNode->data.id, PriNode->data.sex == MALE ? "Man" : "Women", PriNode->data.score[0], PriNode->data.score[1], PriNode->data.score[2], PriNode->data.sum, PriNode->data.average);


	printf("----------------------------------------------------------------------------------------\n");
	fputs("\n", stdout);
}
int sum(int a, int b,int c)
{
	return a + b + c;
}
NodePtr search_data(NodePtr *list)
{
	char id[ARRAY_SIZE];
	fputs("input search id:\n", stdout);
	memset(id, 0, sizeof(id));
	scanf("%s", id);
	NodePtr curNode = *list;
	if (curNode->data.name[0] == 0)
	{
		printf("System no data!\n");
	}
	while (curNode != 0)
	{
		if (strcmp(curNode->data.id, id) == 0)
		{
			priData(&curNode, id);
			return curNode;
		}
		curNode = curNode->next;
	}
	printf("No search id!\n");

}
void WriteFile(NodePtr header)
{
	FILE *writePtr = 0;
	printf("Please enter the path to the exported data file:");
	char p[100] = "";
	int a = 1;
	int b = 1;
	scanf("%s", p);
	if ((writePtr = fopen(p, "w+")) == NULL)
	{
		printf("File not be open!");
		exit(0);
	}
	printf("Please input two number from A to B write file!\n-->");
	scanf("%d%d", &a, &b);
	FILE *wptr = writePtr;
	rewind(wptr);
    char ch = fgetc(wptr);
	if (ch == EOF)
	{
		fprintf(writePtr, "%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", "Acct", "ID", "Name", "Sex", "Chinese", "Math", "English", "Sum", "Average");
	}
	fseek(writePtr, 0, SEEK_END);
	int j = 0;
	for (int i = 1; i <= num; i++)
	{
		if (i >= a&&i <= b)
		{
			j++;
			fprintf(writePtr, "%-10d%-10s%-10s%-10s%-10d%-10d%-10d%-10d%-10.2lf\n", j,
				header->data.id, header->data.name, header->data.sex == MALE ? "Man" : "Women", header->data.score[0], header->data.score[1], header->data.score[2], header->data.sum, header->data.average);
		}
		
		header = header->next;
	}
	printf("write file success!\n");
	fclose(writePtr);
}
void write_file_memory(NodePtr header)
{
	FILE *wPtr = 0;
	NodePtr ptr = header;
	if ((wPtr = fopen(FILE_PATH, "w+")) == NULL)
	{
		printf("Open file is fail!\n");
		exit(0);
	}
	for (int i = 1; i <= num; i++)
	{
		fwrite(&ptr->data, sizeof(struct _StructData), 1, wPtr);
		ptr = ptr->next;
	}
	fclose(wPtr);
	printf("Write data to file success!\n");
} 
void positive_order(NodePtr *ptr)
{
	NodePtr nptr = *ptr;
	NodePtr ntr = *ptr;
	NodePtr aptr[20];
	
	if (num == 0)
	{
		printf("Empty list!\n");
		return;
	}
	printf("Positive Order List of Sum.\n");
	if (num > 1)
	{
		for (int i = 0; i < num; i++)
		{
			aptr[i] = nptr;
			nptr = nptr->next;
		}
		for (int j = 0; j < num-1; j++)
		{
			for (int i = 0; i < num - j-1; i++)
			{
				if (aptr[i]->data.sum < aptr[i+1]->data.sum)
				{
					NodePtr midptr = (NodePtr)malloc(sizeof(Node));
					memset(midptr, 0, sizeof(Node));
					midptr = aptr[i];
					aptr[i] = aptr[i+1];
					aptr[i+1] = midptr;
				}
			}
		}

		for (int i = 0; i < num; i++)
		{

			if (i == (num-1))
			{
				aptr[i]->next = NULL;
				break;
			}
			aptr[i]->next = aptr[i+1];
		}
		*ptr = aptr[0];
		//*ptr->next = aptr[0]->next;
	}
}
void reverse_order(NodePtr *ptr)
{
	NodePtr nptr = *ptr;
	NodePtr ntr = *ptr;
	NodePtr aptr[20];
	if (num == 0)
	{
		printf("Empty list!\n");
		return;
	}
	printf("Reverse Order List of Sum\n");
	if (num > 1)
	{
		for (int i = 0; i < num; i++)
		{
			aptr[i] = nptr;
			nptr = nptr->next;
		}
		for (int j = 1; j < num; j++)
		{
			for (int i = 1; i <= num - j; i++)
			{
				if (aptr[i - 1]->data.sum > aptr[i]->data.sum)
				{
					NodePtr midptr = (NodePtr)malloc(sizeof(Node));
					memset(midptr, 0, sizeof(Node));
					midptr = aptr[i - 1];
					aptr[i - 1] = aptr[i];
					aptr[i] = midptr;
				}
			}
		}

		for (int i = 1; i <= num; i++)
		{

			if (i == num)
			{
				aptr[i - 1]->next = NULL;
				break;
			}
			aptr[i - 1]->next = aptr[i];
		}
		*ptr = aptr[0];
		//*ptr->next = aptr[0]->next;
	}
}
void positive_order_chinese(NodePtr *ptr)
{
	NodePtr nptr = *ptr;
	NodePtr ntr = *ptr;
	NodePtr aptr[20];
	if (num == 0)
	{
		printf("Empty list!\n");
		return;
	}
	printf("Reverse Order List of chinese\n");
	if (num > 1)
	{
		for (int i = 0; i < num; i++)
		{
			aptr[i] = nptr;
			nptr = nptr->next;
		}
		for (int j = 1; j < num; j++)
		{
			for (int i = 1; i <= num - j; i++)
			{
				if (aptr[i - 1]->data.score[0] <= aptr[i]->data.score[0])
				{
					if (aptr[i - 1]->data.score[0] == aptr[i]->data.score[0] && aptr[i - 1]->data.sum > aptr[i]->data.sum)
					{
						continue;
					}
						NodePtr midptr = (NodePtr)malloc(sizeof(Node));
						memset(midptr, 0, sizeof(Node));
						midptr = aptr[i - 1];
						aptr[i - 1] = aptr[i];
						aptr[i] = midptr;
		
				}
			}
		}

		for (int i = 1; i <= num; i++)
		{

			if (i == num)
			{
				aptr[i - 1]->next = NULL;
				break;
			}
			aptr[i - 1]->next = aptr[i];
		}
		*ptr = aptr[0];
		//*ptr->next = aptr[0]->next;
	}
}
void positive_order_math(NodePtr *ptr)
{
	NodePtr nptr = *ptr;
	NodePtr ntr = *ptr;
	NodePtr aptr[20];
	if (num == 0)
	{
		printf("Empty list!\n");
		return;
	}
	printf("Reverse Order List of Math\n");
	if (num > 1)
	{
		for (int i = 0; i < num; i++)
		{
			aptr[i] = nptr;
			nptr = nptr->next;
		}
		for (int j = 1; j < num; j++)
		{
			for (int i = 1; i <= num - j; i++)
			{
				if (aptr[i - 1]->data.score[1] <= aptr[i]->data.score[1])
				{
					if (aptr[i - 1]->data.score[1] == aptr[i]->data.score[1] && aptr[i - 1]->data.sum > aptr[i]->data.sum)
					{
						continue;
					}
					NodePtr midptr = (NodePtr)malloc(sizeof(Node));
					memset(midptr, 0, sizeof(Node));
					midptr = aptr[i - 1];
					aptr[i - 1] = aptr[i];
					aptr[i] = midptr;
				}
			}
		}

		for (int i = 1; i <= num; i++)
		{

			if (i == num)
			{
				aptr[i - 1]->next = NULL;
				break;
			}
			aptr[i - 1]->next = aptr[i];
		}
		*ptr = aptr[0];
		//*ptr->next = aptr[0]->next;
	}
}
void positive_order_english(NodePtr *ptr)
{
	NodePtr nptr = *ptr;
	NodePtr ntr = *ptr;
	NodePtr aptr[20];
	if (num == 0)
	{
		printf("Empty list!\n");
		return;
	}
	printf("Reverse Order List of English\n");
	if (num > 1)
	{
		for (int i = 0; i < num; i++)
		{
			aptr[i] = nptr;
			nptr = nptr->next;
		}
		for (int j = 1; j < num; j++)
		{
			for (int i = 1; i <= num - j; i++)
			{
				if (aptr[i - 1]->data.score[2] <= aptr[i]->data.score[2])
				{
					if (aptr[i - 1]->data.score[2] == aptr[i]->data.score[2] && aptr[i - 1]->data.sum > aptr[i]->data.sum)
					{
						continue;
					}
					NodePtr midptr = (NodePtr)malloc(sizeof(Node));
					memset(midptr, 0, sizeof(Node));
					midptr = aptr[i - 1];
					aptr[i - 1] = aptr[i];
					aptr[i] = midptr;
				}
			}
		}

		for (int i = 1; i <= num; i++)
		{

			if (i == num)
			{
				aptr[i - 1]->next = NULL;
				break;
			}
			aptr[i - 1]->next = aptr[i];
		}
		*ptr = aptr[0];
		//*ptr->next = aptr[0]->next;
	}
}
void sort_page()
{
	printf("\t\t\t************* MANAGEMENT SYSTEM ******************\n"
		"\t\t\t*                                                *\n"
		"\t\t\t*               1  按总成绩正向排序               *\n"
		"\t\t\t*               2  按总成绩逆向排序               *\n"
		"\t\t\t*               3  按语文成绩排序                 *\n"
		"\t\t\t*               4  按数学成绩排序                 *\n"
		"\t\t\t*               5  按英语成绩排序                 *\n"
		"\t\t\t*               6  写入数据库                     *\n"
		"\t\t\t*               7  导出到指定文件                 *\n"
		"\t\t\t*               8  返回上一页面                   *\n"
		"\t\t\t*                                                *\n"
		"\t\t\t****** Capyright @ 2017-9-12 liguangxian *********\n");
}
void sort_choice(Node *header)
{
	processList(header);
	int i;
	while ((i =choice()) != 8)
	{
		switch (i)
		{
		case 1:
			positive_order(&header);
			processList(header);
			break;
		case 2:
			reverse_order(&header);
			processList(header);
			break;
		case 3:
			positive_order_chinese(&header);
			processList(header);
			break;
		case 4:
			positive_order_math(&header);
			processList(header);
			break;
		case 5:
			positive_order_english(&header);
			processList(header);
			break;
		case 6:
			system("cls");
			write_file_memory(header);
			sort_page();
			processList(header);
			
			break;
		case 7:
			system("cls");
			WriteFile(header);
			sort_page();
			processList(header);
			break;
		default:
			printf("Invalid input!\n");
			break;
		}
	}
}
void admin_sign_in()
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
			system("cls");
			navigation();
			insert_data(&header);
			processList(header);
			break;
		case 2:
		{
			system("cls");
			navigation();
			char id[ARRAY_SIZE];
			//char *ch = 0 ;
			fputs("input delete ID:\n", stdout);
			memset(id, 0, sizeof(id));
			scanf("%s", id);
			delete_data(&header, id);
			processList(header);
		}
		break;
		case 3:
			system("cls");
			navigation();
			search_data(&header);
			break;
		case 4:
		{
			system("cls");
			navigation();
			char id[ARRAY_SIZE];
			//char *ch = 0 ;
			fputs("input update ID:\n", stdout);
			memset(id, 0, sizeof(id));
			scanf("%s", id);
			update_data(&header, id);
		}
		break;
		case 5:
			system("cls");
			navigation();
			write_file_memory(header);
			break;
		case 6:
			system("cls");
			navigation();
			WriteFile(header);
			break;
		case 7:
			system("cls");
			navigation();
			read_file();
			break;
		case 8:
			system("cls");
			navigation();
			if (write_list(&header) != 0)
			{
				processList(header);
			}
			break;
		case 9:
			system("cls");
			navigation();
			sort_page();
			sort_choice(header);
			navigation();
			break;
		case 10:
			system("cls");
			navigation();
			list_insert_data(&header);
			processList(header);
			break;
		case 11:
			system("cls");
			navigation();
			format(&header);
			break;
		case 12:
			system("cls");
			navigation();
			format_list(&header);
			printf("Format list successful!\n");
			processList(header);
			break;
		case 13:
		{
			system("cls");
			navigation();
			char id[ARRAY_SIZE];
			//char *ch = 0 ;
			UserData *ud = (UserData*)malloc(sizeof(UserData));
			memset(ud, 0, sizeof(UserData));
			user_write_list(&ud);
			priuserdata(&ud);
			fputs("input update ID:\n", stdout);
			memset(id, 0, sizeof(id));
			scanf("%s", id);
			admin_update(&ud,id);
		}

		default:
			printf("please input choice again!\n");
			break;
		}
	}
	logn();
}
void logn()
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

}
void logn_page()
{
	printf("\t\t\t************* MANAGEMENT SYSTEM *******************\n"
		"\t\t\t*                                                 *\n"
		"\t\t\t*               1  登录                           *\n"
		"\t\t\t*               2  注册                           *\n"
		"\t\t\t*               3  退出程序                       *\n"
		"\t\t\t*                                                 *\n"
		"\t\t\t****** Capyright @ 2017-9-12 liguangxian **********\n");
}
void signup_user_or_admin_page()
{
	printf("\t\t\t************* MANAGEMENT SYSTEM ******************\n"
		"\t\t\t*                                                *\n"
		"\t\t\t*               1  管理员用户注册                 *\n"
		"\t\t\t*               2  普通用户注册                   *\n"
		"\t\t\t*               3  返回上一层                     *\n"
		"\t\t\t*                                                *\n"
		"\t\t\t****** Capyright @ 2017-9-12 liguangxian *********\n");
}
void signin_user_or_admin_page()
{
	printf("\t\t\t************* MANAGEMENT SYSTEM ******************\n"
		"\t\t\t*                                                *\n"
		"\t\t\t*               1  管理员用户登录                 *\n"
		"\t\t\t*               2  普通用户登录                   *\n"
		"\t\t\t*               3  返回上一层                     *\n"
		"\t\t\t*                                                *\n"
		"\t\t\t****** Capyright @ 2017-9-12 liguangxian *********\n");
}
void sign_in()
{
	char name[ARRAY_SIZE];
	char pw[ARRAY_SIZE];
	memset(name, 0, sizeof(name));
	memset(pw, 0, sizeof(pw));
	signin_user_or_admin_page();

	UserData *ud = (UserData*)malloc(sizeof(UserData));
	memset(ud, 0, sizeof(UserData));
	printf("sign in administrator or general user?\n-->");
	user_write_list(&ud);
	priuserdata(&ud);

	int c;
	while ((c = choice()) != 3)
	{
		switch (c)
		{
		case 1:
		{
			printf("please input sign in Admin name:");
			scanf("%s", name);
			printf("please input your password!\n-->");
			scanf("%s", pw);
			int s = search_user_name(&ud, name, pw, c);
			switch (s)
			{
			case 0:
				printf("Account Number no sign up!\n");
				break;
			case 1:
				system("cls");
				printf("Sign in success!\n");
				admin_sign_in();
				break;
			case 2:
				printf("PassWord input is Wrong!\n");
				break;
			}
			system("cls");
			signin_user_or_admin_page();
		}
		break;
		case 2:
		{
			printf("please input sign in user name:");
			scanf("%s", name);
			printf("please input your password!\n-->");
			scanf("%s", pw);
			int s = search_user_name(&ud, name, pw, c);
			switch (s)
			{
			case 0:
				printf("Account Number no sign up!\n");
				break;
			case 1:
				printf("Sign in success!\n");

				//UserData *ud = (UserData*)malloc(sizeof(UserData));
				//memset(ud, 0, sizeof(UserData));
				//user_write_list(&ud);
				general_user(&ud,name);
				break;
			case 2:
				printf("PassWord input is Wrong!\n");
				break;
			}
			system("cls");
			signin_user_or_admin_page();
		}
		break;
		default:
			printf("Invalid input!\n");
			signin_user_or_admin_page();
			break;
		}
	}
	/*printf("Please input your Account Number:-->");
	scanf("%s", name);*/
	logn();

}
void sign_up()
{
	signup_user_or_admin_page();
	char name[ARRAY_SIZE];
	char pw[ARRAY_SIZE];
	memset(name, 0, sizeof(name));
	memset(pw, 0, sizeof(pw));

	UserData * ud = (UserData*)malloc(sizeof(UserData));
	memset(ud, 0, sizeof(UserData));
	printf("sign up administrator or general user?\n-->");
	user_write_list(&ud);
	priuserdata(&ud);

	int c;
	while ((c = choice()) != 3)
	{
		switch (c)
		{
		case 1:
		{
			printf("please input sign up Admin name:");
			scanf("%s", name);
			printf("please input your password!\n-->");
			scanf("%s", pw);
			int u = insert_user(&ud, name, pw, c);
			if (u == 1)
			{
				write_user_memory(&ud);
			}
			priuserdata(&ud);
			signup_user_or_admin_page();
		}
		break;
		case 2:
		{
			printf("please input sign up User name:");
			scanf("%s", name);
			printf("please input your password!\n-->");
			scanf("%s", pw);
			int u = insert_user(&ud, name, pw, c);
			if (u == 1)
			{
				write_user_memory(&ud);
			}
			priuserdata(&ud);
			signup_user_or_admin_page();
		}
		break;
		default:
			printf("Invalid input\n");
			priuserdata(&ud);
			break;
		}
	}
	logn();
}
int insert_user(UserDataPtr *ptr,const char*name, const char*pw, int flag)
{
	UserDataPtr firNode = *ptr;
	UserDataPtr secNode = *ptr;
	UserDataPtr triNode = *ptr;
	UserDataPtr midNode = *ptr;

	//printf("Please input ")
	if (secNode->next != 0 || secNode->name[0] != 0)
	{
		do
		{
			//if (*(secNode->data.id) == *data.id)      *data.id==0;  *(secNode->data.id)==0 equal secNode->data.id[0] equal data.id[0]
			if (strcmp(secNode->name, name) == 0 &&secNode->flag == flag)//peNode->name ==data is error
			{
				printf("\n***************** Account Number Is Exist! ****************\n\n");
				return -1;
			}

			midNode = secNode;
			secNode = secNode->next;
		} while (midNode->next != 0);
	}
	if (firNode->name[0] == 0)
	{
		strcpy(firNode->name, name);
		strcpy(firNode->pw, pw);
		firNode->flag = flag;
		printf("sign up Account number is Accesss!\n");
		return 1;
	}
	else
	{
		while (firNode->next != NULL)
		{
			firNode = firNode->next;

		}
		UserData* pNewNode = (UserData*)malloc(sizeof(UserData));
		memset(pNewNode, 0, sizeof(UserData));
		firNode->next = pNewNode;
		strcpy(pNewNode->name, name);
		strcpy(pNewNode->pw, pw);
		pNewNode->flag = flag;
		printf("sign up Account number is Accesss!\n");
		//Assignment(pNewNode, data);
		return 1;
	}
}
int user_write_list(UserDataPtr *ptr)
{
	FILE *writePtr = 0;
	UserDataPtr firNode = *ptr;
	UserDataPtr secNode = *ptr;
	//Student *data = (Student*)malloc(sizeof(Student));
	//memset(data, 0, sizeof(Student));
	if ((writePtr = fopen(USER_FILE_PATH, "r")) == NULL)
	{
		printf("File could not be opened.\n");
		return 0;
	}

	//Student data = write_data(writePtr);
	int size = file_size(USER_FILE_PATH);
	if (size == 0)
	{
		printf("The User.bat is null!\n");
		return 0;
	}
	int len = (int)size / sizeof(UserData);
	//for (int i = 1; i < len; i++)
	//{
	//	//*ptr->next = pNewNode;
	//	UserData* pNewNode = (UserData*)malloc(sizeof(UserData));
	//	memset(pNewNode, 0, sizeof(UserData));
	//	firNode->next = pNewNode;
	//	firNode = firNode->next;

	//}
	for (int i = 1; i <= len; i++)
	{
		UserData* pNewNode = (UserData*)malloc(sizeof(UserData));
		memset(pNewNode, 0, sizeof(UserData));
		fread(pNewNode, sizeof(UserData), 1, writePtr);
		if (i == 1)
		{
			//user_assignment(secNode);
			 strcpy(secNode->name,pNewNode->name);
			 strcpy(secNode->pw, pNewNode->pw);
			 secNode->flag = pNewNode->flag;
			//free(pNewNode);
			continue;
		}
		//while (firNode->next != NULL)
		//{
		//	secNode = secNode->next;

		//}

		//Node* pNewNode = (Node*)malloc(sizeof(Node));
		//memset(pNewNode, 0, sizeof(Node));
		secNode->next = pNewNode;
		//user_assignment(secNode);
		secNode = secNode->next;
	}
	return 1;
}
void write_user_memory(UserDataPtr *ptr)
{
	FILE *wPtr = 0;
	UserDataPtr uptr = *ptr;
	if ((wPtr = fopen(USER_FILE_PATH, "w+")) == NULL)
	{
		printf("Open file is fail!\n");
		exit(0);
	}
	if (uptr != NULL)
	{
		do
		{
			fwrite(uptr, sizeof(struct _UserData), 1, wPtr);
			uptr = uptr->next;
		} while (uptr!= NULL);
	}
	//fclose(uptr);
	fclose(wPtr);
	printf("Write data to file success!\n");
}
int search_user_name(UserDataPtr *list, char* name, char* pw, int flag)
{
	UserDataPtr curNode = *list;
	if (curNode->name[0] == 0)
	{

		return 0;
	}
	while (curNode != 0)
	{
		if (strcmp(curNode->name, name) == 0 && curNode->flag == flag)
		{
			//priData(&curNode, id);
			if (strcmp(curNode->pw,pw) == 0)
			{
				return 1;
			}
			else
			{
				return 2;
			}

		}
		curNode = curNode->next;
	}
	return 0;
}
void read_file()
{
	FILE *writePtr = 0;
	Node *header = (Node*)malloc(sizeof(Node));
	memset(header, 0, sizeof(Node));
	Student *data = (Student*)malloc(sizeof(Student));
	memset(data, 0, sizeof(Student));
	if ((writePtr = fopen(FILE_PATH, "r")) == NULL)
	{
		printf("File could not be opened.\n");
	}
	//char ch;
	//while ((ch = fgetc(writePtr)) != EOF)
	//{
	//	printf("%c", ch);
	//}

	//fread(&data,sizeof(Student),1,writePtr);
	int size = file_size(FILE_PATH);
	num = (int)size / sizeof(Student);
	printf("Row\tID\tName\tsex\tChinese\tMath\tEnglish\tSum\tAverage\n");
	printf("-----------------------------------------------------------------------\n");
	for (int i = 1; i <= num; i++)
	{
		fread(data, sizeof(Student), 1, writePtr);

		//fprintf();
		printf("%d:\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%.2lf\n", i, data->id, data->name, data->sex == MALE ? "Man" : "Women", data->score[0], data->score[1], data->score[2], data->sum, data->average);

	}
	printf("----------------------------------------------------------------------\n");
	fputs("\n", stdout);
	fclose(writePtr);
}
int file_size(char* filename)
{
	FILE *fp = fopen(filename, "r");
	if (!fp) return -1;
	fseek(fp, 0L, SEEK_END);
	int size = ftell(fp);
	fclose(fp);

	return size;
}
int write_list(NodePtr *ptr)
{
	FILE *writePtr = 0;
	NodePtr firNode = *ptr;
	NodePtr secNode = *ptr;
	Student *data = (Student*)malloc(sizeof(Student));
	memset(data, 0, sizeof(Student));
	if ((writePtr = fopen(FILE_PATH, "r")) == NULL)
	{
		printf("File could not be opened.\n");
		return 0;
	}

	//Student data = write_data(writePtr);
	int size = file_size(FILE_PATH);
	if (size == 0)
	{
		printf("The file.bat is null!\n");
		return 0;
	}
	num = (int)size / sizeof(Student);
	for (int i = 1; i < num; i++)
	{
		//*ptr->next = pNewNode;
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		memset(pNewNode, 0, sizeof(Node));
		firNode->next = pNewNode;
		firNode = firNode->next;

	}
	for (int i = 1; i <= num; i++)
	{
		fread(data, sizeof(Student), 1, writePtr);
		if (i == 1)
		{
			Assignment(*ptr, *data);
			continue;
		}
		//while (firNode->next != NULL)
		//{
		//	secNode = secNode->next;

		//}

		Node* pNewNode = (Node*)malloc(sizeof(Node));
		memset(pNewNode, 0, sizeof(Node));
		secNode->next = pNewNode;
		Assignment(pNewNode, *data);
		secNode = secNode->next;
	}
	return 1;
}
void format(NodePtr *ptr)
{
	FILE *fptr;
	Node *header = (Node*)malloc(sizeof(Node));
	memset(header, 0, sizeof(Node));

	if ((fptr = fopen(FILE_PATH, "w")) != NULL)
	{
		printf("FILE data Format success!\n");
	}
	fclose(fptr);
	write_list(ptr);
	//free(ptr);
	//*ptr = header;
}
void format_list(NodePtr *ptr)
{
	free(*ptr);
	Node *header = (Node*)malloc(sizeof(Node));
	memset(header, 0, sizeof(Node));
	*ptr = header;
}
void priuserdata(UserDataPtr *ptr)
{
		UserDataPtr PriNode = *ptr;
	printf("Row\tName\tpw\tflag\n");
	printf("-----------------------------------------------------------------------\n");
	int i = 1;
	while (PriNode)
	{
		if (PriNode->name[0] == 0)
		{
			printf("----------------------------------------------------------------------\n");
			return;
		}
		printf("%d:\t%s\t%s\t%d\n", i,PriNode->name, PriNode->pw,PriNode->flag);

		PriNode = PriNode->next;
		i++;
	}
	
	printf("----------------------------------------------------------------------\n");
	fputs("\n", stdout);
}
//user  
void admin_update(UserDataPtr *ud,const char* id)
{
	
	printf("sign in administrator or general user?\n-->");
	UserDataPtr ptr = *ud;
	UserDataPtr uptr = *ud;
	
	



	while( ptr!= NULL)
	{
		if (strcmp(ptr->name, id) == 0)
		{
			printf("Update data:Name,PW,flag:-->\n");
			char name[ARRAY_SIZE];
			char pw[ARRAY_SIZE];
			int flag;
			scanf("%s%s%d", name, pw, &flag);
			strcpy(ptr->name, name);
			strcpy(ptr->pw, pw);
			ptr->flag = flag;
			printf("Update seccess!\n");
			write_user_memory(ud);
			priuserdata(ud);
			return 1;
		}
		//priuserdata(&ud);
		
		ptr = ptr->next;
	}
	


	/*if (i == num + 1)
	{
		printf("No Find this name data!\n");
		return -1;
	}    */
}

void general_user(UserDataPtr *ud,char* name)
{
	general_user_page();
	int i;
	while ((i = choice()) != 3)
	{
		switch (i)
		{
		case 1:
			general_user_search(name);
			break;
		case 2:
			general_user_update(ud,name);
			break;
		default:
			printf("Invaled input!\n");
			break;
		}
	}

}
void general_user_page()
{
	printf("\t\t\t************* MANAGEMENT SYSTEM ******************\n"
		"\t\t\t*                                                *\n"
		"\t\t\t*               1  成绩查询                       *\n"
		"\t\t\t*               2  修改信息                       *\n"
		"\t\t\t*               3  返回上一层                     *\n"
		"\t\t\t*                                                *\n"
		"\t\t\t****** Capyright @ 2017-9-12 liguangxian *********\n");
}
void general_user_search(char* name)
{
	Node *header = (Node*)malloc(sizeof(Node));
	memset(header, 0, sizeof(Node));
	write_list(&header);
	/*char id[ARRAY_SIZE];
	fputs("input search id:\n", stdout);
	memset(id, 0, sizeof(id));
	scanf("%s", id);*/
	NodePtr curNode = header;
	if (curNode->data.name[0] == 0)
	{
		printf("System no data!\n");
	}
	while (curNode != 0)
	{
		if (strcmp(curNode->data.id, name) == 0)
		{
			priData(&curNode, name);
			return curNode;
		}
		curNode = curNode->next;
	}
	printf("No search id!\n");
}
 void general_user_update(UserDataPtr *ud, char* name)
{

	UserDataPtr ptr = *ud;
	UserDataPtr uptr = *ud;

	while (ptr != NULL)
	{
		if (strcmp(ptr->name, name) == 0)
		{
			printf("Update data:Name,PW:-->\n");
			char name[ARRAY_SIZE];
			char pw[ARRAY_SIZE];
			int flag;
			scanf("%s%s", name, pw);
			strcpy(ptr->name, name);
			strcpy(ptr->pw, pw);
			//ptr->flag = flag;
			printf("Update seccess!\n");
			write_user_memory(ud);
			priuserdata(ud);
			return 1;
		}
		//priuserdata(&ud);

		ptr = ptr->next;
	}
}