// str3_23.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
void sort1(char *ip)
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
	while(j<num[i])
	{
		ip[k++]=i+97;
	j++;
	}
j=0;
}

}

int _tmain(int argc, _TCHAR* argv[])
{
	char arr[10]={"zzcsseaaa"};
	char arr1[10]={"abdegch"}; char arr2[10]={"abcdefgh"};
	sort1(arr);
	printf("%s \n",(arr));
	sort1(arr1);
	sort1(arr2);
	int i=0,count=0;
	for(i=0;arr1[i]!='\0';i++)
{
	if(arr1[i]==arr2[i])
		count++;
}
int l1=strlen(arr1);
int l2=strlen(arr2);
if(l1==l2 && count==l1)
	printf("they are anagrams");
else
	printf("they are not anagrams");
	return 0;
}

