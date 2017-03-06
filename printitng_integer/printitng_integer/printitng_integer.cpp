// printitng_integer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void print(int number)
{
	if (number < 0)
    {
        putchar('-');
        number = -number;
    }
    else if (number == 0)
    {
        putchar('0');
        return;
    }   
	if(number>9)
	{
		int temp=number/10;
		number-=10*temp;
		print(temp);
	}
	putchar('0'+number);
	
}

int _tmain(int argc, _TCHAR* argv[])
{   
	int number=0;
	printf("Enter a number\n");
	scanf("%d",&number);
	print(number);
	printf("\n");
	return 0;
}

