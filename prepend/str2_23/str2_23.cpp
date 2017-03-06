// str2_23.cpp : Defines the entry point for the console application.
//prepend

#include "stdafx.h"
#include "string.h"
void prepend(char *arr1,char *arr2)
{int len1=strlen(arr1);
 int len2=strlen(arr2);
 int l=len1+len2;
 for(int j=l;j>=(len2-1);j--)
 {
	 arr1[j]=arr1[len1];
	len1--;
 }
 int i=0;
 while(i<len2)
 {arr1[i]=arr2[i];
 i++;
 }
 arr1[l++]='\0';
 //printf("%s",arr1);
}

int _tmain(int argc, _TCHAR* argv[])
{char a1[30]={"hello"};
char a2[12]={"helloworld:"};
prepend(a1,a2);
printf("%s",a1);
	return 0;
}

