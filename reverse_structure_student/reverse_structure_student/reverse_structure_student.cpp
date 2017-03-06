// reverse_structure_student.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"


typedef struct{
	char name[100];
	int number;
	int marks[100];
}student;

student* reverse(student* array,int num)
{
	student  *start=array;
	student *end=(array+(num-1));
	student temp;
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

void display(student *array,int number)
{   printf("--------------------------------\n");
	for(int index=0;index<number;index++)
	{
	   printf("%s\n",array[index].name);
	   for(int mark=0;mark<array[index].number;mark++)
		   printf("%d..",array[index].marks[mark]);
		printf("\n\n");	
	}	
}

int _tmain(int argc, _TCHAR* argv[])
{
	int number;
	printf("enter the number of records:\n");
	scanf("%d",&number);
	student* struct_array=(student *)malloc(sizeof(student)*number);
	printf("Enter the name and number of subjects for each student:\n");
	for(int index=0;index<number;index++)
	{
		scanf("%s %d",&struct_array[index].name,&struct_array[index].number);
		printf("Enter marks for each subject:\n");
		for(int mark=0;mark<struct_array[index].number;mark++)
			scanf("%d",&struct_array[index].marks[mark]);
	}
	display(struct_array,number);
	student* rev=reverse(struct_array,number);
	display(rev,number);
	return 0;
}



