// palindrome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
char* reverse(char *ip)
{
char op[10],t;	int a=strlen(ip);
int i,j,flag=0;
for(i=(a-1),j=0;i>=0,ip[j]!='\0';i--,j++)
{
t=ip[j];
ip[j]=ip[i];
ip[i]=t;
flag++;
if(flag==(a/2))
	break;
}
ip[a]='\0';
return ip;
}
int _tmain(int argc, _TCHAR* argv[])
{ char arr[20]={"aibohphobia"};
  if(*arr==*reverse(arr))
    printf("the given string is a palindrome");
else
	printf("the given string is not a palindrome");
return 0;
}

