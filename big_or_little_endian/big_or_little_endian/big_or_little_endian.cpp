// big_or_little_endian.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define big 0
#define little 1
int endian() 
{
int word = 0x0001;
char *byte = (char *) &word;
return (byte[0] ? little : big);
}
int _tmain(int argc, _TCHAR* argv[])
{
	int value;    
	value = endian();    
	if (value == 1)   
	printf("Machine is little endian\n");    
	else    
	printf("Machine is Big Endian\n");
	return 0;
}

