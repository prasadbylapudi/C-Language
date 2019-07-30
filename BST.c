#include<stdio.h> 
#include<conio.h> 
#include<stdlib.h> 
struct node 
{ 
struct node *left;  
int data;  
struct node *right; 
}; 
struct node *root=NULL,*parent; 
void insert(int val)
{  
	struct node *temp,*current,*parent; 
	 temp=(struct node*)malloc(sizeof(struct node));
  temp->left=NULL; 
  temp->data=val; 
  temp->right=NULL;  
if(root==NULL)  
{
	root=temp; 
 }
   else 
    {  
		current=root;  
		while(current) 
  		{   
		 parent=current;   
		  if(val>current->data)  
		    {     
				current=current->right;   
			 } 
			    else   
				 {     
						current=current->left;   
				 }   
		} 
		  if(val>parent->data)
		    {    
				parent->right=temp;  
		    }   
			else   {    parent->left=temp;   }  } } void preorder(struct node *tree) {  if(tree!=NULL)  {   printf("%d\t",tree->data);   preorder(tree->left); 
  preorder(tree->right);  } } void inorder(struct node *tree) {  if(tree!=NULL)  {   inorder(tree->left);   printf("%d\t",tree->data);   inorder(tree->right);  } } void postorder(struct node *tree) {  if(tree!=NULL)  {   postorder(tree->left);   postorder(tree->right);   printf("%d\t",tree->data);  } } void delete(struct node *current,int val) {    while(val!=current->data)  {   parent=current; 
  if(val>current->data)   {    current=current->right;   }   else   {    current=current->left;   }  }  if(current->left==NULL&&current->right==NULL)  {   if(parent->right==current)   {    parent->right=NULL;   }   else   {    parent->left=NULL;   }     }  else if(current->left==NULL&&current->right!=NULL)  {       if(parent->right==current)    {     parent->right=current->right; 
   }    else    {     parent->left=current->right;    }    current->right=NULL;    free(current);    }  else if(current->right==NULL&&current->left!=NULL)  {   if(parent->right==current)   {    parent->right=current->left;   }   else   {    parent->left=current->left;   }   current->left=NULL;   free(current);  }  else if(current->left!=NULL&&current->right!=NULL)  {    struct node *min,*prev=NULL;    min=current->right;    if(min->left==NULL)    { 
    parent->right=min;     min->left=current->left;     current->right=NULL;     current->right=NULL;     free(current);    }    else    {         while(min->left!=NULL)     {      prev=min;      min=min->left;     }        prev->left=min->right;     parent->right=min;     min->left=current->left;     min->right=current->right;     current->right=NULL;     current->left=NULL;     free(current);   }  } } int countn(struct node *tree) { 
 int c=1;  if(tree==NULL)  {   return 0;  }  else  {   c=c+countn(tree->left);   c=c+countn(tree->right);   return c;  } } void nthnode(struct node *tree,int n) {  static int count=0;  if(tree==NULL)  {   return;  }  if(count<=n)  {   nthnode(tree->left,n);   count++;   if(count==n)   {    printf("\n%d",tree->data);   } 
  nthnode(tree->right,n);  } } void small() {  struct node *current=root;  while(current->left!=NULL)  {   current=current->left;  }  printf("\n%d",current->data);   } void max() {  struct node *current=root;  while(current->right!=NULL)  {   current=current->right;  }  printf("\t%d",current->data); } void at_level(struct node* temp,int desired,int current) {  if(temp)  {   if(desired==current)    printf("%d\t",temp->data); 
  else   {    at_level(temp->left,desired,current+1);    at_level(temp->right,desired,current+1);   }  } } 
 
 
void main() {  int op,val,ele,count,n,c,l;  while(1)  {   printf("\n**MENU**");   printf("\n1.create");   printf("\n2.preorder traversal");   printf("\n3.inorder traversal");   printf("\n4.postorder");   printf("\n5.delete");   printf("\n6.count");   printf("\n7.nthnode in inorder");   printf("\n8.small");   printf("\n9.max");   printf("\n10.nodes at nth level");   printf("\nenter option");   scanf("%d",&op); 
  switch(op)   {    case 1:      printf("\nenter data");      scanf("%d",&val);      insert(val);      break;    case 2:      preorder(root);      break;    case 3:      inorder(root);      break;    case 4:      postorder(root);      break;    case 5:            printf("\nenter value");      scanf("%d",&ele);      delete(root,ele);      break;    case 6:      c=countn(root);      printf("\ncount:%d",c);      break;    case 7: 
     printf("\nenter n value");      scanf("%d",&n);      count=0;      nthnode(root,n);      break;    case 8:      small();      break;    case 9:      max();      break;    case 10:      printf("enter n value\n");      scanf("%d",&l);      at_level(root,l,0);      break;            }  } } 
