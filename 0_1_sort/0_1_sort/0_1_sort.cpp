// 0_1_sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

void sort(int input[],int len)

{   


	
	

	int zero_index=0;
	int one_index=(len-1);
	
	int temp=0;
	

	while(zero_index<=one_index)
	{   
		if(*(input+zero_index)==0 && zero_index<one_index)
		{
			
			
			zero_index++;
		}
		else if(*(input+one_index)==1 && one_index>zero_index)
		{
			one_index--;
		}
		if(zero_index<one_index)
		{
			temp=*(input+zero_index);
			*(input+zero_index)=*(input+one_index);
			*(input+one_index)=temp;
		}
		
	}
	for(int i=0;i<len;i++)
	{
		printf("%d",*(input+i));
	}
}


int length_func(int * array)
{
	return (sizeof(array)/sizeof(array)[0]);
}

int _tmain(int argc, _TCHAR* argv[])
{ 

//int length=0;
//printf("Enter the length of the array\n");
//scanf("%d",&length);
//int *input=(int *)malloc(sizeof(int)*(length)+1);
//printf("enter the array to be sorted \n");
//scanf("%d",input);

int input[5]={1,0,1,0,1};
	
sort(input,5);

	return 0;
}

