#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include "userheader.h"


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
void general_user(UserDataPtr *ud, char* name)
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
			general_user_update(ud, name);
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
void admin_update(UserDataPtr *ud, const char* id)
{

	printf("sign in administrator or general user?\n-->");
	UserDataPtr ptr = *ud;
	UserDataPtr uptr = *ud;





	while (ptr != NULL)
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
		printf("%d:\t%s\t%s\t%d\n", i, PriNode->name, PriNode->pw, PriNode->flag);

		PriNode = PriNode->next;
		i++;
	}

	printf("----------------------------------------------------------------------\n");
	fputs("\n", stdout);
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
			strcpy(secNode->name, pNewNode->name);
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
int insert_user(UserDataPtr *ptr, const char*name, const char*pw, int flag)
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
			if (strcmp(secNode->name, name) == 0 && secNode->flag == flag)//peNode->name ==data is error
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
		} while (uptr != NULL);
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
			if (strcmp(curNode->pw, pw) == 0)
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