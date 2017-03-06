// row_or_coloumn.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

 

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[2][2],*ad[4],flag=0;
	int k=0;
	for(int i=0;i<2;i++)
	{
	for (int j=0;j<2;j++) 
     {
      ad[k++]=&arr[i][j];
	 } 
	}
	while(k<3)
	{
     if(ad[k]<ad[k+1])
	 { 
		 flag++;
	 }
	     k++;
	 }
	if(flag==3)
		printf("Elements are in row order \n");
	else
	printf("Elements are in column order \n");

   return 0;
}

