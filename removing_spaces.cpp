// prj22.cpp : Defines the entry point for the console application.
//removing spaces using 2 pointers

#include "stdafx.h"
void remove(char *ip)
{
	char *a,*b;
	int count=0;
	a=&arr[0];
	b=a;
	for(;*a!='\0';a++)
	{
		if(*a!=' ')
		{
			*b++=*a;
			count++;
		}
	}
	//printf("num of non space letters%d\n",count);
	ip[count]='\0';
	printf("%s\n",ip);
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
	remove(input);
	return 0;
}

