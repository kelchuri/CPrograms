// product_of_numbers.cpp : Defines the entry point for the console application.
//excluding itself

#include "stdafx.h"
#include "malloc.h"
#include "ctype.h"
void product_of_no(int *input,int len)
{
	int count=0;
	
	int left_product[100];
	int right_product[100];
	while(count<len)
	{
		int p=1;
	for(int index=0;index<count;index++)
	{
		p*=*(input+index);
		
	}
	*(left_product+count)=p;
	//printf("%d ",*(left_product+count));
	p=1;
	for(int index=count+1;index<len;index++)
	{
		p*=*(input+index);
		
	}
	right_product[count]=p;
	//printf("%d ",right_product[count]);
	count++;
	}
	for(int index=0;index<len;index++)
	{
		*(input+index)=(*(left_product+index))*(*(right_product+index));
		printf("%d ",*(input+index));
	}
	
}



int _tmain(int argc, _TCHAR* argv[])
{   
	int length=0;
printf("Enter the length of the array\n");
scanf("%d",&length);
int *input=(int *)malloc(sizeof(int)*(length)+1);
printf("enter the array \n");
for(int k=0;k<length;k++)
	{
		scanf("%d",&input[k]);
	 }

product_of_no(input,length);


	return 0;
}

