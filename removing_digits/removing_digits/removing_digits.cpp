// prj14.cpp : Defines the entry point for the console application.
// removing spaaces in the string

#include "stdafx.h"
#include <string.h>
char remdigit(char arr)
{
	if(((int (arr))>='a')&&((int (arr))<='z'))
	return arr;
	else return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char arr[20]={"b1a2b3c4a5"};
	int i=0;
	for(i=0;arr[i]!='\0';i++)
	{
		if(remdigit(arr[i])!=0)
	 printf("%c",remdigit(arr[i]));
	}
	return 0;
}