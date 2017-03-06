// addresses3x3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int c[3];
int _tmain(int argc, _TCHAR* argv[])
{
	int a[3][3],b[3];
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%d\t",&a[i][j]);
		}
		printf("\n");
	}
	printf("the local array addresses are \n");
	for(int i=0;i<3;i++)
	{
		printf("%d \n",&b[i]);
	}
	printf("the global array addresses are \n");
	for(int i=0;i<3;i++)
	{
		printf("%d \n",&c[i]);
	}
	return 0;
}
