#include <stdio.h>
#define stack 20
char postfix[stack],ch;
int top=-1;
void push(int);
int pop();
void main()
{
	char Stack[stack];
	int m,i,op1,op2,num;
	int result;
	printf("enter the postfix expression ex:abc+de-/:\n");
	gets(Stack);
	i=0;
	while(Stack[i]!='\0')
	{
		ch=Stack[i];
		if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')
		{
		printf("enter the value of %c=",ch);
		scanf("%d",&m);
		push(m);
	    }
		else
		{
			op2=pop();
			op1=pop();
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
		i++;
	}
	result=pop();
	printf("The final result is=%d",result);
	
}
void push(int v)
{
	if(top>=stack)
	{
		printf("Stack overflow");
	}
	else
	{
	top++; 
	postfix[top]=v;
	}
	
}
int pop()
{
	int p;
	if(top<=-1)
	{
		printf("Stack underflow");
	}
	else
	{
	p=postfix[top];
	top--;
	return p;
    }
}
