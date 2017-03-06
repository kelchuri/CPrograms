// circular_single_list.cpp : Defines the entry point for the console application.
//given circular sorted linked list,insert a node into the list and make it the head


#include "stdafx.h"
#include "malloc.h"

typedef struct linked_list{
	//char value[2];
	int value;
	struct linked_list *next;
}node;

node* convert_linked_list(int* input,int len)
{
	node *head,*current,*temp;
	head=NULL;
	temp=NULL;
		
int i=0;
while(i<len)
{
current=(node *)malloc(sizeof(node));
current->value=(input[i++]);
if(head==NULL)
   {
	   head=current;
   }
   else
   {
   temp->next=current;
  }
  temp=current;
}
temp->next=head;
return head;
}

node* insert_node(node* head,int val)
{
	node *current,*temp;
	current=head;
	if(head==NULL)
	{
		head=(node *)malloc(sizeof(node));
		head->value=val;
		head->next=head;
		return head;
	}
	else if(current->value>=val)
	{
		while(current->next!=head)
			current=current->next;
		temp=(node *)malloc(sizeof(node));
		temp->value=val;
		current->next=temp;
		temp->next=head;
		head=temp;
	}
	else
	{
		while((current->next!=head) && (current->next->value<val))
			current=current->next;
		temp=(node *)malloc(sizeof(node));
		temp->value=val;
	    temp->next=current->next;
		current->next=temp;
		
	}
	return head;
}


void display(node* head)
{   node* current=head;
//int count=0;
	while((current->next!=head))
{
	printf("%d \n",current->value);
	current=current->next;
	//count++;
}
	printf("%d\n",current->value);
}


int _tmain(int argc, _TCHAR* argv[])
{   int *number;
int value=0;
int len1;
printf("Enter the length\n");
scanf("%d",&len1);
 printf("Enter the number\n");
 number=(int *)malloc(sizeof(int)*(len1+1));
 for(int i=0;i<len1;i++)
 {
 scanf("%d",&number[i]);
 }
 node* head=convert_linked_list(number,len1);
// display(head);
 printf("Enter the number to be inerted\n");
 scanf("%d",&value);
 node* result=insert_node(head,value);
 display(result);
 return 0;
}

