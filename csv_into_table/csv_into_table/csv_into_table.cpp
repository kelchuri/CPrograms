// csv_into_table.cpp : Defines the entry point for the console application.
//

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

void print_space(int len1,int len2)
{
	for(int i=0;i<(len1-len2);i++)
	{
		printf(" ");
	}
}

void store_details(char name[100][100],int index,int temp,char *word)
{
	int j=0;
	
				while(*(word+j))
				   {
					   name[index][temp++]=*(word+j);
					   j++;
				   }
					name[index][temp++]='\0';   
				   
}

bool validate_word(int field,char *word)
{
	if(field==0 && length_recursion(word)>27)
		return false;
	else if(field==1 && length_recursion(word)>24)
		return false;
	else if(field==2 && length_recursion(word)>10)
		return false;
	else if(field==3 && length_recursion(word)>13)
		return false;
	else 
		return true;
}

void display(char name[100][100],char location[100][100],char pincode[100][100],char phone[100][100],int index)
{    int len1=0,len2=0,len3=0;
	for(int i=0;i<index;i++)
	{
		printf("%s",name[i]);
		len1=length_recursion(name[i]);
		print_space(27,len1);
		printf("%s",location[i]);
		len2=length_recursion(location[i]);
		print_space(24,len2);
		printf("%s",pincode[i]);
		len3=length_recursion(pincode[i]);
		print_space(15,len3);
	    printf("%s",phone[i]);
		printf("\n\n");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{    
	char letter;
	char word[100];
	char Name[100][100],location[100][100], pin_code[100][100],phone_number[100][100];
	FILE *f;
	int index=0;
	int temp_index=0;
	int field=0;
	int i,j;

	f=fopen("csvfile.txt","r");
	while((letter=fgetc(f)) !=EOF)
	{
		if(letter!=',' && letter!='\n')
		{
			word[temp_index++]=letter;

		}
		else
		{   i=0;
			word[temp_index]='\0';
			if(validate_word(field,word))
			{
				switch(field)
			{
			case 0:
				store_details(Name,index,i,word);
				field++;
				break;
			case 1:store_details(location,index,i,word) ;
				field++;
				break;
			case 2:store_details(pin_code,index,i,word);
				field++;
				break;
			case 3:store_details(phone_number,index,i,word);
				field=0;
				index++;
				break;
			}
			temp_index=0;
			}
			else
			{
				printf("Data exceeded the limit!!\n");
				return 0;
			}
		}
	}
	display(Name,location,pin_code,phone_number,index);
	
	return 0;
}

