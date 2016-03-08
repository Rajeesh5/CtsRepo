#include<stdio.h>
#include<malloc.h>
#include<iostream>
#define MAX_LEN 50

using namespace std;

struct node
{
    int data;
    struct node* left, *right;
};

struct stkNode
{
    struct node **stkArr;
    int top;
}*stk;

void createStack()
{
	stk=(struct stkNode *)calloc(1,sizeof(stkNode));
	stk->stkArr=(struct node *)calloc(MAX_LEN,sizeof(struct node*));
		stk->top=-1;
}

//void deleteStack(){}


void push(struct node *tmp)
{
	if(stk->top==MAX_LEN) return;
	else{
		stk->top++;
		stk->stkArr[stk->top]=tmp;
	}	
}
struct node *pop()
{
	struct node *tmp;
	if(stk->top==-1)return;
	else {
		tmp=stk->stkArr[stk->top];
		stk->top--;
		}
	return tmp;
}




void preOrder(struct node *tree)
{
	if(tree==NULL)return;
	else{
		cout<<tree->data<<" ";
		if(tree->right)push(tree->right);
		if(tree->left)push(tree->left);
		while(1)
		{
			struct *node tmp=pop();
			if(tmp==NULL)break;
			cout<<tree->data<<" ";
			if(tree->right)push(tree->right);
			if(tree->left)push(tree->left);
			
		}
	}
}




int main()
{

/* Constructed binary tree is
            10
          /   \
        20      30
      /  \     / \
    N     50  11  22
	     /  \
        70   90
  */
  struct node *root = newNode(10);
  root->left        = newNode(20);
  root->right       = newNode(30);
  root->right->left= newNode(11);
  root->right->right= newNode(22);
  root->left->right = newNode(50);
  root->left->right->left = newNode(70);
  root->left->right->right = newNode(90);
  
  preOrder(root);

	return 0;
}
	
