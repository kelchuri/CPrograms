// vowels_and_consonants.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

void vowels_and_consonants(char *input,int len)
{
	char letter;
	int count_vowels=0;
	int count_consonants=0;
	for(int index=0;index<len;index++)
	{
		letter=*(input+index);
		if(letter=='a' || letter=='A' || letter=='e' ||letter=='E'  || letter=='i' ||letter=='I' || letter=='o' || letter=='O' || letter=='u' || letter=='U')
		    count_vowels++;
		else
			count_consonants++;
    }
	printf("The count of vowels is:%d\nThe count of consonants is:%d\n",count_vowels,count_consonants);
}

int validate(char *input,int len)
{   
	char letter;
	for(int index=0;index<len;index++)
	{
		letter=*(input+index);
		if(letter<'A' || letter>'z')
		  {
			  return 1;
		}
	}
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{   int length=0;
printf("Enter the length of the string:\n");
scanf("%d",&length);
char *input=(char *)malloc(sizeof(char)*(length+1));
printf("Enter the string:\n");
scanf("%s",input);
int valid=validate(input,length);
if(valid==1)
{
	printf("Enter a valid string!\n");
}
else
{
vowels_and_consonants(input,length);
}
	return 0;
}

