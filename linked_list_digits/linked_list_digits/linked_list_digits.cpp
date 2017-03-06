// linked_list_digits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

typedef struct linked_list{
	//char value[2];
	int value;
	struct linked_list *next;
}node;

node* convert_linked_list(char *input)
{
	node *head,*temp,*temp1;
	head=NULL;
		temp1=NULL;
int i=0;
//head=nodes;

while(*(input+i))
{

temp=(node *)malloc(sizeof(node));
temp->value=*(input+i)-'0';
i++;
if (head==NULL)
{
	head=temp;
}
else
	temp1->next=temp;
temp1=temp;
}
temp1->next=NULL;

return head;


}

node* get_tail(node* head)
{
	while(head)
{
	//printf("%d",head->value);
	head=head->next;
}
	return head;
}


node* adder_with_carry(node *val1,node* val2)
{
	node *head,*temp;
	head=NULL;
	int sum=val1->value+val2->value;
	if(sum>9)
	{
		char* node_val=sum%10;
		head=convert_linked_list(node_val);
	}
	head=convert_linked_list();
	

	return head;
}

//node* adder(node *val1,node *val2)
//{
//	node *head,*temp,*temp1;
//	head=NULL;
//	temp1=NULL;
//	printf("%d %d \n",val1->value,val2->value);
//	int i=0;
//	while (i<4)
//	{
//	temp=(node *)malloc(sizeof(node));
//
//	temp->value=val1->value+val2->value;
//	val1=val1->next;
//	val2=val2->next;
//	if (head==NULL)
//	{
//		head=temp;
//	}
//	else
//	{
//		temp1->next=temp;
//	}
//	temp1=temp;
//	i++;
//	}
//	temp1->next=NULL;
//	
//	
//	
//
//	return head;
//	}

//char* validate(char *input)
//{
//int index=0;
//while(*(input+index))
//{
//	if ((*(input+index)-'0')==0 && index==0)
//	{  *(input+index)=NULL;
//		*(input+index)=*(input+(index+1));
//		index=0;
//	}
//	
//	index++;
//}
//return input;
//}


int _tmain(int argc, _TCHAR* argv[])


{ int length1,length2;
printf("enter the length of the first string");
scanf("%d",&length1);
printf("enter the first string");
char *input1=(char *)malloc(sizeof(char)*(length1+1));
scanf("%s",input1);
printf("enter the length of the second string");
scanf("%d",&length2);
printf("enter the second string");
char *input2=(char *)malloc(sizeof(char)*(length2+1));
scanf("%s",input2);
//char* string=validate(input1);
//printf("%s",string);

//printf("%s $ %s \n",input1,input2);
node* res=convert_linked_list(input1);
node* res1=convert_linked_list(input2);
//printf("%d",res->value);
//printf("  %d  \n",res1->value);
node* head=adder_with_carry(res,res1);
//display(head);




	/*
		int length;
		
	printf("enter the length of the input string");
scanf("%d",&length);
char *input=(char *)malloc(sizeof(char)*(length+1));
	printf("enter the input string(digits)");
	scanf("%s",input);

printf("%s",input);*/


return 0;
}