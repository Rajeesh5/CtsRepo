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


struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}

struct stkNode
{
    struct node **stkArr;
    int top;
}*stk;

void createStack()
{
	stk=(struct stkNode *)calloc(1,sizeof(stkNode));
	stk->stkArr=(struct node **)calloc(MAX_LEN,sizeof(struct node*));
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
	if(stk->top==-1)return NULL;
	else {
		tmp=stk->stkArr[stk->top];
		stk->top--;
		}
	return tmp;
}




void preOrder(struct node *tree)
{
	struct node *tmp;
	if(tree==NULL)return;
	else{
		push(tree);
		while(1)
		{
			tmp=pop();
			if(tmp)	cout<<tmp->data<<" ";
			if(tmp==NULL)break;
			if(tmp->right)push(tmp->right);
			if(tmp->left)push(tmp->left);
			
		}
	}
}




int main()
{

/* Constructed binary tree is
            10
          /   \
        20      30
         \     / \
          50  11  22
	*/
  struct node *root = newNode(10);
  root->left        = newNode(20);
  root->right       = newNode(30);
  root->right->left= newNode(11);
  root->right->right= newNode(22);
  root->left->right = newNode(50);
  createStack();
  
  preOrder(root);

	return 0;
}
	
