#include<iostream>
#include<stdio.h>

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


void pathSum(struct node *tree,int sum,int *flag)
{
	if(*flag==1 || tree==NULL)
		return;
	else
	{
		sum=sum-tree->data;
		if(sum<0) return;
		if(tree->left==NULL && tree->right==NULL && sum==0){ *flag=1; return;}
		pathSum(tree->left,sum,flag);
		pathSum(tree->right,sum,flag);

	}

}




int main()
{

  /* Constructed binary tree is
            10
          /   \
        20      30
      /  \
    40     50
	  /  \
        70    90
  */
  struct node *root = newNode(10);
  root->left        = newNode(20);
  root->right       = newNode(30);
  root->left->left  = newNode(40);
  root->left->right = newNode(50);

  root->left->right->left = newNode(70);
  root->left->right->right = newNode(90);
	preorder(root);

	cout<<endl;
	int *flag =new int(0);
    pathSum(root,30,flag);
	if(*flag==1) cout<< "Sum Found";
	else cout<<"Not Found";

  return 0;
}
