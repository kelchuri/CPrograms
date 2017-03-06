// c-programs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"
#include "string.h"
#include "time.h"

void check_details(char *string);



void concatenate_string(char *original, char *add)
{
   while(*original)
      original++;
 
   while(*add)
   {
      *original = *add;
      add++;
      original++;
   }
   *original = '\0';

}
#define LINES 100
#define MAX 10000
int _tmain(int argc, _TCHAR* argv[])
{   int no_of_lines=0;
int i=0;
	
	char res[LINES][MAX];
	char a='$';
   
   FILE *p = fopen ("schedule.txt", "r" );
   if ( p != NULL )
   {
      char line [ 128 ]; /* or other suitable maximum line size */
      while ( fgets ( line, sizeof line, p ) != NULL ) /* read a line */
      {  
		strcpy(res[no_of_lines],line);

		
		no_of_lines++;
		/*printf("%d",no_of_lines);
		printf("\n");
		*/
      }
	  
   }
   else
   {
      printf("file cannot be opened"); /* why didn't the p open? */
   }
   
  for(i=1;i<no_of_lines;i++)
  {
	 // printf("%s \n",*(res+i));
	  char *tempstring=*(res+i);
	//  printf("%s",tempstring);
	  check_details(tempstring);
  }
return 0;
}

struct place{
	
	
	//tm dep[100][10];
	//tm arr[100][10];
	int flight_as_src;
	int filght_as_dest;
};

void check_details(char *string)
{   struct place place[100];
	int i=0;
	//printf("%s",string);
	char *p=string;
	char temp[100];
	while(*p!=' ')
	{
		temp[i]=*p;
		i++;
		p++;
		break;
	}
	temp[i]='\0';
	printf("%s",temp);
	

}