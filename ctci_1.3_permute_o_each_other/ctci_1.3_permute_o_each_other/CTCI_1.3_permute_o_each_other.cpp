// CTCI_1.3_permute_o_each_other.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

int len(char *str)
{
	if(*str==NULL)
		return 0;
	else return 1+len(++str);
}
//ASCII  char set
void sort(char *str)
{
	int num[256],temp,count=0,index=0;
	for(int i=0;i<26;i++)
		num[i]=0;
	for(int i=0;str[i]!='\0';i++)
	{
	temp=str[i]-'a';
	num[temp]++;
	}
	for(int i=0;i<26;i++)
	{  if(num[i]!=0){
		while(count<num[i]){
		    str[index++]=i+'a';
			count++;
		}
		count=0;
	}
	}
	str[index]='\0';
}

bool string_equals(char *str1,char *str2)
{
	char *s1=str1;
	char *s2=str2;
	while(*s1!='\0')
	{
		if(*s1==*s2){
		s1++;
		s2++;
		}
		else return false;
	}
	return true;
}

bool permutation(char *str1,char *str2)
{ 
	if(len(str1)!=len(str2)) return false;
	else
	{
		sort(str1);
		sort(str2);
		if(string_equals(str1,str2))
			return true;
		else return false;
	}

}

int _tmain(int argc, _TCHAR* argv[])
{  int len1=0,len2=0;
   printf("Enter the length of first string\n");
   scanf("%d",&len1);
   printf("Enter the length of the secnd string\n");
   scanf("%d",&len2);
   char *str1=(char *)malloc(sizeof(char)*(len1+1));
   char *str2=(char *)malloc(sizeof(char)*(len2+1));
   printf("Enter the first string\n");
   scanf("%s",str1);
   printf("Enter the second string\n");
   scanf("%s",str2);
   printf("%s\n",permutation(str1,str2)?"true":"false");
	return 0;
}

