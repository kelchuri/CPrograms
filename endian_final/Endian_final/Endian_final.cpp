// Endian_final.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
void Endian(int c)
{
FILE *f=fopen("abc.txt","w");
if(f)
{
	size_t n=8*sizeof(unsigned char);
	while(n-->0)
	{ printf("%s \n",((c>>n) &1)?"1":"0");
	fputs(((c>>n) &1)?"1":"0",f);
	}
}
fclose(f);
}

int _tmain(int argc, _TCHAR* argv[])
{ Endian(1);
	return 0;
}

