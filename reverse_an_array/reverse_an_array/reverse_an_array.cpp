// reverse_an_array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

int* reverse_array(int *input,int len)
{
	int *end=(input+(len-1));
	int *start=(input+0);
	int temp=0;
	for(int repeat=0;repeat<(len/2);repeat++)
	{
		temp=*start;
		*start=*end;
		*end=temp;
		start++;
		end--;
	}
	return input;
}

void display(int *input,int len)
{
	for(int index=0;index<len;index++)
	{
		printf("%d\n",*(input+index));
	}
}

int _tmain(int argc, _TCHAR* argv[])
{  
	int length=0;
	printf("Enter the length of the array:\n");
	scanf("%d",&length);
	int *input=(int *)malloc(sizeof(int)*(length+1));
	printf("enter the array to be reversed:\n");
	for(int index=0;index<length;index++)
	{
		scanf("%d",&input[index]);
	}
	//display(input,length);
	int *result=reverse_array(input,length);
	display(result,length);
	return 0;
}

