#pragma once
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstdbool>
typedef enum _Sex
{
	MALE = 0,
	FEMALE
}Sex;
typedef struct _StructData
{
	char name[256];
	char lastName[15];
	char firstName[10];
	int balance;
	Sex sex;
}Student;
typedef struct _Node
{
	Student data;
	struct _Node* next;

} Node, *NodePtr;
int num = 0;        //定义全局变量
void instructions(void);
void processList(NodePtr header);
void Assignment(Node *pNode, Student data);
int insert_data(NodePtr *curNode);//int key 表示插入的位置，0代表从零位开始插入。
int list_delete_data(NodePtr *ppNode, const char* data);
void WriteFile(NodePtr header);
NodePtr list_find_data(NodePtr *list, const char* name);
void priData(NodePtr *list, const char* name);
int update_data(NodePtr *ptr, const char* name)
{
	NodePtr pNode = *ptr;
	int i;
	for (i = 1; i <= num; i++)
	{


		if (strcmp(pNode->data.name, name) == 0)
		{
			printf("input data:sex,firstName,lastName,balance:\n");
			scanf("%d%s%s%d", &pNode->data.sex, pNode->data.firstName, pNode->data.lastName, &pNode->data.balance);
			priData(&pNode, name);
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
Student AssignData(void);
int main()
{
	Node *header = (Node*)malloc(sizeof(Node));
	memset(header, 0, sizeof(Node));
	int chioce = 1;
	char name[256];
	int num = 0;
	while (chioce != 6)
	{
		// int balance;
		//Sex sex;
		instructions();
		scanf("%d", &chioce);
		//int key = 0;
		switch (chioce)
		{
		case 1:
			//fputs("input name,sex,lastName,firstName,balance,address(代表从第address位开始输入):\n", stdout);
			//scanf("%s%d%s%s%d%d", name, &sex,&lastName,&firstName, &balance, &key);
			insert_data(&header);
			processList(header);
			break;
		case 2:
			fputs("input delete name:\n", stdout);
			memset(name, 0, 256);
			scanf("%s", name);
			list_delete_data(&header, name);
			processList(header);
			break;
		case 3:
		{
			fputs("input find name:\n", stdout);
			memset(name, 0, 256);
			scanf("%s", name);
			NodePtr node = list_find_data(&header, name);
			priData(&node, name);
		}
		//priData(&(findData(&header, name)),name);
		break;
		case 4:
			WriteFile(header);
			break;
		case 5:
			memset(name, 0, 256);
			fputs("input update name:\n", stdout);
			scanf("%s", name);
			update_data(&header, name);
		default:
			printf("Invalid choice.\n\n");
			break;
		}
	}
	return 0;
}
int list_delete_data(NodePtr *ppNode, const char* name)
{
	NodePtr pNode = *ppNode;
	NodePtr preNode = *ppNode;
	if (pNode->next == 0)
	{
		if ((*ppNode)->data.name[0] == 0)
		{
			printf("Sorry system not have this number!\n");
			return -1;
		}
		else if (strcmp(pNode->data.name, name) == 0)
		{
			num--;
			*ppNode = (*ppNode)->next;
			free(pNode);
			Node *again = (Node*)malloc(sizeof(Node));
			memset(again, 0, sizeof(Node));
			*ppNode = again;
			return 1;
		}
	}

	int i = 1;
	do {

		if (strcmp(pNode->data.name, name) == 0)
		{
			if (i == 1)
			{
				num--;
				*ppNode = pNode->next;
				free(pNode);
				break;
			}
			preNode->next = pNode->next;
			/*if (i == 1)
			{
			*ppNode = (*ppNode)->next;

			}
			else
			{
			preNode->next = pNode->next;
			}*/
			//把要删除节点的next赋值给前一个节点
			//if (preNode == 0)//如果是头结点，就更新表头文件
			//{
			//	*ppNode = (*ppNode)->next;
			//}
			//else
			//{
			//	preNode->next = pNode->next;
			//}

			//2.释放要要删除节点的内存
			num--;
			free(pNode);
			break;
		}
		i++;
		preNode = pNode;
		pNode = pNode->next;
	} while (preNode->next != 0);
}
void WriteFile(NodePtr header)
{
	FILE *writePtr = 0;
	if ((writePtr = fopen("K:\\vsfile\\acount.txt", "w+")) == NULL)
	{
		printf("File not be open!");
	}

	rewind(writePtr);
	fprintf(writePtr, "%-10s%-10s%-10s%-10s%-10s%-10s\n", "Acct", "Name", "FirstName", "LastName", "Sex", "Balance");
	for (int i = 1; i <= num; i++)
	{
		fprintf(writePtr, "%-10d%-10s%-10s%-10s%-10s%-10d\n", i,
			header->data.name, header->data.firstName, header->data.lastName, header->data.sex == MALE ? "Man" : "Women", header->data.balance);
		header = header->next;
	}
	printf("write file success!\n");
}
Student AssignData(void)
{

	Node *nptr = (Node*)malloc(sizeof(Node));
	memset(nptr, 0, sizeof(Node));
	fputs("input name,sex(0 is Man ,other is Woman),lastName,firstName,balance:\n", stdout);
	scanf("%s%d%s%s%d", nptr->data.name, &nptr->data.sex, nptr->data.lastName, nptr->data.firstName, &nptr->data.balance);
	return nptr->data;
}
int insert_data(NodePtr *curNode)
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
				printf("name is exit!\n");
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
	strcpy(pNode->data.name, data.name);
	pNode->data.sex = data.sex;
	pNode->data.balance = data.balance;
	strcpy(pNode->data.firstName, data.firstName);
	strcpy(pNode->data.lastName, data.lastName);
}
NodePtr list_find_data(NodePtr *list, const char* name)
{
	NodePtr curNode = *list;
	while (curNode != 0)
	{
		if (strcmp(curNode->data.name, name) == 0)
		{
			return curNode;
		}
		curNode = curNode->next;
	}

}
void processList(NodePtr header)
{
	Node * PriNode = header;
	printf("ID\tname\tsex\tFN\tLN\tbalance\t\n");
	printf("---------------------------------------------------------\n");
	int i = 1;
	while (PriNode)
	{

		printf("%d:\t%s\t%s\t%s\t%s\t%d\t\n", i, PriNode->data.name, PriNode->data.sex == MALE ? "Man" : "Women", PriNode->data.firstName, PriNode->data.lastName, PriNode->data.balance);

		PriNode = PriNode->next;
		i++;
	}
	printf("---------------------------------------------------------\n");
	fputs("\n", stdout);
}
void instructions(void)
{
	printf("Enter your choice:\n"
		"   1 to insert an element into the list.\n"
		"   2 to delete an element from the list.\n"
		"   3 to find name an element from the list.\n"
		"   4 to Write the file.\n"
		"   5.to Update the file!\n"
		"   6.to End(and write file)");
}
void priData(NodePtr *list, const char* name)
{
	NodePtr curNode = *list;
	printf("\tname\tLN\tFN\tsex\tbalance\t\n");
	printf("----------------------------------------------------------------------------------------\n");


	printf("\t%s\t%s\t%s\t%d\t%d\t\n", name, (*list)->data.lastName, (*list)->data.firstName, (*list)->data.sex == MALE ? "Man" : "Women", (*list)->data.balance);


	printf("----------------------------------------------------------------------------------------\n");
	fputs("\n", stdout);
}