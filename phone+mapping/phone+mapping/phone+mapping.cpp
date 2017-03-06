// prj21.cpp : Defines the entry point for the console application.
// p

#include "stdafx.h"
void phonemapping(char *arr)
{
	for(int i=0;arr[i]!='\0';i++)
	{
		if((int (arr[i])>='a')&&(int (arr[i])<='c'))
			printf("%d",'a'-'a'+2);
		if((int (arr[i])>='d')&&(int (arr[i])<='f'))
			printf("3");
		if((int (arr[i])>='g')&&(int (arr[i])<='i'))
			printf("4");
		if((int (arr[i])>='j')&&(int (arr[i])<='l'))
			printf("5");
		if((int (arr[i])>='m')&&(int (arr[i])<='o'))
			printf("6");
		if((int (arr[i])>='p')&&(int (arr[i])<='s'))
			printf("7");
		if((int (arr[i])>='t')&&(int (arr[i])<='v'))
			printf("8");
		if((int (arr[i])>='w')&&(int (arr[i])<='z'))
			printf("9");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char arr[15]={"asdfgh"};
	phonemapping(arr);
	return 0;
}

