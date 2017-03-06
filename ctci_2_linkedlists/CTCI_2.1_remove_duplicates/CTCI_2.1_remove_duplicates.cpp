// CTCI_2.1_remove_duplicates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

typedef struct list{
int val;
struct list *next;
}node;

void print_list(node *head)
{
	node *current=head;
	while(current!=NULL || current->next!=head)
	{
		printf("%d\n",current->val);
		current=current->next;
	}
}

void remove_dups(node *head)
{
	if(head==NULL) return ;
	node *current=head;
	node *runner;
	while(current!=NULL)
	{
		runner=current;
		while(runner->next!=NULL)
		{
			if(runner->next->val==current->val) runner->next=runner->next->next;
			else runner=runner->next;
		}
		current=current->next;
	}
}

node* convert_to_list_begin(int num)
{
	node *head,*current,*temp;
	head=NULL;
	temp=NULL;
	while(num>0)
	{
		current=(node *)malloc(sizeof(node));
		current->val=(num%10);
		num=num/10;
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

node* convert_to_list_end(int num)
{
	node *head,*temp1,*temp;
	head=NULL;
	temp1=NULL;
	while(num>0)
	{
		temp=(node *)malloc(sizeof(node));
		temp->val=(num%10);
		num=num/10;
		if(head==NULL) head=temp;
		else temp1->next=temp;
		temp1=temp;
	}
	temp1->next=NULL;
	return head;
}

node* convert_to_list_circular(int num)
{
	node *head,*temp1,*temp;
	head=NULL;
	temp1=NULL;
	while(num>0)
	{
		temp=(node *)malloc(sizeof(node));
		temp->val=(num%10);
		num=num/10;
		if(head==NULL) head=temp;
		else temp1->next=temp;
		temp1=temp;
	}
	temp1->next=head;
	return head;
}

bool delete_node(node* n)
{
	if(n==NULL || n->next==NULL) return false;
	node *next=n->next;
	n->val=next->val;
	n->next=next->next;
	return true;
}

node* partition_around_x_1(node *head,int x)
{
	node *beforestart=NULL;
	node *beforeend=NULL;
	node *afterstart=NULL;
	node *afterend=NULL;
	node *current=head;
	while(current!=NULL)
	{
		node *next=current->next;
		current->next=NULL;
		if(current->val<x)
		{
			if(beforestart==NULL) 
			{
				beforestart=current;
				beforeend=beforestart;
			}
			else
			{
				beforeend->next=current;
				beforeend=current;
			}
		}
		else
		{
			if(afterstart==NULL)
			{
				afterstart=current;
				afterend=afterstart;
			}
			else
			{
				afterend->next=current;
				afterend=current;
			}
		}
		current=next;
	}
	if(beforestart==NULL) return afterstart;
	beforeend->next=afterstart;
	
	return beforestart;
}

node* partition_around_x_2(node *head,int x)
{
	node *beforestart=NULL;
	node *afterstart=NULL;
	node *current=head;
	while(current!=NULL)
	{
		node *next=current->next;
		if(current->val<x)
		{
			current->next=beforestart;
			beforestart=current;
		}
		else
		{
			current->next=afterstart;
			afterstart=current;
		}
		current=next;
	}
	if(beforestart==NULL) return afterstart;
	node *res=beforestart;
	while(beforestart->next!=NULL) beforestart=beforestart->next;
	beforestart->next=afterstart;
	return res;
}

int nth_to_last_recur(node* head,int k)
{
	if(head==NULL) return 0;
	int i=nth_to_last_recur(head->next,k)+1;
	if(i==k) printf("%d\n",head->val);
	return i;
}

node* nth_to_last_iter(node* head,int k)
{
	if(k<=0) return NULL;
	node *p1=head;
	node *p2=head;
	for(int i=0;i<k-1;i++)
	{
		if(p2==NULL) return NULL;
		p2=p2->next;
	}
	if(p2==NULL) return NULL;
	while(p2->next!=NULL)
	{
		p1=p1->next;
		p2=p2->next;
	}
	return p1;
}

node* adder1(node *h1,node *h2,int carry)
{
	if(h1==NULL && h2==NULL && carry==0) return NULL;
	node *result=(node *)malloc(sizeof(node));
	int value=carry;
	if(h1!=NULL) value+=h1->val;
	if(h2!=NULL) value+=h2->val;
	result->val=value%10;
	if(h1!=NULL || h2!=NULL)
	{
		node *more=adder1(h1==NULL?NULL:h1->next,h2==NULL?NULL:h2->next,value>=10?1:0);
		node *temp=result;
		temp->next=more;
		temp=more;
	}
	return result;
}

typedef struct partial{
node *sum;
int carry;
}par_sum;

int len(node *head)
{
	if(head==NULL) return 0;
	else return 1+len(head->next);
}

node* pad_list(node *head,int pad)
{
	node *res=head;
	for(int i=0;i<pad;i++)
	{
		node *temp=(node *)malloc(sizeof(node));
		temp->val=0;
		temp->next=res;
		res=temp;
	}
	return res;
}

node* insertbefore(node *n,int num)
{
	node *temp=(node *)malloc(sizeof(node));
	if(n==NULL)
	{
		temp->val=num;
		n=temp;
		n->next=NULL;
		return n;
	}
	if(n!=NULL)
	{
		
		temp->val=num;
		temp->next=n;
		n=temp;
	}
	return n;
}

par_sum* addListHelper(node *h1,node *h2)
{
	if(h1==NULL && h2==NULL) 
	{
		par_sum *sum=(par_sum *)malloc(sizeof(par_sum));
		sum->carry=0;
		sum->sum=NULL;
		return sum;
	}
	par_sum *sum=addListHelper(h1->next,h2->next);
	int value=sum->carry+h1->val+h2->val;
	node *full_result=insertbefore(sum->sum,value%10);
	sum->sum=full_result;
	sum->carry=value/10;
	return sum;

}
node* adder2(node *h1,node *h2)
{
	int len1=len(h1);
	int len2=len(h2);
	if(len1<len2) h1=pad_list(h1,len2-len1);
	else if(len2<len1) h2=pad_list(h2,len1-len2);
	
	par_sum *sum=addListHelper(h1,h2);
	if(sum->carry==0) return sum->sum;
	else 
	{
		node *res=insertbefore(sum->sum,sum->carry);
		return res;
	}
	

}

node* find_beginning(node *head)
{
	node *slow=head;
	node *fast=head;
	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast) break;
	}
	if(fast==NULL || fast->next==NULL) return NULL;
	slow=head;
	while(slow!=fast)
	{
		slow=slow->next;
		fast=fast->next;
	}
	return fast;
}

