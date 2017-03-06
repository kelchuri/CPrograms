// CTCI_1.2_reverse_string.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

void reverse(char *ip)
{
	char *start=ip;
	char *end=ip;
	if(ip)
	{
		while(*end) ++end;
	}
	--end;
	char temp;
	while(start<end)
	{
		temp=*start;
		*start++=*end;
		*end--=temp;
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
	int length=0;
	printf("Enter the lenght of the string:\n");
	scanf("%d",&length);
	printf("Enter the string :\n");
	char *string=(char *)malloc(sizeof(char)*(length+1));
	scanf("%s",string);
	printf("%s\n",string);
	reverse(string);
	printf("%s\n",(string));
	return 0;
}

