#include<stdio.h>
#define MAX 10
int queue[MAX],front=-1,rear=-1;
void insert(int ele)
{
if(rear==-1)
{
front=rear=0;
queue[rear]=ele;
printf("\n Element inserted");
}
else
{
if(rear==MAX-1)
{
printf("Queue is full");
}
else
{
rear++;
queue[rear]=ele;
printf("\n Element inserted");
}
}
}
void display()
{
int i;
if(rear==-1)
{
printf("\n Sorry queue is empty");
}
else
{
printf("\nThe elements of the queue are:");
for(i=front;i<=rear;i++)
{
printf("%d  ",queue[i]);
}
}
}
void remove()
{
int a;
if(front==-1)
{
printf("Queue is empty");
return;
}
else if(front==rear)
{
a=queue[front];
front=rear=-1;
}
else
{
a=queue[front];
front++;
}
printf("The removing element is:%d\n",a);
}
int main()
{
int ele,choice,i=1;
while(i)
{
printf("\n**MENU**");
printf("\n 1.Insert\n2.Display\n3.Remove\n4.Exit");
printf("\n Enter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
{
printf("\n Enter any element to insert:");
scanf("%d",&ele);
insert(ele);
break;
}
case 2:
{
display();
break;
}
case 3:
{
remove();
break;
}
case 4:
{
	i=0;
	break;
}
default:
printf("\n Invalid choice");
}
}
}
