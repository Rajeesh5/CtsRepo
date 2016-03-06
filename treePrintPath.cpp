#include<iostream>
#include<stdio.h>
#include<malloc.h>
#define MAX_LEN 100
using namespace std;

struct node
{
    int data;
    struct node* left, *right;
};

/* function to create a new node of tree and returns pointer */
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


void printPath(struct node *tree, int *arr,int len)
{
	if(tree->left==NULL && tree->right==NULL)
	{
		arr[len++]=tree->data;
		for(int i=0;i<len;i++)
			cout<<arr[i]<<"  ";

        cout<<endl;

	}

	else
	{
        arr[len++]=tree->data;
		if(tree->left) {  printPath(tree->left,arr,len); }
		if(tree->right){ printPath(tree->right,arr,len); }

	}


}



int main()
{

  /* Constructed binary tree is
            10
          /   \
        20      30
      /  \
    N     50
	     /  \
        70   90
  */
  struct node *root = newNode(10);
  root->left        = newNode(20);
  root->right       = newNode(30);
  root->right->left= newNode(11);
  root->right->right= newNode(22);
 // root->left->left  = newNode(40);
  root->left->right = newNode(50);

  root->left->right->left = newNode(70);
  root->left->right->right = newNode(90);
  //preorder(root);

	int *arr=(int *)malloc(sizeof(int)*MAX_LEN);
	printPath(root,arr,0);



  return 0;
}

