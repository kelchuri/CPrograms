// compiler_temp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>

int num(char *s)
{

	int n=0,r,i=0;
	
	while((s[i])&&(s[i]>47&&s[i]<58))
	{
		n*=10;
		r=s[i]-'0';
		n+=r;
		i++;
	}
	return n;

}
void input(char *s)
{
	gets(s);
}
int op(char s)
{
	if(s=='+'||s=='-'||s=='='||s=='*'||s=='/')
		return 1;
	return 0;
}
int tk(char s)
{
	if((s>96&&s<123))
		return 1;
	return 0;


}
void delspace(char *s)
{
	int i=0,j=1,v=1;
	while(*(s+i)!='\0'&&s+i!=NULL&&s[i]!=' ')
	{
		
		while(*(s+j)==' '&&*(s+j)!='\0')
		{
			
			j++;
			

		}
		i++;

		*(s+i)=*(s+j);
		
		j++;
		

	}
	*(s+i+1)='\0';
	return;
	
}
/*int exp(char *s)
{
	
	int t,i=0;
	
	 
	while(s[i]!='\0')
	{
		if(tk(s[i]))
			i++;
		else
		{
			printf("\n\ninvalid ");
			return 0;
		}
		
		if(op(s[i])||(s[i]>47&&58))
		{
			while(

			i++;
		
		else
		{
			printf("\n\ninvalid ");
			return 0;
		}
	}
	return 1;

}*/


int cal(int t1,char *s,int t2)
{
	if(*s=='+')
		return t1+t2;
	if(*s=='-')
		return t1-t2;
	if(*s=='*')
		return t1*t2;
	if(*s=='/')
	{
		if(t2!=0)
		return t1/t2;
		printf("\n uncalculated expresion ");
		return -1;
	}

	return t1;
}



int token(char *s,char **s1)
{
	int i=0,j=0,k=0,len=0;
	if(!tk(s[0])||s[1]!='=')
	{
		printf("\nsyntax error  ");
		return 0;
	}

	while(s[i])
	{
		if(tk(s[i]))
		{

			*(s1+k)=(char *)malloc(sizeof(char)*2);
			**(s1+k)=s[i];
			*(*(s1+k)+1)='\0';
			i++;
			k++;
		
				
		if(!(op(s[i]))&&s[i])
		{
			printf("\nsyntax error  ");
			return 0;
		}
		}

		if(op(s[i]))
		{
			*(s1+k)=(char *)malloc(sizeof(char)*2);
			**(s1+k)=s[i];
			*(*(s1+k)+1)='\0';
			i++;
			k++;
			if(!tk(s[i])&&!(s[i]>47&&s[i]<58))
			{
				printf("\nsyntax error  ");
				return 0;
			}
		}

		if((s[i])&&(s[i]>47&&s[i]<58))
		{
		len=0;
		while((s[i])&&(s[i]>47&&s[i]<58))
		{
			len++;
			i++;
		}

		*(s1+k)=(char *)malloc(sizeof(char)*(len+1));
		i=i-len;
		j=0;
		while(j<len)
		{
			*(*(s1+k)+j)=s[i];
			i++;
			j++;
		}
		*(*(s1+k)+j)='\0';
		if(s[i]=='.')
		{
			i++;
			while((s[i])&&(s[i]>47&&s[i]<58))
				i++;
		}
		k++;
		if(!op(s[i])&&s[i])
		{
			printf("\nsyntax error  ");
			return 0;
		}
		}
		
	}
	return k;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char *s,**s1;
	int *a,i,k=0,t1,t2,flag=0;
     s=(char *)malloc(sizeof(char)*100);
	 a=(int *)malloc(sizeof(int)*26);
     s1=(char** )malloc(sizeof(char*)*8);
	 for(i=0;i<26;i++)
		 a[i]=-1;

	 while(1)
	 {
		 printf("\n");
		 input(s);
		 i=0;
		 if(s[0]=='e'&&s[1]=='x'&&s[2]=='i'&&s[3]=='t')
		 {
			 break;
		 }
		 delspace(s);
		 
		
		k=token(s,s1);
		flag=0;
		 
	 for(i=0;i<k;i++)
		printf("%s\n",*(s1+i));
	 if(k)
	 {
        i=2;
	    if(tk(**(s1+i)))
		 {
			 if(a[*(s+i)-'a']==-1)
			 {
				 printf("\n %c is unindifined variable \n",**(s1+i));
				 flag=1;
				 i=k;
			 }
			 else
			 {
			 t1=a[**(s1+i)-'a'];
			 i++;
			 }

		 }
		 else
		 {
			 t1=num(*(s1+i));
			 i++;
		 }
		i++;
	 
	 for(;i<k;i++)
	 {
		 if(tk(**(s1+i)))
		 {
			 if(a[**(s1+i)-'a']==-1)
			 {
				 printf("\n%c is undifined variable\n",**(s1+i));
				 flag=1;
				 break;
			 }
			 t2=a[**(s1+i)-'a'];
			 

		 }
		 else
		 {
			 t2=num(*(s1+i));
			 
		 }

		 t1=cal(t1,*(s1+i-1),t2);
		 if(t1==-1)
			 break;

	 }
	 if(!flag)
	 {
	 a[**(s1)-'a']=t1;
	 printf("\n%c =  %d \n",**s1,a[**(s1)-'a']);
	 }



	 }	
	 }

	 	return 0;
}


