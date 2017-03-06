// int_to_list_q3.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "malloc.h"

typedef struct linked_list{
	//char value[2];
	int value;
	struct linked_list *next;
}node;

node* convert_linked_list(int input)
{
	node *head,*current,*temp;
	head=NULL;
		
int i=0;
while(input>0)
{

current=(node *)malloc(sizeof(node));

 
 current->value=(input%10);
input=input/10;
 
 current->next=NULL;

 if(head==NULL)
   {
	   head=current;
   temp=current;
   }
   else
   {
   current->next=head;
   head=current;
   }





}
return head;
}



int validation(int number)
{   int rem=0;
int count=0;
int flag=0;
	while(number>0)
	{   
		flag=1;
		rem=number%10;
		number=number/10;
		if(rem<=9 && rem>=0)
		{   
			count++;
			
		}
		else
		{
		return 1;
		}
	}
	if (flag==0)
	{
		return -1;
	}
	
		return 0;
	
}

void display(node* head)
{
	while(head)
{
	printf("%d \n",head->value);
	head=head->next;
}

}


int _tmain(int argc, _TCHAR* argv[])


{ 
	int number;
printf("enter the number");
scanf("%ld",&number);

if (validation(number)==1 || validation(number)==-1)
{
	printf("Invalid string!\n");
}
else
{
node* head=convert_linked_list(number);

display(head);
}
return 0;
}

