#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20
char stack[MAX];
int top=-1;
void push(char);
char pop();
int priority(char);
void main()
{
	char exp[MAX],prefix[MAX];
	char *ch,x;
	int i=0;
	printf("enter the infix expression=");
	gets(exp);
	strrev(exp);
	ch=exp;
		while(*ch!='\0')
	{
		if(isalnum(*ch))
		{
		      prefix[i]=*ch;
		      i++;
		}
		else if(*ch==')')
		{
			push(*ch);
		}
		else if(*ch=='(')
		{
			while(x=pop()!=')')
			{
			     prefix[i]=x;
		         i++;
			}
		}
		else
		{
			while(priority(stack[top])>=priority(*ch))
			{
				prefix[i]=pop();
		        i++;
			}
			push(*ch);
		}
		ch++;
	}
	while(top!=-1)
	{
		prefix[i]=pop();
		i++;
		
	}
	puts(strrev(prefix));//printf("%s",strrev(prefix));
}
int priority(char o)
{
	if(o==')')
	{
		return 0;
	}
	if(o=='+'||o=='-')
	{
		return 1;
	}
	if(o=='*'||o=='/'||o=='%')
	{
		return 2;
	}
	
}
void push(char c)
{
	if(top==MAX-1)
	{
		printf("Stack Overflow");
	}
	else
	{
		top++;
		stack[top]=c;
	}
}
char pop()
{
	char y;
	if(top==-1)
	{
		printf("Stack underflow");
	}
	else
	{
		 y=stack[top];
		 top--;
		 return y;
	}
}
