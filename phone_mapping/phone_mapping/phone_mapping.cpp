// phone_mapping.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

char*  tolower(char *ipstr,int len)
{   int i=0;
	while(i<len)
	{
	if((int (ipstr[i])>=65) &&(int (ipstr[i])<=90))
	{ipstr[i]=ipstr[i]+32;}
	else
		{ipstr[i]=ipstr[i];}
i++;
}
	return ipstr;
}

void phone_mapping(char *input,int len)
{
	char letter;
	char *result=tolower(input,len);
	int keys[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
	for(int index=0;index<len;index++)
	{
		letter=*(result+index);
		printf("%d",keys[letter-'a']);
	}
	printf("\n");
}

int validate(char *input,int len)
{   
	char letter;
	for(int index=0;index<len;index++)
	{
		letter=*(input+index);
		if(letter<'A' || letter>'z')
		  {
			  return 1;
		}
	}
	return 0;
}


int _tmain(int argc, _TCHAR* argv[])
{   
	int length=0;
	printf("Enter the length:\n");
	scanf("%d",&length);
	char *input=(char *)malloc(sizeof(char)*(length+1));
	printf("Enter the String:\n");
	scanf("%s",input);
	int valid=validate(input,length);
	if(valid==1)
	{
		printf("Enter a string!\n");
	}
	else
	{
	phone_mapping(input,length);
	}
	return 0;
}

