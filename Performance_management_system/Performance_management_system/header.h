
#ifndef _HEADER_H_
#define _HEADER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int num;
#define STU 100
#define SUB 3
#define ARRAY_SIZE 20
typedef enum _Sex
{
	MALE = 0,
	FEMALE
}Sex;
typedef struct _StructData
{
	char id[ARRAY_SIZE];
	char name[ARRAY_SIZE];
	int  score[SUB];
	int  sum;
	double  average;
	char passeord[20];
	Sex sex;
}Student;
typedef struct _Node
{
	Student data;
	struct _Node* next;

} Node, *NodePtr;
typedef struct _UserData
{
	char *name[ARRAY_SIZE];
	char *pw[ARRAY_SIZE];
	struct UserData *next;
	int flag;
}UserData,*UserDataPtr;



void sign_in();
void logn_page();
void logn();
void sign_up();
void admin_sign_in();
int insert_user(UserDataPtr *ptr, const char*name, const char*pw, int flag);
int user_write_list(UserDataPtr *ptr);
void write_user_memory(UserDataPtr *ptr);
int search_user_name(UserDataPtr *list, char* name, char* pw, int flag);
void welcome();
void navigation();
int choice();
void processList(NodePtr header);
void WriteFile(NodePtr header);
void write_file_memory(NodePtr header);
int insert_data(NodePtr *nptr);
void Assignment(Node *pNode, Student data);
Student AssignData(void);
int list_insert_data(NodePtr *curNode);
NodePtr search_data(NodePtr *list);
int sum(int a, int b, int c);
void sort_page();
void sort_choice(Node *header);
int delete_data(NodePtr *ppNode, const char* id);
const char* deId();
void format(NodePtr *ptr);
void reverse_order(NodePtr *ptr);
void positive_order(NodePtr *ptr);
void positive_order_chinese(NodePtr *ptr);
void positive_order_math(NodePtr *ptr);
void positive_order_english(NodePtr *ptr);
int update_data(NodePtr *ptr, const char* id);
void priData(NodePtr *list, const char* id);
void read_file();
int file_size(char* filename);
int write_list(NodePtr *ptr);
void admin_sign_in();
void signin_user_or_admin_page();
void signup_user_or_admin_page();
#endif // !_HEADER_H_
