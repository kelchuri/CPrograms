// cats_and_rats.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

void initialize(int *flow_array,int *eaten_rat,int no_of_rats)
{
	for(int i=0;i<no_of_rats;i++)
	{
		flow_array[i]=-1;
		eaten_rat[i]=-1;
	}
}

void cal_start_point(int no_of_rats,int dest)
{
	int start=0;
	int curr_pos=0;
	int *flow_array=(int *)malloc(sizeof(int)*(no_of_rats));
	int *eaten_rat=(int *)malloc(sizeof(int)*no_of_rats);
	int repeat=no_of_rats;
	int value=no_of_rats;
	int count=0;
	int temp=0;
	int flag=0;
	int index=0;
	initialize(flow_array,eaten_rat,no_of_rats);
	start=0;
	while(1)
	{
		start=curr_pos;
		while(repeat>0)
	    {
		while(count!=no_of_rats-1)
		{
			if(start==no_of_rats)
			{
				start=0;
			}
			else if(eaten_rat[start]==0)
				start++;
			else if(eaten_rat[start]!=0)
			{
				start++;
				count++;
			}
		}
		if(start==no_of_rats)
				start=0;
		if(eaten_rat[start]==0)
		{
			while(eaten_rat[start]==0){
				start++;
				if(start==no_of_rats)
					start=0;
		}
		}
		//printf("the index is %d\n",index);
		flow_array[index++]=start;
		eaten_rat[start]=0;
		count=0;
		repeat--;
	}
	if(flow_array[no_of_rats-1]!=dest)
	{   
		
		curr_pos++;
		count=0;
		index=0;
		repeat=no_of_rats;
		initialize(flow_array,eaten_rat,no_of_rats);
	}
	else
	{
		printf("The cat should start at %d position inorder to end at %d position\n",curr_pos,dest);
		printf("The order in which the rats are eaten is:\n");
		for(int i=0;i<no_of_rats;i++)
		{
			printf("%d %d rat\n",i+1,flow_array[i]+1);
		}
		repeat=0;
		break;
	}

	}
		
}

int _tmain(int argc, _TCHAR* argv[])
{   
	int no_of_rats=0;
	printf("Enter the number of rats:\n");
	scanf("%d",&no_of_rats);
	int end=0;
	printf("Enter the destination position of the cat:\n");
	scanf("%d",&end);
	cal_start_point(no_of_rats,end);
	return 0;
}

