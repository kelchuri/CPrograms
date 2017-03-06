// left_right_rotate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

int* reverse(int *input,int start_index,int end_index,int len)
{
	int *end=(input+(end_index-1));
	int *start=(input+start_index);
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
{   printf("--------------------------------\n");
	for(int index=0;index<len;index++)
	{
		printf("%d\n",*(input+index));
	}

}


int* left_rotate(int *input,int len,int num)
{
	if(num==0 || num==len)
{
	display(input,len);
}
else if(num>len)
	num=len-num;
reverse(input,0,len,len);
//display(input,len);
reverse(input,0,len-num,len-num);
//display(input,len);
reverse(input,len-num,len,num);
//display(input,len);
return input;
}




int* right_rotate(int *input,int len,int num)
{

if(num==0 || num==len)
{
	display(input,len);
}
else if(num>len)
	num=len-num;
reverse(input,0,len,len);
//display(input,len);
reverse(input,0,num,num);
//display(input,len);
reverse(input,num,len,len-num);
//display(input,len);
return input;
}



int _tmain(int argc, _TCHAR* argv[])
{
	int length=0;
	printf("Enter the length:\n");
	scanf("%d",&length);
	int *input=(int *)malloc(sizeof(int)*(length+1));
	
	printf("Enter the array elements:\n");
	for(int index=0;index<length;index++)
	{
		scanf("%d",&input[index]);
	}
	int num=0;
	printf("Enter the number of elements to be rotated:\n");
	scanf("%d",&num);
	int *result;
	
	int choice=0;
	printf("1.Left Shift\n2.Right Shift\n");
	printf("Enter Your choice:\n");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:result=left_rotate(input,length,num);
		display(result,length);
		break;
	case 2:result=right_rotate(input,length,num);
		display(result,length);
		break;
	default:printf("Enter a valid choice");
	}
	
	
	return 0;
}

