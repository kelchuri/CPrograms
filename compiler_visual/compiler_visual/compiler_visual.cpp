#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<regex>
#include"stdafx.h"
char* remove_spaces(char *arr)
{
	char *a,*b;
	int count=0;
	a=&arr[0];
	b=a;
	for(;*a!='\0';a++)
	{
		if(*a!=' ')
		{
			*b++=*a;
			count++;
		}
	}
	//printf("num of non space letters%d\n",count);
	arr[count]='\0';
	return arr;
}
void type()
{//regex_t re;
//char *spaces="[0-9.]+\s+[0-9]+";
//int pattern=regcomp(&re,spaces);
//printf("%d",pattern);

}

main()
{
char exp[25]=" a =  1   0 ";
char *result=remove_spaces(exp);
printf("%s",*result);
getch();	
}