// CTCI_1.4_string_replace.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

void replace_spaces(char *ip,int length)
{
int spacecount=0,newlength,i;
for(int i=0;i<length;i++)
{
	if(ip[i]==' ' || ip[i]=='$')
		spacecount++;
}
newlength=length+spacecount*2;
ip[newlength]='\0';
for(i=length-1;i>=0;i--)
{
	if(ip[i]==' ' || ip[i]=='$'){
		ip[newlength-1]='0';
	    ip[newlength-2]='2';
		ip[newlength-3]='%';
		newlength=newlength-3;
	}
	else{
		ip[newlength-1]=ip[i];
	    newlength--;
}
}
}

int _tmain(int argc, _TCHAR* argv[])
{   int length=0;
printf("Enter the length of the string\n");
scanf("%d",&length);
char *str=(char *)malloc(sizeof(char)*(length+1));
printf("Enter the string\n");

scanf("%s",str);
//fgets(str,length+1,stdin);
printf("%s\n",str);
replace_spaces(str,length);
printf("%s",str);
	return 0;
}

