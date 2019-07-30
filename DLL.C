#include<stdio.h>
#include<conio.h>
struct node
{
int data;
struct node *rlink;
struct node *llink;
};
void append(),add_at_begin(),add_after(),display(),exit();
void del_at_begin(),del_at_end(),del_at_specific();
int l,length();
struct node *root=NULL;
void main()
{
int ch;
clrscr();
while(1)
{
printf("\n**menu**");
printf("\n 1.add_at_end\n2.add_at_begin \n3.add_after\n4.display\n5.length()\n6.delete at begin\n7.delete at end\n8.delete specific node\n9.exit\n");
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:append();
break;
case 2:add_at_begin();
break;
case 3:add_after();
break;
case 4:display();
break;
case 5:l=length();
printf("\nlength of the nodes is :%d",l);
break;
case 6:del_at_begin();
break;
case 7:del_at_end();
break;
case 8:del_at_specific();
break;
case 9:exit(0);
break;
default:printf("\nInvalid option..");
}
}
}
void append()
{
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
printf("\nenter the data:");
scanf("%d",&temp->data);
temp->llink=NULL;
temp->rlink=NULL;
if(root==NULL)
{
root=temp;
}
else
{
struct node *p;
p=root;
while(p->rlink!=NULL)
{
p=p->rlink;
}
p->rlink=temp;
temp->llink=p;
}
}
int length()
{
int c=0;
struct node * temp;
if(root==NULL)
{
return 0;
}
else
{
temp=root;
while(temp!=NULL)
{
c++;
temp=temp->rlink;
}
}
return c;
}
void display()
{
struct node *temp;
temp=root;
if(root==NULL)
{
printf("\n no nodes to display:");
}
else
{
printf("\n The data in L.L is.");
while(temp!=NULL)
{
printf("%d  ",temp->data);
temp=temp->rlink;
}
}
}
void add_at_begin()
{
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
printf("\nEnter the data:");
scanf("%d",&temp->data);
temp->llink=NULL;
temp->rlink=NULL;
if(root==NULL)
{
root=temp;
}
else
{
struct node *p;
p=root;
temp->rlink=p;
p->llink=temp;
root=temp;
}
}
void add_after()
{
int loc,i=1;
struct node *temp,*q;
printf("\nenter the location you want to place node:");
scanf("%d",&loc);
if(loc>length())
{
printf("\nsorry there are only %d nodes",length());
}
else
{
struct node *p;
temp=(struct node *)malloc(sizeof(struct node));
printf("\nEnter the data:");
scanf("%d",&temp->data);
temp->llink=NULL;
temp->rlink=NULL;
p=root;
while(i<loc)
{
p=p->rlink;
i++;
}
temp->rlink=p->rlink;
q=p->rlink;
q->llink=temp;
p->rlink=temp;
temp->llink=p;
}
}
void del_at_begin()
{
if(root==NULL)
{
printf("\nthere are no nodes to delete");
}
else
{
struct node *p;
p=root;
root=p->rlink;
root->llink=NULL;
free(p);
}
}
void del_at_end()
{
if(root==NULL)
{
printf("\nthere are no nodes to delete:");
}
else
{
struct node *p,*q;
p=root;
while(p->rlink!=NULL)
{
p=p->rlink;
}
q=p->llink;
q->rlink=NULL;
free(p);
}
}
void del_at_specific()
{
int loc,l,i=1;
l=length();
printf("\nEnter the location which you want to delete:");
scanf("%d",&loc);
if(loc>l)
{
printf("\nsorry..there are only %d nodes",l);
}
else
{
struct node *p,*q,*r;
p=root;
while(i<loc-1)
{
p=p->rlink;
i++;
}
q=p->rlink;
p	->rlink=q->rlink;
r=q->rlink;
r->llink=q->llink;
q->llink=NULL;
q->rlink=NULL;
free(q);
}
}























