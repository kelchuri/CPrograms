// repeating_each_char2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
void repeat1(char *ip,int a)
{
	for(int i=0;i<a;i++)
	{
		for(int j=0;ip[j]!='\0';j++)
			printf("%c",ip[j]);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{ int len;
	printf("enter length:");
	scanf("%d",&len);
	char *input;
	input=(char *)malloc(sizeof(char)*(len+1));
	printf("enter the string:");
	fflush(stdin);
	scanf("%s",input);
  repeat1(input,len);
	return 0;
}

