// int_to_binary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ctype.h"

void convert_to_binary(int number)
{   char complement[33];
	long int mask=1<<31;
	int i=0;
	while(i<32){
	if(mask&number)
	{
		complement[i]='1';
	}
	else {
	complement[i]='0';
	}
	number=number<<1;
	i++;
	}
	
	complement[i]='\0';
	printf("%s \n",complement);
}


int _tmain(int argc, _TCHAR* argv[])
{   int number=0;
	printf("Enter an integer");
scanf("%d",&number);
convert_to_binary(number);
	return 0;
}

