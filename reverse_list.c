 #include<stdio.h>
#include<conio.h>
int stk[10];
int top=-1;
int pop();
void push(int);
int main()
{
	int val,n,i;
	int arr[10];
	printf("\n enter the number of elements:");
	scanf("%d",&n);
	printf("\n enter the elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
		push(arr[i]);
	}
	for(i=0;i<n;i++)
	{
		val=pop();
		arr[i]=val;
	}
	printf("\n the reversed array is:");
	for(i=0;i<n;i++)
	{
		printf("\n %d",arr[i]);
	}
	return 0;
}
void push(int val)
{
	stk[++top]=val;
}
int pop()
{
	return(stk[top--]);
}
