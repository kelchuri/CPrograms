// CTCI_1.8_substring.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"


int len(char *ip)
{
	if(*ip=='\0') return 0;
	else return 1+len(++ip);
}

void append(char* str1,char* str2)
 {
	 while(*str1!='\0')
		 str1++;
	 
	 while(*str2!='\0')
	 {
		 *str1=*str2++;
		 str1++;
	 }
	 *str1='\0';
 }


bool substring(char *str1,char *str2)
{  int len1=len(str1);
   int len2=len(str2);
	int flag=0;
	for(int i=0;i<=len1-len2;i++)
	{
		for(int j=i;j<i+len2;j++)
		{
			flag=1;
			if (str1[j]!=str2[j-i])
			{
				flag=0;
			   break;
			}
		}
		if (flag==1)
			break;
	}
	if (flag==1)
		return true;
	else
		return false;
	

}

void copy(char *input1,char *input2)
{
	while(*input2)
    {
		*input1=*input2++;
		input1++;
	}
	*input1='\0';
}

bool is_substring(char *str1,char *str2)
{
	int leng=len(str1);
	char *str=(char *)malloc(sizeof(char)*(leng+leng+1));
	
	if(leng==len(str2) && len>0)
	{   
		copy(str,str1);
		append(str1,str);
	}
	return substring(str1,str2);
}

int _tmain(int argc, _TCHAR* argv[])
{   
	int len1=100,len2=100;
	char *str1=(char *)malloc(sizeof(char)*(len1+1));
	char *str2=(char *)malloc(sizeof(char)*(len2+1));
	printf("Enter first string\n");
	scanf("%s",str1);
	printf("Enter second string\n");
	scanf("%s",str2);
	printf("%s\n",is_substring(str1,str2)?"It is a substring":"It is not a sub string");
	return 0;
}

