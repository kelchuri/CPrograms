// single_ll_with_twolinks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

typedef struct list{
int value;
struct list *fnext;
struct list *snext;
}node;

void add_links(node* head,int length,node *first)
{   
	int count=0,no_of_links=0;
	
	node *link=head;
no_of_links=length/5;
while(count<(length-4))
{
	if(link->fnext!=NULL)
	{
		link->snext=first;
		link=link->fnext;
		first=first->fnext;
	}	
	count++;
}
	while(count<length)
       {
		link->snext=NULL;
		link=link->fnext;
		count++;
		}

}

node* insert_node(node* head,int length,int val)
{
	node *current,*next,*temp,*first;
	current=head;
	int index=0;
	int found=-1;
	first=NULL;
	temp=(node *)malloc(sizeof(node));
	temp->value=val;
	if(head==NULL)
	{
		temp->fnext=temp;
		temp->snext=NULL;
		head=temp;
		return head;
	}
	if(temp->value<current->value)
	{
		temp->fnext=current;
		temp->snext=current->snext;
		head=temp;
		return head;
	}
    next=current->fnext;
	while((index<(length-1)) && (next->value<temp->value))
	{
		current=current->fnext;
		next=next->fnext;
		index++;
	}
	index=0;
	temp->fnext=current->fnext;
	temp->snext=current->snext;
	current->fnext=temp;
	current->snext=current->fnext->snext;
	node *link=head;
	while(index<length+1)
	{ 
		
		if(index!=0 && (index+1)%5==0){
			first=link;
			break;
		}
		link=link->fnext;
		index++;
	}
		add_links(head,length+1,first);
	return head;
}



node* convert_to_list(int *input,int length)
{
	node *head,*current,*temp,*first;
	head=NULL;
	temp=NULL;
	first=NULL;
int i=0;
int no_of_links=0;
int count=0;
int found=0;
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
   temp->fnext=current;
  }
  temp=current;
  if(i>0 && (i+1)%5==0)
	  first=current;
  i++;
}
temp->fnext=NULL;
add_links(head,length,first);
return head;
}

void display(node* head,int length)
{   int index=0;
	while(index<length)
{
	printf("%d \n",head->value);
	head=head->fnext;
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

