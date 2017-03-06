// linked_list_prob.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"
typedef struct linked_list{
	//char value[2];
	int value;
	struct linked_list *next;
}node;

void remove_loop(node *current,node* head)
{
	node *ptr1,*ptr2;
	ptr1 = head;
   while(1)
   {
     
     ptr2 = current;
     while(ptr2->next != current && ptr2->next != ptr1)
     {
         ptr2 = ptr2->next;
     }
 
     
     if(ptr2->next == ptr1)
        break;
	 else
       ptr1 = ptr1->next;
   }
    ptr2->next = NULL;
	
}
node* detect_loop(node* head,int length)
{ node *current,*next,*temp;
current=head;
next=head;


while (current && next && next -> next) {
current = current -> next;
next = next -> next -> next;

if (current == next) {
remove_loop(current,head);
}
}

return head;
	
}

node* convert_linked_list(int* input,int len,int position)
{
	node *head,*current,*temp,*link;
	head=NULL;
	temp=NULL;
		
int i=0;
while(i<len)
{

current=(node *)malloc(sizeof(node));

 
 current->value=(input[i]);
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
  if(i==(position-1))
	  link=current;
  i++;
}
temp->next=link;
return head;
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
int len1;
printf("Enter the lengths of the arrays\n");
scanf("%d",&len1);
 printf("Enter the number\n");
 number=(int *)malloc(sizeof(int)*(len1+1));
 for(int i=0;i<len1;i++)
 {
 scanf("%d",&number[i]);
 }
 
 int position=0;
 printf("Enter the position to loop:\n");
 scanf("%d",&position);
 node* head=convert_linked_list(number,len1,position);
 node* res=detect_loop(head,len1);
 display(res);
	return 0;
}

