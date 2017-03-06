// string_replace.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

char* replace(char *input1,int len1,char *input2,int len2,int start)
{
	char *string;
	string=input1;
	int temp_index=0;
	int second_index=0;
	int index=0;
		while(index<start-1)
		{
			*string=*(input1+index);
			string++;
			temp_index++;
			index++;
		}
		//printf("%d\n",index);
		while(index==(start-1) && second_index<len2)
		{
			*string=*(input2+second_index);
			string++;
			second_index++;
			temp_index++;
		}
		 //printf("%d \n",temp_index);
		input1[temp_index]='\0';
	//printf("%s\n",input1);
    return input1;
}

bool validate(char *input,int length)
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
	int length1=0,length2=0;
	printf("Enter length of the first string:\n");
	scanf("%d",&length1);
	printf("Enter the length of the second string:\n");
	scanf("%d",&length2);
	if(length1<0 || length2<0)
	{
		printf("Provide a valid length");
		return 0;
	}
	char *string1=(char *)malloc(sizeof(char)*(length1+length2+1));
	printf("Enter the first string:\n");
	scanf("%s",string1);
	char *string2=(char *)malloc(sizeof(char)*(length2+1));
	printf("Enter the second string:\n");
	scanf("%s",string2);
	int index=0;
	printf("Enter the index from which the string has to be replaced:\n");
	scanf("%d",&index);
	if(index>length1 || index<0 )
	{
		printf("Provide proper indices\n");
		return 0;
	}
	if(validate(string1,length1) && validate(string2,length2))
	{
	printf("The replaced string is: %s\n",replace(string1,length1,string2,length2,index));
	}
	else
		printf("Invalid string\n");

	return 0;
}

