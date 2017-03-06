// binary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"
#include "math.h"

void base4(char *i,int l)
{
	int val=0,j,k=0,inter=0;
	int res[10];
	for(j=l-1,k=0;j>=0,k<l;j--,k++)
{
	val+=(int(*(i+j))-48)*(pow(2.0,k));
}
k=0;
while(val>0)
{
res[k++]=val%4;
val=val/4;
}
k--;
while(k>=0)
{
printf("%d",*(res+k));
k--;
}
printf("\n");
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
	base4(i,len);
	return 0;
}
