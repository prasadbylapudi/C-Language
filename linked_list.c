#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *link;
}*head=NULL;
int c;
void display()
{
    struct node *temp;
    temp=head;
    if(temp!=NULL)
    {
        printf("\nElements are:");
        do
        {
            printf("%d ",temp->data);
            temp=temp->link;
        }while(temp!=NULL);
        printf("\n");
    }
}	
void ins_at_beg(){
	int ele; 
	c++;
	printf("Enter element to insert: ");
	scanf("%d",&ele);
	struct node *newNode;
	newNode=(struct node *)malloc(sizeof(struct node));
	if(head==NULL){
		head=newNode;
		head->data=ele;
		head->link=NULL;
		return;	
	}
	newNode->data=ele;
	newNode->link=head;
	head=newNode;
}
void ins_at_end(){
	int ele;
	c++;
	printf("Enter element to insert: ");
	scanf("%d",&ele);
	struct node *newNode,*temp;
	newNode=(struct node *)malloc(sizeof(struct node));
	temp=head;
	if(head==NULL){
		head=newNode;
		head->data=ele;
		head->link=NULL;
		return;	
	}	
	while(temp->link!=NULL)
		temp=temp->link;
	temp->link=newNode;
	newNode->data=ele;
	newNode->link=NULL;
}
void ins_at_middle(){
	int pos,i,ele;
	printf("Enter the position of a element: ");
	scanf("%d",&pos);
	printf("Enter element to insert: ");
	scanf("%d",&ele);
	struct node *newNode,*temp,*prev;
	newNode=(struct node *)malloc(sizeof(struct node));
	temp=head;
	if(pos==c)
		ins_at_end();
	else if(pos==1)
		ins_at_beg();
	else{
		c++;
		for(i=1;i<pos;i++){
			prev=temp;
			temp=temp->link;
		}
		prev->link=newNode;
		newNode->data=ele;
		newNode->link=temp;	
	}
}
void del_at_beg(){
	struct node *temp;
	if(head==NULL){
		printf("The list is Empty");
	}
	else{
		c--;
		temp=head;
		printf("%d\n",temp->data);
		head=head->link;
		free(temp);
	}
}
void del_at_end(){
	struct node *temp,*prev;
	temp=head;
	if(head==NULL){
		printf("List is empty");
	}
	else if(head->link==NULL){
		c--;
		temp=head;
		printf("%d\n",temp->data);
		head=head->link;
		free(temp);
	}
	else{
		c--;
		while(temp->link!=NULL){
			prev=temp;
			temp=temp->link;
		}
		printf("%d\n",temp->data);
		prev->link=NULL;
		free(temp);
	}
}
void del_at_mid(){
	int pos,i;
	struct node *temp,*prev;
	temp=head;
	display();
	printf("Enter the position to be deleted: ");
	scanf("%d",&pos);
	if(pos==1){
		del_at_beg();
	}
	else if(pos==c){
		del_at_end();
	}
	else{
		c--;
		for(i=1;i<pos;i++){
			prev=temp;
			temp=temp->link;
		}
		printf("%d\n",temp->data);
		prev->link=temp->link;
		free(temp);
	}
}
void push(){
	ins_at_end();
}
void main(){
	int ele,i,n,a;
	do{
		printf("1.Push\n2.Insert\n3.Delete\n4.Display\n5.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&n);
		switch(n){
			case 1:
				push();
				break;
			case 2:
				printf("1.Insert at beginning\n2.Insert at end\n3.Insert at middle\n");
				printf("Enter your choice: ");
				scanf("%d",&a);
				switch(a){
					case 1:
						ins_at_beg();
						break;
					case 2:
						ins_at_end();
						break;
					case 3:
						ins_at_middle();
						break;
					default:
						printf("Invalid choice\n");
				}
				break;
			case 3:
				printf("1.Delete at beginning\n2.Delete at end\n3.Delete at middle\n");
				printf("Enter your choice: ");
				scanf("%d",&a);
				switch(a){
					case 1:
						del_at_beg();
						break;
					case 2:
						del_at_end();
						break;
					case 3:
						del_at_mid();
						break;
					default:
						printf("Invalid choice\n");
				}
				break;
			case 4:
				display();
				break;
			case 5:
				printf("Exit");
				break;
			default:
				printf("Enter a valid option\n");
		}
	}while(n!=5);
}
