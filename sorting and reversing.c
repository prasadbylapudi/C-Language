#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{	int data;
	struct node *next;
};
struct node *start=NULL;
void create_ll();
void display();
void rev();
int len();
void sort_list();

int main()
{	int option;
		
		do{
			printf("\n1.create list");
		printf("\n2.display:");
	
		printf("\n3:sort the list");
		printf("\n4.reverse");
		printf("\nEnter your option:");
		scanf("%d",&option);
		
		switch(option)
		{
		case 1:create_ll();
			printf("\n Linked List created");
			break;
		case 2:display();
			break;
		
		case 3:sort_list();
			break;
			case 4:rev();
			break;
	      
		default:
			printf("wrong choice:");
			exit(0);
		}
	}while(option!=5);
       
}
void create_ll()
  {	 
    struct node *temp,*p;
	int num;
	printf("\n Enter -1 to end\n Enter the data:");
	scanf("%d",&num);
	while(num!=-1)
	{	temp=(struct node*)malloc(sizeof(struct node*));
		temp->data=num;
		temp->next=NULL;
			if(start==NULL)
			{
				start=temp;
			}
			else
			{
				p=start;
				while(p->next!=NULL)
				{
					p=p->next;
				}
				p->next=temp;
			}
			printf("enter num\n");
			scanf("%d",&num);
	}
}
void display()
	{ 
    struct node *p;
	p=start;
	printf("\n");
	while(p!=NULL)
	{printf("\t %d",p->data);
	p=p->next;
	}
	}

void sort_list()
{
	
		struct node *p,*q;
		int temp;
		p=start;
		while(p->next!=NULL)
		{
		q=p->next;
			while(q!=NULL)
			{    if(p->data>q->data)
				{
				temp=p->data;
				p->data=q->data;
				q->data=temp;
				}
				q=q->next;
			}
			p=p->next;
		}

}
void rev()
{
	struct node *p,*q,*temp;
	int i,j,k,l;
	l=len();
	i=0;
	j=l-1;
	p=start;
	q=start;
	while(i<j)
	{
		k=0;
		while(k<j)
		{
			q=q->next;
			k++;
		}
		temp=p->data;
		p->data=q->data;
		q->data=temp;
		i++;
		j--;
		p=p->next;
		q=start;
	}

}

int len()
{
    struct node *temp;
    int c=0;
    temp=start;
    if (temp==NULL)
        printf("No nodes");
    else
    {
        while(temp!=NULL)
        {

            temp=temp->next;
            c++;
        }
    }
    return c;
}
