#include<iostream>
#include<stdio.h>
#include<malloc.h>
#define MAX_LEN 50
using namespace std;

struct node
{
    int data;
    struct node* left, *right;
};


struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}

int getMax(struct node * tree)
{
		while(tree->right)
			tree=tree->right;
		return tree->data;	
}

int getMin(struct node * tree)
{
		while(tree->left)
			tree=tree->right;
		return tree->data;	
}



int isBST( struct node * tree)
{
	if( tree==NULL) return 1;
	else if( tree->left && tree->right)
	{
		if( tree->data > getMax(tree->left) && tree->data < getMin(tree->right))
			return (isBST(tree->left)&& isBST(tree->right));
		else return 0;		
	}
	else if( tree->left)
	{
		if( tree->data > getMax(tree->left))
			return (isBST(tree->left));
		else return 0;		
	}
	else if( tree->right)
	{
		if( tree->data < getMin(tree->right))
			return (isBST(tree->right));
		else return 0;		
	}
	else return 1;
	
	
}

/*


int isBST(struct node* node) 
{ 
  if (node == NULL) 
    return 1; 
     
  if (node->left!=NULL && getMax(node->left) > node->data) 
    return 0; 
     
  if (node->right!=NULL && getMin(node->right) < node->data) 
    return 0; 
   
  if (!isBST(node->left) || !isBST(node->right)) 
    return 0; 
     
  return 1; 
}
*/







int main()
{
  struct node *root = newNode(4);
  root->left        = newNode(2);
  root->right       = newNode(5);
  root->left->left  = newNode(1);
  root->left->right = newNode(3); 
 
  if(isBST(root))
    printf("Is BST");
  else
    printf("Not a BST");
     
  getchar();
  return 0;
}  

	






	
	
	
	
	
	
	
	
	
	


 
 
 
 
 
 