#include<stdio.h> 
int gcd(int,int); 
void main() 
{ 
	int a,b,result;
	printf("enter any two numbers"); 
	scanf("%d %d",&a,&b); 
	result=gcd(a,b); 
	printf("gcd=%d",result); 
} 
int gcd(int a,int b) 
{ 
	int r; 
	r=a%b; 
	if(r==0) 
	{ 
		return b; 
	} 
	else 
	{ 
		return gcd(b,r); 
	} 
}
