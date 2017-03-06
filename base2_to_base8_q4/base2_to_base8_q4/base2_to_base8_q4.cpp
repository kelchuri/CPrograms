// base2_to_base8_q4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"
#include "math.h"

void base8(char *i,int l)
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
res[k++]=val%8;
val=val/8;
}
k--;
while(k>=0)
{
printf("%d",*(res+k));
k--;
}
printf("\n");
}
int validate(char *number)
{  int index=0;
	int value;
	while(*(number+index))
	{
		value=(int)*(number+index)-'0';
		printf("%d\n",value);
		if(value!=0 && value!=1)
		{
			return 1;
		}
		else{
			index++;}
	}
	return 0;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int len;
	printf("enter length:");
	scanf_s("%d",&len);
	char *input;
	input=(char *)malloc(sizeof(char)*(len+1));
	printf("enter the binary string:");
	fflush(stdin);
	scanf_s("%s",input,len+1);
	if (validate(input)==1)
	{
		printf("Enter a binary string!\n");
	}
	else{
	base8(input,len);
	}
	return 0;
}
