#include<stdio.h>
#include<conio.h>
#define MAX 20
void inputredq();
void outputredq();
void delatright();
void delatleft();
void addatleft();
void addatright();
void display();
int length();
int left=-1,right=-1;
int deque[MAX];
void main()
{
int n;
clrscr();
printf("\n\nThis is a programme on Double Ended Queue by PRAVEENA\n\n");
printf("Double Ended Queue Menu:\n");
printf("1.Input restricted Dequeue");
printf("\n2.Output restricted Dequeue");
printf("\nEnter your choice:");
scanf("%d",&n);
switch(n)
{
case 1:inputredq();
       break;
case 2:outputredq();
       break;
default:printf("Wrong choice.");
}
getch();
}
void inputredq()
{
int n,i=1,p,a;
printf("\nSelect your operation for inserton:");
printf("\n1.From left\n2.From right");
printf("\nEnter your choice:");
scanf("%d",&a);
switch(a)
{
case 1:
while(i)
{
printf("\n\nInput restricted Dequeue Menu:\n");
printf("1.Insertion from left end");
printf("\n2.Deletion from Right end");
printf("\n3.Deletion from left end");
printf("\n4.Display");
printf("\n5.Length");
printf("\n6.Exit");
printf("\nEnter your choice:");
scanf("%d",&n);
switch(n)
{
case 1:addatleft();
       break;
case 2:delatright();
       break;
case 3:delatleft();
       break;
case 4:display();
       break;
case 5:p=length();
       printf("Length of the Dequeue is:%d",p);
       break;
case 6:i=0;
       break;
default:printf("Wrong choice:");
}
}
case 2:
while(i)
{
printf("\n\nInput restricted Dequeue Menu:\n");
printf("1.Insertion from right end");
printf("\n2.Deletion from Right end");
printf("\n3.Deletion from left end");
printf("\n4.Display");
printf("\n5.Length");
printf("\n6.Exit");
printf("\nEnter your choice:");
scanf("%d",&n);
switch(n)
{
case 1:addatright();
       break;
case 2:delatright();
       break;
case 3:delatleft();
       break;
case 4:display();
       break;
case 5:p=length();
       printf("Length of the Dequeue is:%d",p);
       break;
case 6:i=0;
       break;
default:printf("Wrong choice:");
}
}
}
}
void outputredq()
{
int n,i=1,p,b;
printf("\nSelect your operation for Deletion:");
printf("\n1.From left\n2.From right");
printf("\nEnter your choice:");
scanf("%d",&b);
switch(b)
{
case 1:
while(i)
{
printf("\n\nOutput restricted Dequeue Menu:\n");
printf("1.Insertion from left end");
printf("\n2.Insertion from Right end");
printf("\n3.Deletion from left end");
printf("\n4.Display");
printf("\n5.Length");
printf("\n6.Exit");
printf("\nEnter your choice:");
scanf("%d",&n);
switch(n)
{
case 1:addatleft();
       break;
case 2:addatright();
       break;
case 3:delatleft();
       break;
case 4:display();
       break;
case 5:p=length();
       printf("Length of the Dequeue is:%d",p);
       break;
case 6:i=0;
       break;
default:printf("Wrong choice:");
}
}
case 2:
while(i)
{
printf("\n\nOutput restricted Dequeue Menu:\n");
printf("1.Insertion from left end");
printf("\n2.Insertion from Right end");
printf("\n3.Deletion from right end");
printf("\n4.Display");
printf("\n5.Length");
printf("\n6.Exit");
printf("\nEnter your choice:");
scanf("%d",&n);
switch(n)
{
case 1:addatleft();
       break;
case 2:addatright();
       break;
case 3:delatright();
       break;
case 4:display();
       break;
case 5:p=length();
       printf("Length of the Dequeue is:%d",p);
       break;
case 6:i=0;
       break;
default:printf("Wrong choice:");
}
}
}
}
void addatleft()
{
int p;
printf("Enter an element:");
scanf("%d",&p);
if((left==0&&right==MAX-1)||(left==right+1))
{
printf("Dequeue is in overflow condition.");
}
else
{
if(left==-1)
{
left=0;
right=0;
}
else if(left==0)
{
left=MAX-1;
}
else
{
left=left-1;
}
deque[left]=p;
}
}
void addatright()
{
int p;
printf("Enter an element:");
scanf("%d",&p);
if((left==0&&right==MAX-1)||(left==right+1))
{
printf("Queue is in overflow condition.");
}
else
{
if(left==-1)
{
left=0;right=0;
}
if(right==MAX-1)
{
right=0;
}
else
{
right=right+1;
}
deque[right]=p;
}
}
void delatleft()
{
int val;
if(left==-1&&right==-1)
{
printf("Queue is in underflow condition.");
}
else
{
val=deque[left];
if(left==right)
{
left=right=-1;
}
if(left==0)
{
left=MAX-1;
}
else
{
left++;
}
printf("Deleted element is:%d",val);
}
}
void delatright()
{
int val;
if(left==-1)
{
printf("Dequeue is in underflow condition.");
}
else
{
val=deque[right];
if(right==MAX-1)
{
right=0;
}
if(left==right)
{
left=right=-1;
}
else
{
right=right-1;
}
printf("Deleted element is:%d",val);
}
}
int length()
{
int c=0,i;
if(left==-1)
{
return 0;
}
else
{
if(left<=right)
{
for(i=left;i<=right;i++)
{
c++;
}
}
else
{
for(i=0;i<=right;i++)
{
c++;
}
for(i=left;i<=MAX-1;i++)
{
c++;
}
}
return c;
}
}
void display()
{
int i;
if(left==-1)
{
printf("There is no element to display.");
}
else
{
printf("Elements in the Dequeue are:");
if(left<=right)
{
for(i=left;i<=right;i++)
{
printf("%3d",deque[i]);
}
}
else
{
for(i=left;i<=MAX-1;i++)
{
printf("%3d",deque[i]);
}
for(i=0;i<=right;i++)
{
printf("%3d",deque[i]);
}
}
}
}







