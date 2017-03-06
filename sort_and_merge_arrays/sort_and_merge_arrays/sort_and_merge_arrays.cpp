// sort_and_merge_arrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"


void merge_arrays(int *input1,int length1,int *input2,int length2)
{
	int index=length1+length2-1;
	int first=length1-1;
	int second=length2-1;
	while(second>=0)
		{
			if(*(input2+second)>*(input1+first) || first<0)
			{
				*(input1+index)=*(input2+second);
			second--;
			}
			else{
				*(input1+index)=*(input1+first);
				first--;
			}
			index--;
	
	}
	for(int i=0;i<length1+length2;i++)
	{
		printf("%d\n",*(input1+i));
	}
}




int _tmain(int argc, _TCHAR* argv[])
{   int length1=0,length2=0;
	
printf("Enter the length of the first array\n");
scanf("%d",&length1);
printf("Enter the length of the second array\n");
scanf("%d",&length2);
int *input1=(int *)malloc(sizeof(int)*(length1+length2+1));
printf("enter the first array elements\n");
for(int k=0;k<length1;k++)
	{
		scanf("%d",&input1[k]);
	 }

int *input2=(int *)malloc(sizeof(int)*(length2)+1);
printf("enter the second array elements\n");
for(int k=0;k<length2;k++)
	{
		scanf("%d",&input2[k]);
	 }
merge_arrays(input1,length1,input2,length2);

	return 0;
}

