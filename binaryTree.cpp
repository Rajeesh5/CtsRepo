
#include<iostream>
#include<stdio.h>
#include<malloc.h>

using namespace std;

struct node
{
    int data;
    struct node* left, *right;
}*root=NULL;



void preorder(struct node *tmp)
{
	if(tmp)
	{
		cout<<tmp->data<<"  ";
		preorder(tmp->left);
		preorder(tmp->right);
	}
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


void insertEle(struct node *walker,int val)
{
    struct node *ptr=new node();
    ptr->left=NULL;ptr->right=NULL;
    ptr->data=val;
    if(root==NULL){root=ptr;return;}
    if(val>walker->data)
    {
         if(walker->right==NULL){walker->right=ptr;}
         else insertEle(walker->right,val);
    }
    else if(val<walker->data)
    {
        if(walker->left==NULL){walker->left=ptr;}
        else insertEle(walker->left,val);
    }
    else {cout<<"Canot insert duplicate element  "<<val<<"\n"; }


}



void getParent(struct node *tree,int val,struct node **p)
{
    if(!tree || *p )return;

    if(tree->left)
    {
        if(tree->left->data==val){ *p=tree;  return;}
    }
    if(tree->right)
    {
        if(tree->right->data==val){ *p=tree; return;}
    }

       getParent(tree->left,val,p);
       getParent(tree->right,val,p);
}



/*
struct node *getParent(struct node *tree,int val )
{
    if(!tree) return NULL;
    if(tree->left)
    {
        if(tree->left->data==val)  return tree;
    }
    if(tree->right)
    {
        if(tree->right->data==val)  return tree;
    }
    getParent(tree->left,val);
    getParent(tree->right,val);
}
*/


int main()
{
/*
             10
            /  \
           6    19
            \   /
             9 13
 */

    insertEle(root,10);
    insertEle(root,6);
    insertEle(root,9);
    insertEle(root,19);
    insertEle(root,13);
    preorder(root);
    cout<<endl;

    node *tmp=new node();
    tmp=NULL;

    getParent(root,13,&tmp);
    if(tmp)
        cout<<"parent Found "<<tmp->data;





/*
    tmp=getParent(root,  9);
    if(tmp)
        cout<<"parent Found "<<tmp->data;
*/

}