bool ispalindrome_iter(node *head)
{
	node *fast=head;
	node *slow=head;
	int arr[10];
	int index=0;
	while(fast!=NULL && fast->next!=NULL)
	{
		arr[index++]=slow->val;
		slow=slow->next;
		fast=fast->next->next;
	}
	index--;
	if(fast!=NULL) slow=slow->next;
	while(slow!=NULL)
	{
		int top=arr[index--];
		if(top!=slow->val) return false;
		slow=slow->next;
	}
	return true;
}



int _tmain(int argc, _TCHAR* argv[])
{   
	int num1=0,num2=0;
	printf("Enter first number \n");
	scanf("%d",&num1);
	node *head=convert_to_list_begin(num1);
	printf("%s\n",ispalindrome_iter(head)?"It is a palindrome":"It is not a palindrome");
	//print_list(find_beginning(head));
	//printf("Enter second number \n");
	//scanf("%d",&num2);
	//node* head1=convert_to_list_begin(num1);
	//node* head2=convert_to_list_begin(num2);
	//print_list(adder2(head1,head2));
	//print_list(head);
	//print_list(head);
	//remove_dups(head);
	//print_list(head);
	//int index=0;
	//printf("Enter the index of the node \n");
	//scanf("%d",&index);
	//nth_to_last_recur(head,index);
	//printf("%d\n",nth_to_last_iter(head,index)->val);
   // int ele=0;
	//printf("Enter the element to be partitioned\n");
	//scanf("%d",&ele);
   //print_list(partition_around_x_1(head,ele));
   //print_list(partition_around_x_2(head,ele));
	return 0;
}

