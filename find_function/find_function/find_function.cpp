// find_function.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"
#include "direct.h"
#include "conio.h"
#include "io.h"
#include "ctype.h"
#include "time.h"

int length_recursion(char *input)
{
	if(*input=='\0')
		return 0;
	else
	{
      return 1+length_recursion(++input);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{   
	int turn=0;
	int number=0,len=100;
	int temp_count=0;
	int index=0,count=0;
	char letter;
	FILE *f;
	char *target=(char *)malloc((len+1));
	printf("Enter the word to be searched!\n");
	scanf("%s",target);
	char   path[100] = "C:\\Users\\kavya\\Documents\\Visual Studio 2012\\Projects\\find_function\\find_function\\words";
struct _finddata_t c_file;
long   hFile;
if(_chdir(path))
printf("Unable to locate the directory: %s\n", path);
else
hFile = _findfirst("*.*", &c_file);
while(_findnext(hFile, &c_file) == 0 )
{
 printf("%s\n", c_file.name);
 if(turn==1)
 {
	 f=fopen(c_file.name,"r");
	 while((letter=fgetc(f)) !=EOF)
		{
			if(letter==*(target+index))
			{
				index++;
			}
			else index=0;
			if(length_recursion(target)==index)
			{
				count++;
				index=0;
			}
	   }
	 if((count-temp_count)!=0)
		{
			printf("Word %s is found in %s file and the count is %d\n",target,c_file.name,(count-temp_count));
	    }
		else
			printf("Word %s is not there in %s file\n",target,c_file.name);
		temp_count=count;
}
turn=1;	
}
printf("Total count of %s word is %d\n",target,count);
_findclose(hFile);
return 0;
}

