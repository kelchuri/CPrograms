// removing_chars.cpp : Defines the entry point for the console application.
//from a given index i to j

#include "stdafx.h"
#include "malloc.h"

char* remove_chars(char *input,int length,int start,int end)
{
	if(start==1 && end==length)
	{
		return "None";
	}
	else
	{
	char *string=input;
	int temp_index=0;
for(int index=0;index<length;index++)
{
	
	if(index<(start-1) || index>=end)
	{
		*string=*(input+index);
		string++;
		temp_index++;
	}
	

}
input[temp_index]='\0';
return input;
	}
}

bool validate(char *input,int length,int start,int end)
{   
	char letter;
	for(int index=0;index<length;index++)
	{ 
		letter=*(input+index);
		if(letter<'A' || letter>'z')
		{
			return false;
		}
	}
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int length=0;
	printf("Enter the length of the string:\n");
	scanf("%d",&length);
	if(length<0)
	{
		printf("Provide a valid length");
	}
	char *string=(char *)malloc(sizeof(char)*(length+1));
	printf("Enter the string:\n");
	scanf("%s",string);
	printf("Enter the start index:\n");
	int start=0;
	scanf("%d",&start);
	int end=0;
	printf("Enter the end index:\n");
	scanf("%d",&end);
	if(start>length || end>length || start<0 || end<0)
	{
		printf("Provide proper indices\n");
		return 0;
	}
	if(validate(string,length,start,end))
	{
		char *result=remove_chars(string,length,start,end);
	if(result=="None")
	{
		printf("All characters have been removed!!\n");
	}
	else
	{
		printf("The string is: %s\n",result);
	}
	}
	else
		printf("Invalid string \n");
	return 0;
}

