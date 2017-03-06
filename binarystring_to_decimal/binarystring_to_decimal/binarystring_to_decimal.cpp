// binarystring_to_decimal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

int power(int number,int pow)
{
	int result=1;
	for(int time=1;time<=pow;time++)
	{
		result*=number;
	}
	
	return result;
}



int convert_to_decimal(char *input,int length)
{
int result=0;
int temp=length;

for (int index=0;index<length;index++)
{   
	result+=((input[index]-'0')*power(2,(temp-1)));
	temp--;
}

return result;
}

int validate(char *input,int length)
{   int index=0;

while(*(input+index))
	{
		if ((*(input+index)-'0')>1)
		{
			return 1;
		}
		
		
		index++;
	}
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
int length=0;
printf("enter the length of the binary string \n");
scanf("%d",&length);
printf("enter the binary string \n");
char *input=(char *)malloc(sizeof(char)*(length+1));
scanf("%s",input);
if(validate(input,length)==1)
{
	printf("Enter a binary string!\n");
}
else
{
	printf("The Decimal Equivalent is: %d \n",convert_to_decimal(input,length));
}
	return 0;
}

