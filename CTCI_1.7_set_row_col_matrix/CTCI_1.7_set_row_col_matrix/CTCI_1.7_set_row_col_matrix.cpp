// CTCI_1.7_set_row_col_matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void print_matrix(int mat[][4],int row,int col)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			printf("%d \t",mat[i][j]);
		}
		printf("\n\n");
	}

}

void set_matrix(int mat[][4],int row,int col)
{
	int val=row*col,i=0;
	int rows[16];
	int cols[4];
	for(i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(mat[i][j]==0)
			{
				rows[i]=2;
				cols[j]=2;
			}
		}
	}
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(rows[i]==2 || cols[j]==2) mat[i][j]=0;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{   
	int matrix[4][4]={{1,2,3,0},{0,6,7,8},{9,10,11,12},{13,14,15,16}};
	int rows=4;

	int cols=4;
	print_matrix(matrix,rows,cols);
	printf("\n\n");
	set_matrix(matrix,rows,cols);
	print_matrix(matrix,rows,cols);
	return 0;
}

