// str1_23.cpp : Defines the entry point for the console application.
//to lower

#include "stdafx.h"
#include "malloc.h"
char*  tolower(char *ipstr)
{   int i=0;
	while(ipstr[i]!='\0')
	{
	if((int (ipstr[i])>=65) &&(int (ipstr[i])<=90))
	{ipstr[i]=ipstr[i]+32;}
	else
		{ipstr[i]=ipstr[i];}
i++;
}
	return ipstr;
}
int _tmain(int argc, _TCHAR* argv[])
{ 
	char arr[10]={"ABCdEf"};
   printf("%s",tolower(arr));
	return 0;
}

