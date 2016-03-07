#include<iostream>
#include<stdio.h>
#include<malloc.h>
#define MAX_LEN 10
using namespace std;

struct node
{
    int data;
    struct node* left, *right;
};

struct queueNode
{
    struct node **qArr;
    int rear,front;
}*Q;

struct queueNode * createQueue()
{
	Q->qArr=(struct node**) calloc(MAX_LEN,sizeof( node *) )
	Q->rear=Q->front=-1;
	return Q;
}

void distroyQ()
{
    for(int i=0;i<MAX_LEN;i++)
        free(Q->qArr[i]);
	free(Q);
} 

int isQEmpty()
{
    if (Q->front==-1)return 1;
    else return 0;
}

int isQFull()
{
    if((Q->rear+1)%MAX_LEN==Q->front) return 1;
    else return 0;
}

void enqueue(int data)
{
   



}

struct node* newNode(int data)
{
	node *tmp=new node();tmp->left=tmp->right=NULL; tmp->data=data;
}

void preorder(struct node *tmp)
{
	if(tmp)
	{
		cout<<tmp->data<<"  ";
		preorder(tmp->left);
		preorder(tmp->right);
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

	enqueue(root);    

  return 0;
}

