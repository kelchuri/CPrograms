// string_to_list_q2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"
#include "ctype.h"

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

int validation(char *string)
{   int i=0;
int count=0;
	while(*(string+i))
	{   int value=(int)*(string+i)-'0';
		if(value<=9 && value>=0)
		{   
			count++;
			i++;
		}
		else
		{
			
			i++;
		}
	}
	if (count==i)
		return 0;
	else
		return 1;
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


{ int length;
printf("enter the length of the string");
scanf("%d",&length);
printf("enter the string");
char *input=(char *)malloc(sizeof(char)*(length+1));
scanf("%s",input);
printf("%s\n",input);
if (validation(input)==1)
{
	printf("Invalid string!\n");
}
else
{
node* head=convert_linked_list(input);

//display(head);
}
return 0;
}

