// change_case.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"
char*  change_case(char *ipstr)
{ int i=0;
	while(ipstr[i]!='\0')
	{
	if((int (ipstr[i])>=65) &&(int (ipstr[i])<=90))
	{ ipstr[i]=ipstr[i]+32; }
	else
	{	ipstr[i]=ipstr[i]-32; }
	i++;
}
	return ipstr;
}
int _tmain(int argc, _TCHAR* argv[])
{ 
	int len;
	printf("enter length:");
	scanf("%d",&len);
	char *input;
	input=(char *)malloc(sizeof(char)*(len+1));
	printf("enter the string:");
	fflush(stdin);
	scanf("%s",input);
	printf("%s",change_case(input));
    return 0;
}


