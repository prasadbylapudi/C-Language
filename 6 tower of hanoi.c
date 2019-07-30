#include<stdio.h> 
void toh(int n,char s,char d,char au) 
{ 
	if(n==1) 
	{ 
		printf("move disk %d from %c to %c\n",n,s,d); 
		return; 
	} 
	toh(n-1,s,au,d); 
	printf("move disk %d from %c to %c\n",n,s,d); 
	toh(n-1,au,d,s);
} 
void main() 
{ 
	int n; 
	printf("enter number of dics\n"); 
	scanf("%d",&n); 
	toh(n,'A','C','B');
} 

