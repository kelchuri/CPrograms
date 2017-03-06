// duplicates.cpp : Removing duplicates in the given string
//
/*
		Specifications
		--------------
		1.Removal of duplicates and sorting it
		2.String should contain only alphabets
		3.If the string contains both uppercase and lowercase alphabets we consider lowercase alphabets
*/
#include "stdafx.h"
#include "malloc.h"
#include "string.h"

int duplicateRemoval(char *s)
{
	if(s!=NULL)
	{
		int count[30]={0},i=0,j=0;
		while(s[i]!='\0')
		{
			if(s[i]>='a' && s[i]<='z')
			{
				if(count[s[i]-'a']>=1)
					i++;
				else
				{
					s[j] = s[i];
					count[s[i]-'a']++;
					j++;
					i++;
				}
			}
			else if(s[i]>='A' && s[i]<='Z')
			{
				if(count[s[i]-'A']>=1)
					i++;
				else
				{
					s[j] = s[i]+32;
					count[s[i]-'A']++;
					j++;
					i++;
				}
			}
			else
				return 0;
		}
		if(i==0)
			return 0;
		else
		{
			s[j] = 0;
			return j;
		}
	}
	else
	{
		return -1;
	}
}
char * readInput()
{
	char *a;
	int maxlen;
	printf("Enter the maximum size of the string\n");
	scanf("%d",&maxlen);
	a = (char *)malloc(maxlen+1);
	//printf("%d \n",strlen(a));
	printf("Enter a string\n");
	fflush(stdin);										//to clear the standard input
	gets_s(a,maxlen);
  printf("%d \n",strlen(a));
	return a;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char *s;
	int res;
	s = readInput();
	res = duplicateRemoval(s);
	//res = duplicateRemoval(NULL);
	if(res==-1)
		printf("NULL entered\n");
	else if(res==0)
		printf("Invalid string\n");
	else
		printf("After duplicate removal string is %s",s);
	return 0;
}

