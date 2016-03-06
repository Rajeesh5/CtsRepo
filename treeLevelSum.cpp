#include<iostream>
#include<stdio.h>
#include<malloc.h>
#define MAX_LEN 20
using namespace std;

struct node
{
    int data;
    struct node* left, *right;
};


struct queueNode
{
    struct node *treelist;
    int rear,front;
}Q;

void queueInitialize()
{
  Q.treelist=(struct node *)calloc(MAX_LEN,sizeof(struct node));
  Q.rear=Q.front=-1;
}
void distroyQ()
{
    for(int i=0;i<MAX_LEN;i++)
        free( (void *) &Q.treelist[i]);
}
int isQEmpty()
{
    if (Q.front==-1)return 1;
    else return 0;
}
int isQFull()
{
    if((Q.rear+1)%MAX_LEN==Q.front) return 1;
    else return 0;
}

void enqueue(struct node *tmp)
{
    if(isQFull()){cout<<"Cant Insert"; return; }
    else
    {
        if(Q.rear==-1){Q.front=Q.rear=0;}
        Q.treelist[Q.rear++] = tmp;

    }

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
  preorder(root);
  queueInitialize();

    for (int i=0;i<MAX_LEN;i++)
        cout<<Q.treelist[i].data;




    distroyQ();


  return 0;
}

