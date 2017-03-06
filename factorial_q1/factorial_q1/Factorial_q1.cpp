// Factorial_q1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "math.h"

int factorial(int num)
{
	long int fact=1;
	for(int i=1;i<=num;i++)
	{
		fact=fact*i;
	}
	return fact;
}




int _tmain(int argc, _TCHAR* argv[])
{
	
	long int number=0;
	printf("Enter a number(integer):\n ");// if you give a floating point number .. it will take floor of that number
	scanf("%d",&number);
	if(number==0)
	{
		printf("Please enter a valid number! \n");
	}
	else if(number>33)
	{
		printf("Number too big to calculate factorial!\n");
	}
	else
	{
	printf("Factorial of the number is %d \n",factorial(number));
	}
	return 0;
}

