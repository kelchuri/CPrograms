// tree_inorder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "math.h"
#include "malloc.h"

typedef struct tree
{
	int data;
	struct tree *parent;
	struct tree *lchild;
	struct tree *rchild;
}tree_node;

void inorder(tree_node *head)
{
	if(head!=NULL)
	{
		inorder(head->lchild);
		printf("%d ",head->data);
		inorder(head->rchild);
	}
	
}

tree_node* create(int number)
{
	tree_node *temp;
	temp=(tree_node *)malloc(sizeof(tree_node));
	temp->data=number;
	temp->lchild=NULL;
	temp->rchild=NULL;
	temp->parent=NULL;
	return temp;
}

tree_node* insert(tree_node *head,int num)
{
	tree_node *current,*prev;
	if(head==NULL)
	{
	 head=create(num);
	}
	else
	{   
		current=head;
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
		return head;
	}
}
int depth_node(tree_node *head)
{
	int left=0,right=0;
	if(head==NULL)
		return 0;
	
	left=depth_node(head->lchild)+1;
	right=depth_node(head->rchild)+1;

	
	if(left>right)
		return left;
	else
		return right;
}

int print(tree_node *tree, int is_left, int set_w, int depth, char s[30][300])
{
    char b[20];
    int width = 5;

    if (!tree) return 0;

	sprintf(b, "(%03d)", tree->data);

	int left  = print(tree->lchild,  1, set_w,depth + 1, s);
	int right = print(tree->rchild, 0, set_w + left + width, depth + 1, s);

#ifdef CONSTRUCT
    for (int i = 0; i < width; i++)
        s[depth][set_w + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[depth - 1][set_w + left + width/2 + i] = '-';

        s[depth - 1][set_w + left + width/2] = '.';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[depth - 1][set_w - width/2 + i] = '-';

        s[depth - 1][set_w + left + width/2] = '.';
    }
#else
    for (int i = 0; i < width; i++)
        s[2 * depth][set_w + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][set_w + left + width/2 + i] = '-';

        s[2 * depth - 1][set_w + left + width/2] = '|';
        s[2 * depth - 1][set_w + left + width + right + width/2] = '|';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][set_w - width/2 + i] = '-';

        s[2 * depth - 1][set_w + left + width/2] = '|';
        s[2 * depth - 1][set_w - width/2 - 1] = '|';
    }
#endif

    return left + width + right;
}



int _tmain(int argc, _TCHAR* argv[])
{   
	tree_node *head;
	head=NULL;
	int number;
	char s[30][300];
	FILE *file;
	file=fopen("tree.txt","a+");
	//head=(tree_node *)malloc(sizeof(tree_node));
	do
	{
		printf("Enter the number to be entered and press -999 to exit\n");
		scanf("%d",&number);
		if(number!=-999)
			head=insert(head,number);
		else
		{
			printf("Process EXit !\n");
			inorder(head);
			printf("\n");
			break;
		}
	}while(number!=-999);
	int depth=depth_node(head);
	for (int i = 0; i < 30; i++)
        sprintf(s[i], "%80s", " ");
	print(head,0,0,0,s);
	for (int i = 0; i < 30; i++)
	{
        printf("%s\n", s[i]);
		
		fprintf(file,"%s",s[i]);
		fprintf(file,"\n");
	}	
	
	return 0;
}

