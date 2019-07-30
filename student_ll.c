#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int no;
	char name[20];
	int marks;
	struct node *link;
};
struct node *root=NULL;
void create();
void display();
void first_class();
void main()
{
		printf("enter student details\n");
		create();
		display();
		first_class();
		
		
}
void create()
{
		struct node *temp,*p;
		int num;
		printf("enter -1 to exit\n");
		printf("enter num\n");
		scanf("%d",&num);
		while(num!=-1)
		{
			temp=(struct node*)malloc(sizeof(struct node));
			temp->no=num;
			printf("enter name\n");
			scanf("%s",&temp->name);
			printf("enter marks\n");
			scanf("%d",&temp->marks);
			temp->link=NULL;
			if(root==NULL)
			{
				root=temp;
			}
			else
			{
				p=root;
				while(p->link!=NULL)
				{
					p=p->link;
				}
				p->link=temp;
			}
			printf("enter num\n");
			scanf("%d",&num);
		}
}
void display()
{
	struct node *temp=root;
	if(root==NULL)
	{
		printf("empty list\n");
	}
	else
	{
		printf("student details\n");
		while(temp!=NULL)
		{
			printf("%d\t\t%s\t\t%d\n",temp->no,temp->name,temp->marks);
			temp=temp->link;
		}
	}
}
void first_class()
{
	struct node *temp,*p;
	temp=root;
	p=temp->link;
	printf("first class student details\n");
	while(p!=NULL)
	{
	
		if(temp->marks==p->marks)
		{
			printf("%d\t%s\t%d\n",p->no,p->name,p->marks);
		}
		if(temp->marks<p->marks)
		{
			temp=p;
		}
		
		p=p->link;
	}
	
	printf("%d\t%s\t%d\n",temp->no,temp->name,temp->marks);
}

