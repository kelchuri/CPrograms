// removing_duplicates_in_string_q5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"
void remove_dup(char *ip)
{
	
	for(int i=0;ip[i]!='\0';i++)
	{
		for(int j=(i+1);j<(i+2);j++)
		{
			if(ip[i]!=ip[j])
				printf("%c",ip[i]);
		}
		
	}
	printf("\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	int len;
	printf("enter length:");
	scanf("%d",&len);
	char *input;
	input=(char *)malloc(sizeof(char)*(len+1));
	printf("enter the string:");
	fflush(stdin);
	scanf("%s",input);
	remove_dup(input);
	return 0;
}