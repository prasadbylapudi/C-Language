#include<stdio.h>
#define SIZE 6
int cq[SIZE];
void insertcq(int);
void deletecq();
void display();
void exit();
int front=-1,rear=-1;
int main()
{
	int n,ch,i=1;
	while(i)
	{
		printf("\n circular queue:\n0.Exit\n1.insert\n2.delete\n3.display");
		printf("\nenter choice 0-3:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n enter number:");
				scanf("%d",&n);
				insertcq(n);
				break;
			case 2:
				deletecq();
				break;
			case 3:
				display();
				break;
			case 0:
				i=0;
				break;
			default:
				printf("\nSorry invalid option");
		}
    }
}
void insertcq(int item)
{
	if((front==0&&rear==SIZE-1)||(front==rear+1))
	{
		printf("q is full..");
		return ;
	}
	else if(rear==-1)
	{
		rear++;
		front++;
	}
	else if(rear==SIZE-1&& front>0)
	{
		rear=0;
	}
	else
	{
		rear++;
	}
	cq[rear]=item;
}
void display()
{
	int i;
	printf("\nThe  queue elements are:");
	if(front>rear)
	{
		for(i=front;i<SIZE;i++)
		{
			printf("%3d ",cq[i]);
		}
		for(i=0;i<=rear;i++)
		{
			printf("%3d",cq[i]);
		}
	}
		else
		{
			for(i=front;i<=rear;i++)
			printf("%3d",cq[i]);
		}
}
void deletecq()
{
	if(front==-1&&rear==-1)
	{
		printf("queue is empty");
	}
	else if(front==rear)
	{
		printf("\n %d deleted",cq[front]);
		front=-1;
		rear=-1;
	}
	else
	{
		if(front==SIZE-1)
		{
		printf("\n %d deleted",cq[front]);
		front=0;
	    }
	    else
	    {
			printf("\n %d is deleting element",cq[front]);
			front++;
		}
	}
}
