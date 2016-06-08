#include<iostream>
#include<stdio.h>
#include<malloc.h>

using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};
Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
void preOrder(Node* node)
{
    if (node == NULL) return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}
 
int findRootIndex(int inArr[],int postArr[],int val,int low,int high)
{
	int i,j;
	for( i=low;i<=high;i++)
	{
		if(inArr[i]==val){break;}
	}
	
	for(j=high-1;j>=i;j--)
	{
		postArr[j+1]=postArr[j];
		
	}
	postArr[j+1]=val;	
	return i;
} 
 
 
struct Node * buildTree(int inOrder[],int postOrder[],int low,int high)
{
	if(low>high){return NULL;}
	if(low==high){return newNode(postOrder[high]);}
	struct Node *root= newNode(postOrder[high]);
	int mid=findRootIndex(inOrder,postOrder,postOrder[high],low,high);
	root->left=buildTree(inOrder,postOrder,low,mid-1);
	root->right=buildTree(inOrder,postOrder,mid+1,high);
	return root;
}

int main()
{
    int in[]   = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(in)/sizeof(in[0]);
 
    Node *root = buildTree(in, post,0,n-1);
 
    cout  << "Preorder of the constructed tree : \n";
    preOrder(root);
 
    return 0;
}
