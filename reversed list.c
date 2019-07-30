#include <stdio.h>
#define MAX 100
int stack[MAX],top=-1,x;
void push(int);
int pop();
void main()
{
	int i,n;
	printf("enter the no of elements in array=");
	scanf("%d",&n);
	int arr[n];
	printf("enter the elements in array=");
	for (i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		push(arr[i]);
	}
	for (i=0;i<n;i++)
	{
		arr[i]=pop();
	}
	printf("The reversed list is=");
	for(i=0;i<n;i++)
	{
		printf("%3d",arr[i]);
	}
} 
void push(int v)
{    
    if(top>=MAX)
    {
    	printf("Stack overflow");
	}
	else
	{
      top++;
	  stack[top]=v;	
    }
}
int pop()
{
	if (top<=-1)
	{
		printf("Stack Underflow");
	}
	else
	{
	x=stack[top];
	top--;
	return x;
     }
}
