#include <stdio.h>
#include <stdlib.h>
 

struct node
{
   int data;
   struct node* left;
   struct node* right;
};
 
void printKDistant(node *root , int k)    
{
   if(root == NULL) 
      return;
   if(k==0){printf("%d ",root->data);}
   else
   {
	   printKDistant(root->left,k-1);
	   printKDistant(root->right,k-1);
   }
}
 
struct node* newNode(int data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data; node->left = NULL; node->right = NULL;
  return(node);
}
 

int main()
{
 
  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \    /
    4     5  8 
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(8);  
  
  for(int i=0;i<=2;i++)
  {
	printKDistant(root, i);
    printf("\n");	
  }
  
 
  getchar();
  return 0;
}