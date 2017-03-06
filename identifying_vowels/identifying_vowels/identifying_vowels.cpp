// identifying_vowels.cpp : Defines the entry point for the console application.
//


//given a dictionary or a set of words, print words haveing all vowels in them 

#include "stdafx.h"



int length_recursion(char *input)
{
	if(*input=='\0')
		return 0;
	else
	{
		
		return 1+length_recursion(++input);
	}
}

void vowels(char *word)
{
	char letter;
	int count_vowels=0;
	
	int len=length_recursion(word);
	for(int index=0;index<len;index++)
	{
		letter=*(word+index);
		if(letter=='a' || letter=='A' || letter=='e' ||letter=='E'  || letter=='i' ||letter=='I' || letter=='o' || letter=='O' || letter=='u' || letter=='U')
		   
			{
				count_vowels++;
		}
		
    }
	if(count_vowels>=5)
	{
		printf("This word %s contains all the vowels\n",word);
	}
	
}

int _tmain(int argc, _TCHAR* argv[])
{   
	char letter;
	char word[100];
	int temp_index=0;
	FILE *f=fopen("dictionary.txt","r");
	while((letter=fgetc(f)) !=EOF)
	{
		//printf("%c",letter);
		if(letter!=',' && letter!='\n')
		{
			word[temp_index++]=letter;

		}
		else
		{
			word[temp_index]='\0';
		vowels(word);
		
		temp_index=0;
		}
	}
		
	
	return 0;
}



