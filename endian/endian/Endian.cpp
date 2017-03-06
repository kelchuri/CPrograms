// Endian.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
void endian()
{ int a=0x0001;
char *b = (char *) &a;
b[0]?printf("little endian"):printf("big endian");
}

int _tmain(int argc, _TCHAR* argv[])
{ 
	endian();
	return 0;
}

