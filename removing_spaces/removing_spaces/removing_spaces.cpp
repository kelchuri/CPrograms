// prj22.cpp : Defines the entry point for the console application.
//removing spaces using 2 pointers

#include "stdafx.h"
void remove(char *arr)
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
	arr[count]='\0';
	printf("%s\n",arr);
}
int _tmain(int argc, _TCHAR* argv[])
{
	char arr[25]={"  a  b   c de  f "};
	remove(arr);
	return 0;
}

