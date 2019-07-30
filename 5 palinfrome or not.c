#include<stdio.h> 
void main()
{
	int n,num ; 
	printf("enter any number\n"); 
	scanf("%d",&n); 
	num=reverse(n); 
	if(n==num) 
	{ 
		printf("palindrome"); 
	} 
	else 
	{ 
		printf("not palidrome"); 
	}
} 
int reverse(int n) 
{ 
	static sum=0; 
	if(n!=0) 
	{ 
		sum=sum*10+(n%10); 
		reverse(n/10); 
	} 
	else 
	{ 
		return sum; 
	} 
}
