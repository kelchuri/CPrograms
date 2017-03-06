// 0_1_2sorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

void sort(int *input,int len)

{   
	int zero_index=0;
	int two_index=(len-1);
	int one_index=1;
	
	int temp=0;
	

	while(one_index<len)
	{   
		
		if(*(input+one_index)==0 && one_index>zero_index)
		{
			temp=*(input+one_index);
			*(input+one_index)=*(input+zero_index);
			*(input+zero_index)=temp;

			zero_index++;
			
		}
		else if(*(input+one_index)==2  && two_index>one_index)
		{
			temp=*(input+one_index);
			*(input+one_index)=*(input+two_index);
			*(input+two_index)=temp;
			two_index--;
		}
		else{
			one_index++;
		}
		}
	for(int i=0;i<len;i++)
	{
		printf("%d",*(input+i));
	}
	
}


int validate(int *input)
{   int index=0;
while(*(input+index))
	{
		if (*(input+index)!=0 && *(input+index)!=1 && *(input+index)!=2)
		{
			return 1;
		}
		index++;
	}
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{ 

int length=0;
printf("Enter the length of the array\n");
scanf("%d",&length);
int *input=(int *)malloc(sizeof(int)*(length)+1);
printf("enter the array(0's 1's 2's) to be sorted \n");
for(int k=0;k<length;k++)
	{
		scanf("%d",&input[k]);
	 }

if(validate(input)==1)
{
	printf("please enter a valid array!!");
}
else
{
	sort(input,length);
}
	return 0;
}


