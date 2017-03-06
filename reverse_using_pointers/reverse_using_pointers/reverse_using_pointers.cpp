// prj20.cpp : Defines the entry point for the console application.
// revesing sting using two pointers

#include "stdafx.h"
#include <string.h>
void reverse(char *arr)
{
	int l=strlen(arr);
	char *a,*b;
	a=&arr[0];
	b=&arr[l-1];
	char temp;
	for(int i=0;i<(l/2);i++)
	{
		temp=*a;
		*a=*b;
		*b=temp;
		a++;
		b--;
	}
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	char arr[20]={"abcdefghi"};
	reverse(arr);
	printf("%s",arr);
	return 0;
}

