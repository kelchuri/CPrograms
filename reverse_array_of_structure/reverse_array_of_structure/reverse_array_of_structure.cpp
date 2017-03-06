// reverse_array_of_structure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"


typedef struct{
	char name[100];
	int age;
}user;

user* reverse(user* array,int num)
{
	user  *start=array;
	user *end=(array+(num-1));
	user temp;
	while(start<end)
	{
		temp=*start;
		*start=*end;
		*end=temp;
		start++;
		end--;
	}
    return array;
}

void display(user *array,int number)
{   printf("--------------------------------\n");
	for(int index=0;index<number;index++)
	   printf("%s...%d\n",array[index].name,array[index].age);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int number;
	printf("enter the number of records:\n");
	scanf("%d",&number);
	user* struct_array=(user *)malloc(sizeof(user)*number);
	printf("Enter the name,age of each user:\n");
	for(int index=0;index<number;index++)
	{
		scanf("%s %d",&struct_array[index].name,&struct_array[index].age);
	}
	display(struct_array,number);
	user* rev=reverse(struct_array,number);
	display(rev,number);
	return 0;
}

