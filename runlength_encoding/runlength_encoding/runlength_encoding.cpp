// runlength_encoding.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
void encoding(char *ip)
{
int num[26];int i,j=0,s=0;
for(int i=0;i<26;i++)
num[i]=0;
for(i=0;ip[i]!='\0';i++)
{
s=(int (ip[i]))-97;
num[s]=num[s]+1;

}
int k=0;
for(i=0;i<26;i++)
{
	if(num[i]>0)
printf("%c%d",i+97,num[i]);
}
}


int _tmain(int argc, _TCHAR* argv[])
{   char arr[30]={"aaaazzzssdccc"};
    encoding(arr);
	return 0;
}

