// word_search_phonemap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

int func_map(int num,int index,char *word,char keys[8][6])
{
	for(int j=0;j<4;j++)
	{
	  if(word[index]==keys[num][j])
		{
			return 1;
		}
	}
	return 0;
					
}


int _tmain(int argc, _TCHAR* argv[])
{   char keys[8][6]={{'a','b','c'},{'d','e','f','g'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},
                      {'w','x','y','z'}};
    char word[100];
	printf("Enter the number\n");
	char *choice=(char *)malloc(100);
	FILE *file;
	char letter;
	int count=0;
	int temp_index=0,index=0,number;
	scanf("%s",choice);
   file=fopen("dict.txt","r");
	    
		 while((letter=fgetc(file))!=EOF)
		         {   
			   while(letter!='\n')
			   {
				word[temp_index++]=letter;
				letter=fgetc(file);
			    }
			index=0;
			count=0;
			word[temp_index]='\0';
			while(*(choice+index)!='\0')
			{
				number=((int)choice[index])-50;
				if(number<2)
				{
					printf("Invalid choice!\n");
					return 0;
				}
				count+=func_map(number,index,word,keys);
			    index++;
		    }
			temp_index=0;
			if(count==(index))
			{
				printf("%s\n",word);
			}
			
		 }
		return 0;
}

