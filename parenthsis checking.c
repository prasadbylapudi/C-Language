#include <stdio.h>
#include <string.h>
#define MAX 20
void push(char);
char pop();
char stack[MAX];
int valid=1,top=-1;
void main()
{
	char exp[MAX],temp;
	int i;
	printf("enter the expression=");
	gets(exp);
	for(i=0;i<strlen(exp);i++)
	{
		if (exp[i]=='('||exp[i]=='{'||exp[i]=='[')
		{
			push(exp[i]);
		}
		if (exp[i]==')'||exp[i]=='}'||exp[i]==']')
		{
			if (top==-1)
			{
				valid=0;
			}
			else
			{
			   temp=pop();
			   if (exp[i]==')'&&(temp=='['||temp=='{'))
			   valid=0;
			   if (exp[i]==']'&&(temp=='('||temp=='{'))
			   valid=0;
			   if (exp[i]=='}'&&(temp=='['||temp=='('))
			   valid=0;
			}
		}
		
	}
	if (top>=0)
	{
		valid=0;
	}
	if (valid==1)
	{
		printf("Valid expression");
	}
	else
	{
		printf("Not valid expression");
	}
}
void push(char ch)
{
	if(top==MAX-1)
	{
		printf("Stack Over flow");
	}
	else
	{
	top++;
	stack[top]=ch;
    }
}
char pop()
{
	char c;
	if (top==-1)
	{
		printf("Stack underflow");
	}
	else
	{
	c=stack[top];
	top--;
	return c;
    }
}


