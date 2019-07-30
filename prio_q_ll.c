#include<stdio.h>
#include<stdlib.h>
struct node
{
	int priority;
	int info;
	struct node *link;
}*front=NULL,*rear=NULL;
void insert(int,int);
int del();
void display();
int isempty();
int main()
{
	int choice,item,item_priority;
while(1)
{
	printf("1.insert\n2.delete\n3.display\n4.quit\n");
	printf("\n enter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("input the item to be added to queue:");
			scanf("%d",&item);
			printf("enter its priority:");
			scanf("%d",&item_priority);
			insert(item,item_priority);
			break;
		case 2:
			printf("\n deleted item is %d ",del());
			break;
		case 3:
			display();
			break;
		case 4:
			exit(1);
		default:
		printf("wrong choice");
			
	}
}
}
void insert(int item,int item_priority)
{
	struct node *p,*temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=item;
	temp->priority=item_priority;
	if(rear==NULL)
	{
		rear=temp;
		front=temp;
	}
	else if(item_priority<rear->priority)
	{
		temp->link=rear;
		rear=temp;
	}
	else
	{
		p=rear;
		while(p->link!=NULL&&p->link->priority<=item_priority)
		{
			p=p->link;
		}
		temp->link=p->link;
		p->link=temp;
				
	}
}
int del()
{
	struct node *temp;
	int item;
	if(isempty())
	{
		printf("queue is underflow\n");
		exit(1);
	}
	else
	{
		temp=front;
		item=temp->info;
		front =front->link;
		free(temp);
	}
	return item;
}
int isempty()
{
	if(front==NULL)
	{
	return 1;
    }
	else
	{
	return 0;
    }
}
void display()
{
	struct node *p;
	p=front;
	if(front==NULL)
	{
		printf("queue is empty\n");
	}
	else
	{
		printf("queue is \n");
		printf("priority item\n");
		while(p!=NULL)
		{
			printf("%3d%3d\n",p->priority,p->info);
			p=p->link;
		}
	}
}	




