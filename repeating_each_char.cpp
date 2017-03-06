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
{ int len;
	printf("enter length:");
	scanf("%d",&len);
	char *input;
	input=(char *)malloc(sizeof(char)*(len+1));
	printf("enter the string:");
	fflush(stdin);
	scanf("%s",input);
   
  repeat(input,len);
	return 0;
}

