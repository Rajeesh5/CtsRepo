#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node* left, *right,*next;
};
 
struct node* newNode(int data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL; node->right = NULL;node->next=NULL;
  return(node);
}
 
void preorder(struct node *tmp)
{
	if(tmp)
	{
		printf("node->data=%d &node=%X node->left=%X node->right=%X node->next=%X\n",tmp->data,
		&tmp,tmp->left,tmp->right,tmp->next);
		preorder(tmp->left);
		preorder(tmp->right);
	}
}


void nextSibling( struct node *tree)
{
	if(tree==NULL) return;
	else
	{
		if(tree->left&&tree->right)
			tree->left->next=tree->right;
		if(tree->left) nextSibling(tree->left);
		if(tree->right) nextSibling(tree->right);
	}
}



int main()
{
 
  /* Constructed binary tree is 
 *             1
 *           /   \
 *         2  -->3
 *        /  \    \
 *      4  -->5    9
 **/
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->right= newNode(9);
 
  
	preorder(root);

 
  return 0;
}
