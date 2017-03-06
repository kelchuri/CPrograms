// single_ll_insert.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

typedef struct list{
int value;
struct list *next;
}node;

node* insert_node(node* head,int length,int val)
{
	node *current,*next,*temp,*end;
	current=head;
	int index=0;
	temp=(node *)malloc(sizeof(node));
	temp->value=val;
	if(head==NULL)
	{
		temp->next=temp;
		head=temp;
		return head;
	}
	if(temp->value<current->value)
	{
		temp->next=current;
		head=temp;
		return head;
	}
    next=current->next;
	while((index<length-1) && (next->value<temp->value))
	{
		current=current->next;
		next=next->next;
		
		index++;
	}
	
	temp->next=current->next;
	current->next=temp;
	return head;
}


node* convert_to_list(int *input,int length)
{
	node *head,*current,*temp,*end;
	head=NULL;
	temp=NULL;
	end=NULL;
int i=0;

while(i<length)
{
current=(node *)malloc(sizeof(node));
current->value=(input[i]);
if(head==NULL)
   {
	   head=current;
   }
   else
   {
   temp->next=current;
  }
  temp=current;
  if(i==(length/2))
	  end=current;
 
  i++;
}
temp->next=end;
return head;
}

void display(node* head,int length)
{   int index=0;
	while(index<=length+1)
{
	printf("%d \n",head->value);
	head=head->next;
	index++;
}
	
}


int _tmain(int argc, _TCHAR* argv[])
{   
	int length=0;
	printf("Enter the length of the array:\n");
	scanf("%d",&length);
	int *input=(int *)malloc(sizeof(int)*(length+1));
	printf("Enter the elements:\n");
	for(int i=0;i<length;i++)
		scanf("%d",&input[i]);
	node *head=convert_to_list(input,length);
	//display(head);
	printf("Enter the value to be inserted:\n");
	int value=0;
	scanf("%d",&value);
	node* res=insert_node(head,length,value);
	display(res,length);
	return 0;
}

