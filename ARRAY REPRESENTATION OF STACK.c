#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int top=-1,stack[MAX],x,i;
void push();
void pop();
void display();
void peek();
void main()
{
   int ch;
    while(1)
	{
		printf("Stack Operations:\n");
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Display\n");
		printf("4.peek\n5.exit\n");
		printf("enter your choice=\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			push();
        	break;
			case 2:
			pop();
			break;
			case 3:
			display();
			break;
			case 4:
		    peek();
		    break;
		    case 5:
		    exit(0);
		    break;
			default:
			printf("choose right option\n");
     	}
	}
}
void push()
{
	if(top>=MAX)
	{
		printf("STACK is overe flow\n");
	}
	else
	{
		printf("enter the element to push=\n");
		scanf("%d",&x);
		top++;
		stack[top]=x;
	}
}
void pop()
{
	if(top<=-1)
	{
		printf("Stack is underflow\n");
		
	}
	else
	{
		printf("The popped element is= %d\n",stack[top]);
		top--;
	}
	
}
void display()
{
	if(top>=0)
	{
		printf("The elements in the stack are=");
		for(i=top;i>=0;i--)
		{
			printf("\n%d",stack[i]);
		}
	}
	else
	{
		printf("The stack is empty\n");
	}
}
void peek()
{
	printf("The Top element in the stack is=%d\n",stack[top]);
	
}

