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
struct node* PreOrderToBst(int *arr,int low, int high)
{
	int len=high-low+1;
	int mid;
	struct node *root;
	if(len==0){return NULL;}
	
	root=newNode(arr[0]);
	mid=low+1;
	while(arr[low] > arr[mid] ) mid++;
		
	root->left=PreOrderToBst(arr,low+1,mid);
	root->right=findRightChilds(arr,mid+1,high);
	return root;
		
}


int main()
{
	
/*
   We can make a Unique BST form from either preOrder or postOrder.
   OR,with combination of inOrder with preOrder/postOrder.
   Constructed binary tree is
            70
          /   \
        50      80
      /  \     / \
    N     60  75  90
	     /  \
        55   65
   
  struct node *root = newNode(70);
  root->left        = newNode(50);
  root->right       = newNode(80);
  root->right->left= newNode(75);
  root->right->right= newNode(90);
  root->left->right = newNode(60);
  root->left->right->left = newNode(55);
  root->left->right->right = newNode(65);
  preorder(root);
  
  */
  int preOrderArr[]={70,50,60,55,65,80,75,90};
  int  inOrderArr[]={50,55,60,65,70,75,80,90};
  int postOrderArr[]={55,65,60,50,75,90,80,70};

//  struct node * root=PreOrderToBst(preOrderArr,0,7);
  
  
  
  
   
  
  cout<<endl;
  return 0;
}