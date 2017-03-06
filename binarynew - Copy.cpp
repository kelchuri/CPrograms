// binary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"
#include "math.h"

void integer(char *i,int l)
{
	int val=0,j,k=0,inter=0;
for(j=l-1,k=0;j>=0,k<l;j--,k++)
{
	inter=(int(*(i+j))-48)*(pow(2.0,k));
		val=val+inter;
				}
printf("the integer values is: %d \n",val);
}
int _tmain(int argc, _TCHAR* argv[])
{
	int len;
	printf("enter length:");
	scanf_s("%d",&len);
	char *i;
	i=(char *)malloc(sizeof(char)*(len+1));
	printf("enter the binary string:");
	fflush(stdin);
	scanf_s("%s",i,len+1);
	integer(i,len);
	return 0;
}
