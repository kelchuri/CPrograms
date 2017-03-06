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
	char arr[10]={"aAZz"};
	printf("%s",change_case(arr));
    return 0;
}


