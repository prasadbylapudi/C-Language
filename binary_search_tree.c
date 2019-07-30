#include <stdio.h>
#include <stdlib.h>
struct node { 
    int key; 
    struct node *left, *right; 
}*root=NULL;
int ne=1; 
struct node *newNode(int item){ 
    struct node *temp=(struct node *)malloc(sizeof(struct node)); 
    temp->key=item; 
    temp->left=temp->right = NULL; 
    return temp; 
} 
void inorder(struct node *root){ 
    if (root!=NULL){ 
        inorder(root->left); 
        printf("%d \n", root->key); 
        inorder(root->right); 
    } 
} 
void pre(struct node *root){ 
    if (root!=NULL){ 
    	printf("%d \n", root->key); 
        pre(root->left); 
        pre(root->right); 
    } 
}
void post(struct node *root){ 
    if (root!=NULL) { 
        post(root->left); 
       	post(root->right); 
        printf("%d \n", root->key); 
    } 
}
struct node* insert(struct node* node, int key){ 
    if (node==NULL) 
		return newNode(key); 
    if (key<node->key) 
        node->left=insert(node->left, key); 
    else if(key>node->key) 
        node->right=insert(node->right, key);   
    return node; 
} 
int count(struct node *leaf){
	if(leaf==NULL)
		return 0;
	return 1+count(leaf->right)+count(leaf->left);	
}
void min_max(struct node *root){
	int s,l;
	struct node *temp;
	temp=root;
	s=root->key;
	l=s;
	while(temp!=NULL){
		s=temp->key;
		temp=temp->left;		
	}
	temp=root;
	while(temp!=NULL){
		l=temp->key;
		temp=temp->right;		
	}	
	printf("\nMAX:%d\nMIN:%d",l,s);	
}   
void nth(struct node *leaf)
{
	if(ne==1){
		printf("%d",leaf->key);
	}else if(count(root) < ne){
		printf("Tree is too SMALL");
	}else if(leaf!=NULL){
		nth(leaf->left);
		nth(leaf->right);
	}
	ne--;
}

void main() { 
    struct node *root = NULL; 
    int i,key,r,c,n;
    printf("Enter root node: ");
    scanf("%d",&r);
    root = insert(root,r); 
    do{
    	printf("\n1)Insert\n2)Inorder\n3)Preorder\n4)Postorder\n5)Count\n6)Min and Max\n7)nth node\n\8)Exit\nEnter your choice: ");
    	scanf("%d",&n);
    	switch(n){
	    	case 1:
		    	printf("Enter an element to insert: ");
		    	scanf("%d",&key);
		    	insert(root,key);
		    	break;
		    case 2:
		    	inorder(root);
				break; 
			case 3:
		   		pre(root);
		   		break;
			case 4:
		   		post(root); 
		   		break;
		   	case 5:
		   		c=count(root);
		   		printf("\n%d\n",c);
		   		break;
		   	case 6:
		   		min_max(root);
		   		break;
		   	case 7:
		   		printf("Enter level of node: ");
		   		scanf("%d",&ne);
		   		nth(root);
		   		break;
		   	case 8:
		   		printf("\nExit\n");
		   		break;
		   	default:
		   		printf("Invalid Choice");
		   }
	}while(n!=8);
} 
