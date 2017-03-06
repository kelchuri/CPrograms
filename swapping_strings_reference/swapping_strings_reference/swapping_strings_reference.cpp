// swapping_strings_reference.cpp : Defines the entry point for the console application.
//pass by reference

#include "stdafx.h"


void swap(char **string1,char **string2)
{
	char *temp;
	temp=*string1;
	*string1=*string2;
	*string2=temp;
}

int _tmain(int argc, _TCHAR* argv[])
{   char* input[2];
input[0]="hello";
input[1]="world";

swap(&input[0],&input[1]);
printf("%s\n%s\n",input[0],input[1]);
	return 0;
}

