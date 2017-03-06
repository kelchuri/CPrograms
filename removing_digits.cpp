// prj14.cpp : Defines the entry point for the console application.
// removing spaaces in the string

#include "stdafx.h"
#include <string.h>
char remdigit(char letter)
{
	if(((int (arr))>='a')&&((int (arr))<='z'))
	return letter;
	else return 0;
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
	int i=0;
	for(i=0;input[i]!='\0';i++)
	{
		if(remdigit(input[i])!=0)
	 printf("%c",remdigit(input[i]));
	}
	return 0;
}