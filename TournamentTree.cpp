#include<iostream>
#define infinity 999
using namespace std;
struct tnode
{
	tnode* lchild;
	int data;
	tnode* rchild;
	int *aptr;
	int ind;
	tnode()
	{
		lchild=NULL;
		aptr=NULL;
		ind=0;
		rchild=NULL;
	}
};

tnode* create(tnode* root,int *s1,int *s2,int *s3,int level,int &cnt)
{
	if(level==0)
	{
		root=new tnode();
		if(cnt==1)
		{
			root->aptr=s1;
			cnt++;
			return root;
		}
		else if(cnt==2)
		{
			root->aptr=s2;
			cnt++;
			return root;
		}
		else if(cnt==3)
		{
			root->aptr=s3;
			cnt++;
			return root;
		}
		else
		return root;
	}
	root=new tnode();
	root->lchild=create(root->lchild,s1,s2,s3,level-1,cnt);
	root->rchild=create(root->rchild,s1,s2,s3,level-1,cnt);
	return root;
}
void fun(tnode* root,int level,int n)
{
	if(level==0)
	{
		if((root->ind>=n)||(root->aptr==NULL))
		{
			root->data=infinity;
			return;
		}
		else
		{
			root->data=root->aptr[root->ind];
			return;
		}
	}
	fun(root->lchild,level-1,n);
	fun(root->rchild,level-1,n);
	root->data=min(root->lchild->data,root->rchild->data);
}
void display(tnode* root)
{
	if(root)
	{
		display(root->lchild);
		cout<<root->data<<" ";
		display(root->rchild);
	}
}
void get_roottoleaf(tnode* root,int k,int level)
{
	if(level==0)
	{
		if(root->data==k)
		{
			root->ind++;
			return;
		}
		else
			return;
	}
	get_roottoleaf(root->lchild,k,level-1);
	get_roottoleaf(root->rchild,k,level-1);
}
int main()
{
	tnode* root=NULL;
	int s1[]={2,5,8,12};
	int s2[]={1,3,4,6};
	int s3[]={7,9,10,11};
	int level=2,cnt=1;
	int n=sizeof(s1)/sizeof(s1[0]);
	root=create(root,s1,s2,s3,level,cnt);
	for(int i=0;i<=6;i++)
	{
		fun(root,level,n);
		get_roottoleaf(root,root->data,level);
	}
	cout<<root->data<<" is the median of the sorted array.\n";
return 0;
}