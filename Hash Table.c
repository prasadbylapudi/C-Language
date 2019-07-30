#include<stdio.h>
#define size 5
int arr[size];
void init()
{   
    int i;
    for(i = 0; i < size; i++)
        arr[i] = -1;
}
void insert(int value){   
    int key = value % size;
    if(arr[key] == -1){   
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value,key);
    }
    else{   
        printf("Collision : arr[%d] has element %d already!\n",key,arr[key]);
        printf("Unable to insert %d\n",value);
    }
}
void del(int value){
    int key = value % size;
    if(arr[key] == value)
        arr[key] = -1;
    else
        printf("%d not present in the hash table\n",value);
}
void search(int value)
{
    int key = value % size;
    if(arr[key] == value)
        printf("Search Found\n");
    else
        printf("Search Not Found\n");
}
void print(){
    int i;
    printf("-------------------------\n");
    printf("|\tLoc -  Dta\t|\n");
    printf("-------------------------\n");
    for(i = 0; i < size; i++)
        printf("|\t%d  |\t%d\t|\n",i,arr[i]);
    printf("-------------------------\n");
}
void main(){
    init();
    int ch,x,c=0;
    printf("\n1.Insert\n2.Search\n3.Delete\n4.Display\n");
	while(!c){
	    printf("Enter choice : ");
	    scanf("%d",&ch);
	    switch(ch){
	    	case 1:
	    		printf("Enter element to insert : ");
	    		scanf("%d",&x);insert(x);break;
	    	case 2:
	    		printf("Enter element to search : ");
	    		scanf("%d",&x);search(x);break;
	    	case 3:
	    		printf("Enter element to delete : ");
	    		scanf("%d",&x);del(x);break;
	    	case 4:
	    		print();c++;break;
		}
	}
}
