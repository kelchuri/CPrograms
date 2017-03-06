// CTCI_1.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

int len(char *str)
{
	if(*str==NULL)
		return 0;
	else return 1+len(++str);
}

bool check_string1(char *ip)
{   
	int temp;
	if(len(ip)>256) return false;
	int char_set[256];
	int length=len(ip);
	for(int i=0;i<length;i++)
	{   
		temp=ip[i]-'a';
		if(char_set[temp]==2) return false;
		char_set[temp]=2;
	}
	return true;
}

bool check_string2(char *ip)
{
	int checker=0;
	int val=0;
	int length=len(ip);
	for(int i=0;i<length;i++)
	{
		val=ip[i]-'a';
		printf("bit moanip:%d ",(checker & (1<<val)));
		if((checker & (1<<val))>0) return false;
		checker|=(1<<val);
		printf(" checker:%d \n",checker);
	}
	return true;
}

// true means all are unique 
int _tmain(int argc, _TCHAR* argv[])
{   
	int length;
	printf("Enter the length\n");
	scanf("%d",&length);
	printf("Enter the string\n");
	char *string=(char *)malloc(sizeof(char)*(length+1));
	scanf("%s",string);
	printf("%s\n",string);
	//printf("%d\n",len(string));
	//printf("%s\n",check_string1(string)?"true":"false");
	printf("%s\n",check_string2(string)?"true":"false");
	return 0;
}

