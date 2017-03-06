// merging_sorted_linked_lists.cpp : Defines the entry point for the console application.
//

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
//input=input/10;
 
// current->next=NULL;

 if(head==NULL)
   {
	   head=current;
   //temp=current;
   }
   else
   {
   temp->next=current;
  }
  temp=current;
}
temp->next=NULL;
return head;
}

node* merge_lists(node* head1,node* head2)
{
	node *current,*next;
	current=head1;
	int temp=0;
	while(current!=NULL && current->next!=NULL)
	{
		//flag=1;
		current=current->next;
	}
	
		if(current==NULL)
			current=head2;
		else
			current->next=head2;
	
	current=head1;
	while(current!=NULL && current->next!=NULL)
	{ 
		next=current->next;
		while(next->next!=NULL)
		{ //  flag1=1;
			if(current->value>next->value)
			{
				temp = current->value;
                current->value = next->value;
                next->value = temp;
			}
			next=next->next;
		}
		current=current->next;

	}
	
		if(current==NULL)
            return head2;
        else
            return head1;
	
	
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
{   int *number,*number1;
int len1,len2;
printf("Enter the lengths of the arrays\n");
scanf("%d,%d",&len1,&len2);
 printf("Enter the number\n");
 number=(int *)malloc(sizeof(int)*(len1+1));
 for(int i=0;i<len1;i++)
 {
 scanf("%d",&number[i]);
 }
 printf("Enter the second number\n");
 number1=(int *)malloc(sizeof(int)*(len2+1));
 for(int i=0;i<len2;i++)
 {
 scanf("%d",&number1[i]);
 }
 node* head=convert_linked_list(number,len1);
 //display(head);
 node* head1=convert_linked_list(number1,len2);
 //display(head1);
 node* result=merge_lists(head,head1);
 display(result);
	return 0;
}

