#include<stdio.h> 
int mul(int x,int y) 
{ 
	if(y==0) 
	{ 
		return 0; 
	} 
	else if(y>0) 
	{ 
		return (x+mul(x,y-1)); 
	} 
	else if(y<0)
	{
		return -mul(x,-y);
	}
} 
int main() 
{ 
	int a,b,result; 
	printf("enter two numbers\n"); 
	scanf("%d %d",&a,&b); 
	result=mul(a,b); 
	printf("%d",result); 
} 
