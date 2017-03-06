// reverse_string_wo_length.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


char* reverse(char* string)
{
	char *start=string;
	char *end=string;
	char temp;
	while(*end!='\0')
		end++;
	end--;
	while(start<end)
	{
		temp=*start;
		*start=*end;
		*end=temp;
		start++;
		end--;
	}
	return string;
}



int _tmain(int argc, _TCHAR* argv[])
{  
	char string[100];
	printf("Enter the string:\n");
	gets(string);

	printf("%s \n",reverse(string));
	return 0;
}

