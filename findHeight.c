#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node* left, *right;
};
 
struct node* newNode(int data);
 
int max(int a, int b);
 
int height(struct node* node);

void preorder( struct node* ) ;
 
int height(struct node* node)
{
   if(node == NULL)
       return 0;
 
   return 1 + max(height(node->left), height(node->right));
} 
 
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
 
int max(int a, int b)
{
  return (a >= b)? a: b;
}    
 

void preorder(struct node *tmp)
{
	if(tmp)
	{
		printf("Node=%d and its height=%d\n",tmp->data,height(tmp));
		preorder(tmp->left);
		preorder(tmp->right);
	}


}



int main()
{
 
  /* Constructed binary tree is 
 *             1
 *           /   \
 *         2      3
 *        /  \
 *      4     5
 **/
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
 
  
	preorder(root);

 
  return 0;
}
