#include<stdio.h> 
int division(int,int); 
void main() 
{
	int a,b,result; 
	printf("enter two numbers\n"); 
	scanf("%d %d",&a,&b); 
	result=division(a,b); 
	printf("%d",result);
} 
int division(int a,int b) 
{ 
	if(a-b<0) 
	return 0; 
	else if(a-b==0) 
	return 1; 
	else return division(a-b,b)+1; 
} 

