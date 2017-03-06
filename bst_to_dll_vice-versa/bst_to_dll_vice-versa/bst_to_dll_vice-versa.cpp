// bst_to_dll_vice-versa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"


typedef struct tree_node{
	int data;
	struct tree_node *lchild;
	struct tree_node *rchild;
}node;


void append(node *root, node *temp)
{
	if (temp->data < root->data)
    {
        if (!root->lchild) { root->lchild = temp; }
        else { append(root->lchild, temp); }
    }
    else
    {
        if(!root->rchild) { root->rchild = temp; }
        else { append(root->rchild, temp); }
    }
}
	
	
node* list_to_tree(node *&head)
{   
	node *root=NULL;
	node *current=head;
	while(current)
	{
		node *next=current->rchild;
		if(!root) root=current;
		else
			append(root,current);
		
      current->lchild = current->rchild = NULL;
      
      current = next;
    }
    return root;
}






void node_to_list(node *root,node *&prev,node *&head)
{
	if(!root)
		return;
	node_to_list(root->lchild,prev,head);
	root->lchild=prev;
	if(prev)
		prev->rchild=root;
	else
		head=root;
	node *right=root->rchild;
	head->lchild=root;
	root->rchild=head;
	prev=root;
	node_to_list(right,prev,head);
}

node* node_to_list(node *root)
{
 node *prev=NULL;
 node *head=NULL;
 node_to_list(root,prev,head);
 return head;
}
node* create(int number)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->data=number;
	temp->lchild=NULL;
	temp->rchild=NULL;
    return temp;
}
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->lchild);
		printf("%d ",root->data);
		inorder(root->rchild);
	}
	
}


node* insert(node *root,int num)
{
	node *current,*prev;
	if(root==NULL)
	{
	 root=create(num);
	}
	else
	{   
		current=root;
		while(current!=NULL)
		{
			if(num<current->data)
			{       
				prev=current;
				current=current->lchild;
			}
			else if(num>current->data)
			{   
				prev=current;
			    current=current->rchild;
			}
			else{
				printf("Cannot Be Inserted !\n");
				break;
			}
		}
		current=create(num);
		if(current->data<prev->data)
			prev->lchild=current;
		else
			prev->rchild=current;
		return root;
	}
}
void display(node* head)
{
	node *current=head;
	while(current!=NULL)
	{
		printf("%d\n",current->data);
		current=current->rchild;
		if(current==head)
			break;
	}

}

int _tmain(int argc, _TCHAR* argv[])
{

	node *root,*head;
	node *res;
	root=NULL;
	int number;
	int count=0;
	do
	{
		printf("Enter the number to be entered and press -999 to exit\n");
		scanf("%d",&number);
		if(number!=-999)
		{
			root=insert(root,number);
			count++;
		}
		else
		{
			printf("Process EXit !\n");
			head=node_to_list(root);
			printf("\n");
			break;
		}
	}while(number!=-999);
	display(head);
	res=list_to_tree(head);
	inorder(res);
	return 0;
}

