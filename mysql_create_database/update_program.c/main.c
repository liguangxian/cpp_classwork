#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//  test program
#define ADDRESS_MAX 100

int main()
{
	//C:\Users\me\Desktop\test.txt
	/*
	test program
	*/
	FILE *readptr;
	FILE *writeptr;
	char *a[1];
	char  b, c;
	char read_c[1]="";
	char source_address[ADDRESS_MAX] = "";
	char target_address[ADDRESS_MAX] = "";
	printf("Please input address path of your want update file:");
	scanf("%s", source_address);
	printf("Please input address path of your want save file:");
	scanf("%s", target_address);
	if ((readptr = fopen(source_address, "r+")) == NULL)
	{
		printf("File not be open!");
		exit(0);
	}
	if ((writeptr = fopen(target_address, "w+")) == NULL)
	{
		printf("File not be open!");
		exit(0);
	}
	fseek(readptr, 0, SEEK_END);
	long int len = ftell(readptr);
	long int raw = 0;
	printf("File length is: %d\n",len);
	fseek(readptr, 0, SEEK_SET);
	int d = 0;
	int e = 0;
	int w = 0;
	while (!feof(readptr))
	{
		
		b = fgetc(readptr);
		
		if (b == '\"')
		{
			int j;
			if ((j = w % 2) == 0)
			{
				int i;
				if ((i = e % 2) == 0)
				{
					d++;
				}
			}
			
		}
		if (d == 1)
		{
	
			if (b == '\n')
			{
				raw++;
			}
			if (b == '\\')
			{
				e++;
			}
			else 
			{
				e = 0;
			}
			a[0] = b;
			fwrite(a, 1, 1, writeptr);
		
		}
		else if (d == 2)
		{
			a[0] = b;
			fwrite(a, 1, 1, writeptr);
			d = 0;
		}
		else
		{
			if (b == '\'')
			{
				w++;
			}
			if (w == 2)
			{
				w = 0;
			}
			if (b == '/')
			{
				if (b == '/'&&c == '/')
				{
					fseek(writeptr, -1, SEEK_END);
					fwrite(read_c, 1, 1, writeptr);
					while (b != '\n' && b!= EOF)
					{
						b = fgetc(readptr);
					}
				}
				
				
			}
			if (b == '*')
			{
				if (b == '*'&&c == '/')
				{
					fseek(writeptr, -1, SEEK_END);
					fwrite(read_c, 1, 1, writeptr);
					b = fgetc(readptr);
					while (b != '/' || c != '*')
					{
						c = b;
						b = fgetc(readptr);
					}
				}
			}
			else
			{

				if (b == '\n')
				{
					raw++;
				}
				a[0] = b;
				fwrite(a, 1, 1, writeptr);
			}
		}
		c = b;
	}
	
	printf("File have %d raw.\n",raw+1);
	fseek(writeptr, 0, SEEK_END);
	long int len1 = ftell(writeptr);
	//long int raw = 0;
	printf("After Update File length is: %d\n", len1);
	fclose(readptr);
	fclose(writeptr);
	return 1;
}