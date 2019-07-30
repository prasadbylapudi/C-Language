#include <stdio.h>
#define stack 20
#include <string.h>
char prefix[stack],ch;
int top=0;
void push(int);
int pop();
void main()
{
	char Stack[stack];
	int m,i,op1,op2,len;
	int result;
	printf("enter the prefix expression=");
	gets(Stack);
	len=strlen(Stack);
	i=len-1;
	for(i;i>=0;i--)
	{
		ch=Stack[i];
		if(ch>='a' && ch<='z' || ch>='A' && ch<='Z')
		{
		printf("enter the value of %c=",ch);
		scanf("%d",&m);
		push(m);
	    }
		else
		{
			op1=pop();
			op2=pop();
			switch(ch)
			{
				case '+':
					result=op1+op2;
					push(result);
					break;
				case '-':
					result=op1-op2;
					push(result);
					break;
				case '*':
					result=op1*op2;
					push(result);
					break;
				case '/':
					result=op1/op2;
					push(result);
					break;			
			}
		}
	}
	result=pop();
	printf("The final result is=%d",result);
	
}
void push(int v)
{
	if(top>=stack)
	{
		printf("stack overflow");
	}
	else
	{
	top++; 
	prefix[top]=v;
    }
	
}
int pop()
{
	int p;
	if(top<=-1)
	{
		printf("stack underflow");
	}
	else
	{
	p=prefix[top];
	top--;
	return p;
   }
}
