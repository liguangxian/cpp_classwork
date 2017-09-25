#ifndef _USERFUNCATION_H_
#define USERFUNCATION_H_


void signin_user_or_admin_page();
void signup_user_or_admin_page();
int insert_user(UserDataPtr *ptr, const char*name, const char*pw, int flag);
int user_write_list(UserDataPtr *ptr);
void general_user(UserDataPtr *ud, char* name);
void general_user_search(char* name);
void general_user_update(UserDataPtr *ud, char* name);
void general_user_page();
void admin_update(UserDataPtr *ud, const char* id);
void write_user_memory(UserDataPtr *ptr);
int search_user_name(UserDataPtr *list, char* name, char* pw, int flag);
void priuserdata(UserDataPtr *ptr);
#endif