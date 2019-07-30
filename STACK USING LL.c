#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*stnode,*first,*preptr;
void creat(int);
void display();
void delete_start();
void delete_end();
void delete_middle();
void delete_data();
main()
{	
	int n,a;
	printf("enter no.of nodes");
	scanf("%d",&n);
	printf("enter your option\n");
	printf("1-creation,2-deleting starting node,3-deleting ending node,4-deleting the node by it's position,5-deleting the node by it's data\n");
	scanf("%d",&a);
	switch(a)
	{
	case 1:
		creat(n);
		printf("list is\n");
		display();
		break;
	case 2:
		creat(n);
		delete_start();
		printf("after deleting of strating node\n");
		display();
		break;
	case 3:
		creat(n);
		delete_end();
		printf("after deleting of ending node\n");
		display();
		break;
	case 4:
		creat(n);
		delete_middle();
		printf("after deleting the node by it's position\n");
		display();
		break;
	case 5:
		creat(n);
		delete_data();
		printf("after deleting the node by it's data\n");
		display();
		break;
	default:
		printf("enter correct option");
	}
}
void creat(int n)
{
	int num,i;
	struct node *temp;
	stnode=(struct node *)malloc(sizeof(struct node));
	if(stnode==NULL)
	{
		printf("memory is not allocated");
	}
	else
	{
		printf("enter first node data\n");
		scanf("%d",&num);
		stnode->data=num;
		stnode->next=NULL;
		temp=stnode;
		for(i=2;i<=n;i++)
		{
			first=(struct node *)malloc(sizeof(struct node));
			if(first==NULL)
			{
				printf("memory is not allocated");
				break;
			}
			else
			{
				printf("enter %d node data\n",i);
				scanf("%d",&num);
				first->data=num;
				first->next=NULL;
				temp->next=first;
				temp=temp->next;
			}
		}
	}
	
}
void delete_start()
{	
	struct node *ptr;
	ptr=stnode;
	stnode=stnode->next;
	free(ptr);
}
void delete_end()
{	
	struct node *ptr,*preptr;
	ptr=stnode;
	while(ptr->next!=NULL)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=NULL;
	free(ptr);
}
void delete_middle()
{	
	struct node *ptr,*preptr;
	int c=1,m;
	printf("enter node no.\n");
	scanf("%d",&m);
	ptr=stnode;
	while(ptr->next!=NULL)
	{
		c++;
		preptr=ptr;
		ptr=ptr->next;
		if(c==m)
			break;
	}
	preptr->next=ptr->next;
	free(ptr);
}
void delete_data()
{	
	struct node *ptr,*preptr;
	int b;
	printf("enter data of node no.\n");
	scanf("%d",&b);
	ptr=stnode;
	while(ptr->data!=b)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
}

void display()
{
	struct node *temp;
	if(stnode==NULL)
	{
		printf("memory is not allocated");
	}
	else
	{
		temp=stnode;
		while(temp!=NULL)
		{
			printf("data of nodes=%d\n",temp->data);
			temp=temp->next;
		}
	}
	
}
