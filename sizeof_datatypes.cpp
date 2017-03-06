// sizeof_datatypes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
void size_of()
{
printf("size of integer is %d \n",sizeof(int));
printf("size of short is %d\n",sizeof(short));
printf("size of short integer is %d\n",sizeof(short int));
printf("size of signed short is %d\n",sizeof(signed short));
printf("size of unsigned short is %d\n",sizeof(unsigned short));
printf("size of signed short integer is %d\n",sizeof(signed short int));
printf("size of unsigned short integer is %d\n",sizeof(unsigned short int));
printf("size of long is  %d\n",sizeof(long));
printf("size of long  integer is  %d\n",sizeof(long int));
printf("size of signed long is  %d\n",sizeof(signed long));
printf("size of unsigned long is  %d\n",sizeof(unsigned long));
printf("size of signed long  integer is  %d\n",sizeof(signed long int));
printf("size of unsigned long  integer is  %d\n",sizeof(unsigned long int));
printf("size of long long is  %d\n",sizeof(long long));
printf("size of long long integer is  %d\n",sizeof(long long int));
printf("size of signed long long is  %d\n",sizeof(signed long long));
printf("size of unsigned long long is  %d\n",sizeof(unsigned long long));
printf("size of signed long long integer is  %d\n",sizeof(signed long long int));
printf("size of unsigned long long integer is  %d\n",sizeof(unsigned long long int));
printf("size of signed integer is  %dn",sizeof(signed));
printf("size of unsigned integer %d \n",sizeof(unsigned));
printf("size of character is %d \n",sizeof(char));
printf("size of signed char is  %d \n",sizeof(signed char));
printf("size of unsigned char  is  %dn",sizeof(unsigned char));
printf("size of float is %d\n",sizeof(float));
printf("size of double is %d \n",sizeof(double));
printf("size of Long double is %d \n",sizeof(long double));
printf("size of boolean is %d \n",sizeof(bool));
}

int _tmain(int argc, _TCHAR* argv[])
{  size_of();
   return 0;
}

