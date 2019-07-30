#include <stdio.h>
#include <conio.h>
struct node
    {
        int data;
        struct node *link;
    };
    struct node *root=NULL;
void addatend();
void addatbegin();
void addafter();
int len();
void display();

void reverse();

int main()
{
    int ch,l;

    while(1)
    {
        printf("\n 1.Add at end \n 2.Add at begin\n 3.Length\n4.add after\n 5.Display\n 6.reverse\n");
    printf("enter choice:");
    scanf("%d",&ch);
        switch(ch)
        {
            case 1:addatend();
                break;
            case 2:addatbegin();
                break;

            case 3:l=len();
                printf("length is %d",l);
                break;
            case 5:display();
                break;
            
            case 4:addafter();
                break;
            case 6:reverse();
            break;
            
            default:
				printf("wrong choice");
				exit(0);

        }
    }
}

void addatend()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root==NULL)
        root=temp;
    else
    {
        struct node *p;
        p=root;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
        printf("\n data is added");
    }

}

void addatbegin()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("\n enter data");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root==NULL)
        root=temp;
    else
    {
        temp->link=root;
        root=temp;
    }
}

void addafter()
{
    struct node *temp,*p;
    int loc,i=1,length;
    printf("enter location:");
    scanf("%d",&loc);
    length=len();
    if(loc>length)
        printf("No nodes");
    else
    {
        p=root;
        while(i<loc)
        {
            p=p->link;
            i++;
        }
        temp=(struct node*)malloc(sizeof(struct node));
        printf("enter data");
        scanf("%d",&temp->data);
        temp->link=NULL;
        temp->link=p->link;
        p->link=temp;
    }
}

int len()
{
    struct node *temp;
    int c=0;
    temp=root;
    if (temp==NULL)
        printf("No nodes");
    else
    {
        while(temp!=NULL)
        {

            temp=temp->link;
            c++;
        }
    }
    return c;
}

void display()
{
    struct node *temp;
    temp=root;
    if (temp==NULL)
        printf("no nodes");
    else
    {
        while(temp!=NULL)
        {
            printf("\t%d-->",temp->data);
            temp=temp->link;
        }
    }
}


void reverse()
{
	struct node *p,*q,*temp;
	int i,j,k,l;
	l=len();
	i=0;
	j=l-1;
	p=root;
	q=root;
	while(i<j)
	{
		k=0;
		while(k<j)
		{
			q=q->link;
			k++;
		}
		temp=p->data;
		p->data=q->data;
		q->data=temp;
		i++;
		j--;
		p=p->link;
		q=root;
	}

}


