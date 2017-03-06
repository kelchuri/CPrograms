// binary_search_in_array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

int* reverse(int *input,int str,int end,int len)
{
	int *begin=(input+(str-1));
	int temp=0;
	int *fin=(input+(end-1));
	for(int index=0;index<=(len/2);index++)
	{ 
		temp=*begin;
		*begin=*fin;
		*fin=temp;
		begin++;
		fin--;

	}
    return input;
}

int binary_search(int *input,int length,int val,int start,int end)
{   
	if(input==NULL)
		return 0;
	int begin=0;
	int fin=length-1;
	int found=0;
	int mid=0;
	int reverse=0;
	while(begin<=fin)
	{
		mid=(begin+fin)/2;
		if(val==input[mid])
			return mid;
		else if((mid>=start) && (mid<=end))
		{
			if(val<input[end])
				fin=start-1;
			else if(val>input[start])
				begin=end+1;
			else if(val<input[mid])
				begin=mid+1;
			else if(val>input[mid])
				fin=mid-1;
		}
		else if(val < input[mid])
			fin=mid-1;
		else if(val > input[mid])
			begin=mid+1;
	}
	
	return 0;
}

void display(int *input,int len)
{   printf("--------------------------------\n");
	for(int index=0;index<len;index++)
	{
		printf("%d\n",*(input+index));
	}

}


int _tmain(int argc, _TCHAR* argv[])
{  
	int *number;
	int pos=0;
    int length=0;
	printf("Enter the length of the array:\n");
	scanf("%d",&length);
	printf("Enter the array elements:\n");
	number=(int *)malloc(sizeof(int)*(length+1));
	for(int i=0;i<length;i++)
		scanf("%d",&number[i]);
	int start=0,end=0;
	printf("Enter the start and end indices:\n");
	scanf("%d %d",&start,&end);
	reverse(number,start,end,(end-start));
	display(number,length);
	int value=0;
	while(1)
	{
		printf("Enter the value to be searched or enter -999 to exit:\n");
	scanf("%d",&value);
	if(value==-999)
		return 0;
	else
		pos=binary_search(number,length,value,(start),(end));
		printf("The position of %d is %d\n",value,pos);
	}
	return 0;
}

