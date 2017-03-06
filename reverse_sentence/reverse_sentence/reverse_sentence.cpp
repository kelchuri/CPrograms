// reverse_sentence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

void reverse(char *start,char *end)
{
	char letter;
	
	while(start<end)
	{
		letter=*start;
		*start++=*end;
		*end--=letter;
		
    }
	
}

char* reverse_words(char *input)
{   
	
    if(input == NULL)
        return NULL;

    char *start=input;
	char *end=input;
    while(*end != '\0')
        end ++;
    end--;
    reverse(start, end);
	start=end=input;
    while(*start != '\0')
    {
        if(*start == ' ' || *start == '$')
        {
            start ++;
            end ++;
        }
        else if(*end == ' ' || *end == '\0' || *end == '$')
        {
            reverse(start, --end);
            start = ++end;
        }
        else
        {
            end ++;
        }
    }
	
    return input;

	
}

int _tmain(int argc, _TCHAR* argv[])
{   int length=0;
    printf("Enter the length:\n");
	scanf("%d",&length);
	char *input=(char *)malloc(sizeof(char)*(length+1));
	printf("Enter the string(use '$' in place of ' '):\n");
	scanf("%s",input);
	
	//char input[]="how are you ?";
	
	
	printf("%s\n",reverse_words(input));
	return 0;
}

