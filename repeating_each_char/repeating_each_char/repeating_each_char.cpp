// repeating_each_char.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
void repeat(char *ip,int a)
{
for(int i=0;ip[i]!='\0';i++)
{
 for(int j=0;j<a;j++)
 {
	 printf("%c",ip[i]);
 }
}
}

int _tmain(int argc, _TCHAR* argv[])
{ char arr[10]={"abcd"};
   int n=3;
  repeat(arr,n);
	return 0;
}

