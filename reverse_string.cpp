// reverse_string.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
char* reverse1(char *ip)
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
char* reverse(char *ip)
{
char op[10],t;	int a=strlen(ip);
int i,j;
for(i=(a-1),j=0;i>=0,ip[j]!='\0';i--,j++)
{
op[i]=ip[j];
}
op[a]='\0';
for(i=0;op[i]!='\0';i++)
{
	ip[i]=op[i];
}
return ip;
}
int _tmain(int argc, _TCHAR* argv[])
{ char arr[20]={"zyxwvu"};
char arr1[20]={"zyxwvu"};
printf("%s \n",reverse(arr));
printf("%s \n",reverse1(arr1));
return 0;
}
