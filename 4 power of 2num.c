#include<stdio.h> 
int power(int,int); 
void main() 
{ 
	int b,p,result; 
	printf("enter base\n"); 
	scanf("%d",&b); 
	printf("enter power\n"); 
	scanf("%d",&p); 
	if(p>=0) 
	{
		result=power(b,p); 
		printf("%d^%d=%d",b,p,result);
	}
	if(p<0) 
	{ 
		result=power(b,-p); 
		printf("%d^%d=1/%d",b,p,result); 
	}
} 
int power(int b,int p) 
{ 
	if(p!=0) 
	{ 
		return (b*power(b,p-1)); 
	} 
	else 
	{ 
		return 1;
	}
}
