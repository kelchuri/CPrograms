// prj19.cpp : Defines the entry point for the console application.
// palindromes using two pointers in opp directions

#include "stdafx.h"
#include <string.h>
void palindrome(char *arr)
{
	int l=strlen(arr);
	char *a,*b;
	a=&arr[0];
	b=&arr[l-1];
	int count=0;
	for(int i=0;i<(l/2);i++)
	{
		if(*a==*b)
		{
			count++;
			a++;
			b--;
		}
		else
		{
			printf("not palindrome\n");
			break;
		}
	}
	if(count==(l/2))
		printf("palindromes\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	int len;
	printf("enter length:");
	scanf("%d",&len);
	char *input;
	input=(char *)malloc(sizeof(char)*(len+1));
	printf("enter the string:");
	fflush(stdin);
	scanf("%s",input);
	palindrome(input);
	return 0;
}

