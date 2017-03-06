// transpose_of_a_matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"


void display(int matrix[100][100],int m,int n)
{   
	int val=0,val1=0;
	if(m>n)
	{
		val=m;
	    val1=n;
	}
	else
	{
		val=n;
	    val1=m;
	}
		for(int i=0;i<val;i++)
	{
		for(int j=0;j<val1;j++)
		{
			printf("%d",matrix[i][j]);
		}
	    printf("\n");
    }
}

void transpose(int matrix[100][100],int rows,int cols)
{
	int temp=0;
	
	for(int i=0;i<=((rows+(cols-rows)));i++)
	{
		for(int j=i+1;j<=((cols));j++)
		{
			if(i!=j)
			{
				temp=matrix[i][j];
			matrix[i][j]=matrix[j][i];
			matrix[j][i]=temp;
			}
		}
	}
	display(matrix,rows,cols);
}



int _tmain(int argc, _TCHAR* argv[])
{    
	int m=0,n=0;
	printf("Enter number of rows:\n");
	scanf("%d",&m);
	printf("Enter number of columns:\n");
	scanf("%d",&n);
	int matrix[100][100];
	printf("Enter the matrix elements(row-wise):\n");
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&matrix[i][j]);
	
	transpose(matrix,m,n);
	return 0;
}

