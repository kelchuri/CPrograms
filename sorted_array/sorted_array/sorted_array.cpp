// sorted_array.cpp : Defines the entry point for the console application.
//given an array of len n is sorted and a part of it is reversed,fix it

#include "stdafx.h"
#include "malloc.h"

void reverse(int *start,int *end)
{
	int number;
	
	while(start<end)
	{
		number=*start;
		*start++=*end;
		*end--=number;
		
    }
	
}




int* sorted_array(int *input,int len)
{   
	int *current=(input+1);
	int *previous=input;
	int *temp_begin;
	int *temp_end;
	int index=0;
	int flag=0;
	while(index<len)
	{
		if(*current<=*previous && flag==0)
		{
			flag=1;
			temp_begin=previous;
		}
		else if(flag==1 && ((*current>*previous)|| index==(len-1)))
		{
			temp_end=previous;
			break;
		}
		
		
		current++;
		previous++;
		index++;
		

	}
	reverse(temp_begin,temp_end);
	return input;
}

void display(int *input,int len)
{
	for(int index=0;index<len;index++)
	{
		printf("%d  ",*(input+index));
	}
	printf("\n");
}


int _tmain(int argc, _TCHAR* argv[])
{
    int length=0;
	printf("Ener the length of array:\n");
	scanf("%d",&length);
	int *input=(int *)malloc(sizeof(int)*(length+1));
	printf("Enter the array elements(only numbers):\n");
	for(int index=0;index<length;index++)
	{
		scanf("%d",&input[index]);
	}
	int *result=sorted_array(input,length);
	display(result,length);
	return 0;
}

