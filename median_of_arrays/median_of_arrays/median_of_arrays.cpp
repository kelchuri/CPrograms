// median_of_arrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

int* merge_arrays(int *ip1,int len1,int *ip2,int len2)
{
	int index=len1+len2-1;
	int first=len1-1;
	int second=len2-1;
	while(second>=0)
		{
			if(*(ip2+second)>*(ip1+first) || first<0)
			{
				*(ip1+index)=*(ip2+second);
			second--;
			}
			else{
				*(ip1+index)=*(ip1+first);
				first--;
			}
			index--;
	
	}
	for(int i=0;i<len1+len2;i++)
	{
		printf("%d\n",*(ip1+i));
	}
	return ip1;
}

float calculate_median(int *input1,int len1,int *input2,int len2)
{   

	int *result=merge_arrays(input1,len1,input2,len2);
	int middleValue=0;
	 middleValue = (len1+len2)/2;
    if ((len1+len2) % 2 == 1)
        return (float)result[middleValue];
    else
        return (float)(result[middleValue] + result[middleValue - 1]) / 2;
}


int _tmain(int argc, _TCHAR* argv[])
{   
	int length1=0,length2=0;
	
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
printf("The median is: %f\n",calculate_median(input1,length1,input2,length2));


	return 0;
}

