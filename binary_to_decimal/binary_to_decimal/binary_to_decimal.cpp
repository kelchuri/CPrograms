// binary_to_decimal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

int power(int num,int pow)
{
	int result=1;
	for(int repeat=0;repeat<pow;repeat++)
	{
		result*=num;
	}
	//printf("%d \n",result);
	return result;
}

int convert_to_decimal(int input)
{   
	int rem=0;
	int decimal_no=0;
	int pow=0;
	while(input>0)
	{ 
		rem=input%10;
		decimal_no+=(rem*power(2,pow));
		pow++;
		input=input/10;
	}
	//printf("%d",decimal_no);
	return decimal_no;
}

int validate(int number)
{
	int rem=0;
	while(number>0)
	{
		rem=number%10;
		if(rem>1)
		{
			return 1;
		}
		number=number/10;
	}
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{  
int binary_num=0;
printf("Enter the binary number: \n");
scanf("%d",&binary_num);
int valid=validate(binary_num);
if(valid==1)
{
	printf("Enter a binary string!\n");
}
else{
printf("Th decimal equivalent is:%d \n",convert_to_decimal(binary_num));
}
	return 0;
}

