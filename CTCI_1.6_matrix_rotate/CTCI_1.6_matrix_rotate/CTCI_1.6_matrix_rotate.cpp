// CTCI_1.6_matrix_rotate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void print_matrix(int mat[][4],int n);

void rotate_matrix(int mat[][4],int n)
{
	for(int layer=0;layer<n/2;++layer)
	{
		int first=layer;
		int last=n-1-layer;
		for(int i=first;i<last;++i)
		{
			int offset=i-first;
			int top=mat[first][i];
			mat[first][i]=mat[last-offset][first];
			mat[last-offset][first]=mat[last][last-offset];
			mat[last][last-offset]=mat[i][last];
			mat[i][last]=top;
		}
	}
	print_matrix(mat,n);
}

void print_matrix(int mat[][4],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d \t",mat[i][j]);
		}
		printf("\n");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{    
	int matrix[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	int n=4;
	print_matrix(matrix,n);
	printf("\n\n");
	rotate_matrix(matrix,n);


	return 0;
}

