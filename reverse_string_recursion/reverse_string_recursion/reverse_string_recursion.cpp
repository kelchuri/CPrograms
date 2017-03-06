// reverse_string_recursion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

char* recursive_reverse(char *string,int length)
{
	static int index=0;
	static char reverse[100];

	if(*string){
		recursive_reverse(string+1,length);
		reverse[index++]=*string;
		
       }

    return reverse;
}

int length_recursion(char *input)
{
	if(*input=='\0')
		return 0;
	else
	{
		
		return 1+length_recursion(++input);
	}
}
void display(char *input,int len)
{
	for(int index=0;index<len;index++)
	{
		printf("%c",*(input+index));
	}
	printf("\n");
}

bool validate(char *input,int len)
{
	char letter;
	for(int index=0;index<len;index++)
	{
		letter=*(input+index);
		if(letter<'A' || letter>'z')
			return false;
	}
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	static int length=0;
	printf("Enter the length:\n");
	scanf("%d",&length);
	char *input=(char *)malloc(sizeof(char)*(length+1));
	printf("Enter the string :\n");
	scanf("%s",input);
	if(validate(input,length))
	{
		char *result=recursive_reverse(input,length);
	display(result,length);
	int cal_len=length_recursion(input);
	printf("The length of the string is : %d \n",cal_len);
	}
	else
		printf("Invalid string!\n");
	return 0;
}

