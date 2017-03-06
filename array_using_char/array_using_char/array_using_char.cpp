// array_using_char.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"
void print(char* str)
{
	int i=0;
while(*(str+i))
{
	printf("%c",*(str+i));
	i++;
}
printf("\n");
}

int _tmain(int argc, _TCHAR* argv[])
{  int len;
printf("enter the length ");
scanf_s("%d",&len);
char *i=(char *)malloc(sizeof(char) *(len+1));
printf("enter the string");
scanf_s("%s",i,len+1);
print(i);
return 0;
}

