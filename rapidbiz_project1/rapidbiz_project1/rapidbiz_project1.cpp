//// rapidbiz_project1.cpp : Defines the entry point for the console application.
////
//
//#include "stdafx.h"
//#include "malloc.h"
//
//
////char* sort_string(char *sentence)
////{   
////	int flag=0;
////	
////	int i=0,j=0;
////	char *start=sentence;
////	char *end=sentence;
////	char temp1[100],temp2[100];
////	while(*start!='\0')
////	{
////		if(*start==' ')
////		{
////			start++;
////			end++;
////		}
////		else if(*end==' ' || *end=='\0')
////		{
////			end++;
////			flag++;
////			//compare_strings(start,end);
////			//start=end;
////		}
////		else if(flag==0)
////		  {
////			  temp1[i++]=*end++;
////		}
////		else if(flag==1)
////		{
////			temp1[i]='\0';
////			temp2[j++]=*end++;
////		}
////		else if(flag==2)
////		{
////			temp2[j]='\0';
////			compare_strings(temp1,temp2);
////			i=j=0;
////			flag=0;
////		}
////	}
////	//return sentence;
////}
//void swap(char **string1,char **string2)
//{
//	char *temp;
//	temp=*string1;
//	*string1=*string2;
//	*string2=temp;
//}
//
//void compare_strings(char* begin,char* end)
//{
//	if(*begin>*end)
//	{  
//		swap(&begin,&end);
//	}
//	else 
//	{
//		if(*begin==*end)
//	    {
//		compare_strings(++begin,++end);
//	    }
//	}
//}
//
//
//void append(char *input1,char *input2)
//{
//	while(*input2)
//    {
//		*input1=*input2++;
//		input1++;
//	}
//	*input1='\0';
//}
// void sort_sentence(char words[100][100], int number)
// {
//	 for(int i=0;i<=number;i++)
//		 for(int j=i+1;j<=number;j++)
//		 {   
//			// printf("%s %s"
//			compare_strings(words[i],words[j]);
//			 
//		 }
// }
//
// void append1(char* str1,char* str2)
// {
//	 while(*str1!='\0')
//		 str1++;
//	 *str1++=' ';
//	 while(*str2)
//	 {
//		 *str1=*str2++;
//		 str1++;
//	 }
//	 *str1='\0';
// }
//
// char* concat(char words[100][100],int number)
// {
//	 int index=0;
//	 char *sentence=words[0];
//	 index++;
//	 while(index<=number)
//	 {
//         append1(sentence,words[index]);
//	 }
//	 return sentence;
// }
//
//char* sort_string1(char *sentence)
//{
//	char words[100][100];
//	int i=0,j=0;
//	char temp[50];
//	char *start=sentence;
//	while(*start)
//	{
//		if(*start==' '|| *start=='\0')
//		{
//			temp[j]='\0';
//			append(words[i],temp);
//			i++;
//			j=0;
//			start++;
//	   }
//		else 
//		{
//		temp[j++]=*start++;	
//		}
//	}
//	temp[j]='\0';
//	append(words[i],temp);
//    sort_sentence(words,i);
//	return concat(words,i);
//}
//
//int _tmain(int argc, _TCHAR* argv[])
//{   
//	int length=100;
//	char *input=(char *)malloc(sizeof(char)*(length+1));
//	printf("Enter the string to be sorted \n");
//	scanf("%[^\n]",input);
//
//	printf("%s\n",input);
//	printf("%s",sort_string1(input));
//
//	return 0;
//}
//
