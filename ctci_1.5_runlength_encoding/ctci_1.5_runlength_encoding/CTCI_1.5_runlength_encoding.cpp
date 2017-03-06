// CTCI_1.5_runlength_encoding.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"
#include "stdlib.h"

int len(char *ip)
{
	if(*ip=='\0') return 0;
	else return 1+len(++ip);
}

int countcompress(char *str)
{
	if(str==NULL) return 0;
	char last=str[0];
	int count=1;
	int size=0;
	char buf[5];
	for(int i=1;str[i]!='\0';i++)
	{
		if(str[i]==last) count++;
		else
		{
			last=str[i];
			size+=1+len(itoa(count,buf,10));
			count=1;
		}
	}
	size+=1+len(itoa(count,buf,10));
	return size;
}

int setindex(char *arr,char temp,int index,int count)
{
	arr[index]=temp;
	index++;
	 char countarr[5];
	 itoa(count,countarr,10);
	 for(int i=0;countarr[i]!='\0';i++)
	 {
		 arr[index++]=countarr[i];
	 }
	 return index;
}

char* compress_string(char *ip)
{
	int size=countcompress(ip);
	if(size>=len(ip)) return ip;
	char *temp=(char *)malloc(sizeof(char)*(size+1));
	int index=0;
	char last=ip[0];
	int count=0;
	for(int i=0;ip[i]!='\0';i++)
	{
		if(ip[i]==last) count++;
		else
		{
			index=setindex(temp,last,index,count);
			last=ip[i];
			count=1;
		}
	}
	index=setindex(temp,last,index,count);
	temp[index]='\0';
	return temp;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int length=0;
	printf("Enter the length of the string\n");
	scanf("%d",&length);
	char *str=(char *)malloc(sizeof(char)*(length+1));
	printf("Enter the string\n");
	scanf("%s",str);
	printf("%s\n",compress_string(str));
	return 0;
}

