// solution_to_problem_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"

void print_dash()
{
	printf("|");
}

void print_line(int column)
{
	for(int i=0;i<((3*column)+(column-1));i++)
		printf("-");
	printf("\n");
}

void mirror_row(char domino[][3],int column)
{
	int col=column, i=0;
	int flag = 0;
	switch(i)
	{
	case 0:
		while(col)
		{
			for(int j=0;j<3;j++)
				printf("%c",domino[i][j]);
			print_dash();
			col--;
		}
		printf("\n");
		col = column;
		i++;
	case 1:
		while(col)
		{
			if(flag==0)
			{
				for(int j=0;j<3;j++)
					printf("%c",domino[i][j]);
				print_dash();
				flag=1;
				col--;
			}
			else
			{
				for(int j=2;j>=0;j--)
					printf("%c",domino[i][j]);
				print_dash();
				flag=0;
				col--;
			}
		}
		printf("\n");
		col = column;
		i++;
	case 2:
		while(col)
		{
			for(int j=0;j<3;j++)
				printf("%c",domino[i][j]);
			print_dash();
			col--;
		}
		printf("\n");
	}
}

void swap(char domino[][3])
{
	char temp=domino[0][1];
	domino[0][1]=domino[2][1];
	domino[2][1]=temp;
}

void mirror_domino(char domino[][3],int row,int column)
{
	while(row)
	{
		mirror_row(domino,column);
		print_line(column);
		row--;
		swap(domino);
	}
	getch();
}

void read_row_column(char domino[][3])
{
	int row, column;
	printf("\nEnter the row");
	scanf("%d",&row);
	printf("enter the column");
	scanf("%d",&column);
	mirror_domino(domino,row,column);
}

void display_single_domino(char domino[][3])
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			printf("%c",domino[i][j]);
		printf("\n");
	}
	read_row_column(domino);
}

void single_domino(char input[])
{    int row,column;
	char domino[3][3]={'.','.','.','.','.','.','.','.','.'};
	for(int i=0;input[i]!='\0';i++)
	{
		if(input[i]=='U')
			domino[0][1]=input[i-1];
		else if(input[i]=='L')
			domino[1][0]=input[i-1];
		else if(input[i]=='R')
			domino[1][2]=input[i-1];
		else if(input[i]=='D')
			domino[2][1]=input[i-1];
	}
	display_single_domino(domino);
}

int _tmain(int argc, _TCHAR* argv[])
{
	char input[20];
	printf("domino describe:");
	scanf("%s",input);
	single_domino(input);
	return 0;
}

