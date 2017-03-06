// arrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

void addition(int *i,int *j,int l)
{ int *ans;
	ans=(int*)malloc(sizeof(int) *(l+1));
for(int n=0;n<l;n++)
{
	ans[n]=i[n]+j[n];
	printf("%d\t",*(ans+n));
}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int len;
	printf("enter the length:");
	scanf_s("%d",&len);
	int *i,*j,*ans;
	i=(int*)malloc(sizeof(int) *(len+1));
	j=(int*)malloc(sizeof(int) *(len+1));
	printf("enter the first array:");
	for(int k=0;k<len;k++)
	{
		scanf_s("%d",&i[k]);
	}
	printf("enter the second array:");
	for(int k=0;k<len;k++)
	{
		scanf_s("%d",&j[k]);
	}
	addition(i,j,len);
	return 0;
}

