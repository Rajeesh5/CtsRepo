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

struct node *head,*tail;

struct node* newNode(int data)
{
	node *tmp=new node();tmp->left=tmp->right=NULL; tmp->data=data;
}

void inorder(struct node *tmp)
{
	if(tmp)
	{
		inorder(tmp->left);
		cout<<tmp->data<<"  ";
		inorder(tmp->right);
	}

}

void binToDLL( struct node *tmp)
{
	if(tmp==NULL)
	{
		return;
	}
	binToDLL(tmp->left);
	if(head==NULL)
	{
		head=tail=tmp;
		if(tmp->right)
			binToDLL(tmp->right);
	}
	else
	{
		tail->right=tmp;
		tail->right->left=tail;
		tail=tmp;
		binToDLL(tmp->right);
	}
}

void displayList(node *tmp)
{
	while(tmp)
	{
		cout<<tmp->data<<"  ";
		tmp=tmp->right;
	}
	cout<<endl;
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
  
  inorder(root);
  cout<<endl;
  head=tail=NULL;
  binToDLL(root);
  displayList(head);
  
  return 0;

}