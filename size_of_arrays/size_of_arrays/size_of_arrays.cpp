// size_of_arrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"
#include "string.h"
void test2()
{
	//heap corruption
char *ar2=(char *)malloc(5);
//strcpy(ar2,"hello w");
strcpy(ar2,"hello world");
//printf("%s\n",ar2);
free(ar2);
}
/*void test1()
{
	//stack corruption 
int value1=-1;
char ar1[5];
strcpy(ar1,"hello world hello world");
printf("value is %d \n",value1);
}
void mutate(char *ipstr)
{
	int i=0;
	while(ipstr[i]!='\0')
	{
		ipstr[i++]='a';
	}
	printf("%s \n",ipstr);
}*/
int _tmain(int argc, _TCHAR* argv[])
{ // test1();
	test2();
	char arr[10]={"hello"};
	char *arr1=(char *)malloc(sizeof(char) *10);
    strcpy_s(arr1,4,"abc");
	char *arr2="hello";
	//constant strings and literals are put in read only location
	printf("strlen %d size is %d:\n",strlen(arr),sizeof(arr));
	printf("strlen %d size is %d:\n",strlen(arr1),sizeof(arr1));
	printf("strlen %d size is %d\n",strlen(arr2),sizeof(arr2));
	//mutate(arr);
	//mutate(arr1);
	//mutate(arr2);
	return 0;
}
//compile time allocation of size of
//strlength at runtime 
