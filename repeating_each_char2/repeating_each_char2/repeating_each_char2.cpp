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
{ char arr[10]={"abcd"};
  int n=5;
  repeat1(arr,n);
	return 0;
}

