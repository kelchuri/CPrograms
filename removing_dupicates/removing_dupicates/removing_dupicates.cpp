// prj18.cpp : Defines the entry point for the console application.
// removing duplicates

#include "stdafx.h"
void dup1(char *arr)
{
	char *a,*b;
	for(int i=0;arr[i]!='\0';i++)
	{
		for(int j=(i+1);j<(i+2);j++)
		{
			if(arr[i]!=arr[j])
				printf("%c",arr[i]);
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char arr[15]={"aaaaabbbbcc"};
	dup1(arr);
	return 0;
}

