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

struct queueNode
{
    struct node **qArr;
    int rear,front;
}*Q;

struct queueNode * createQueue()
{
	Q=(queueNode*)calloc(1,sizeof(queueNode));
	Q->qArr=(struct node**) calloc(MAX_LEN,sizeof( node *) );
	Q->rear= -1;Q->front=-1;
	return Q;
}

void destroyQ()
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

void enqueue(struct node *tmp)
{
	
	if(isQFull())
	{
		cout<<"Q Full Can not Insert"<<endl;
		return;
	}
	else
	{
		if(Q->rear==-1){Q->rear=0; Q->front=0;}
		else Q->rear=(Q->rear+1)%MAX_LEN;
		Q->qArr[Q->rear]=tmp;
		
	}
}

struct node *dequeue()
{
	struct node *tmp=new node();
	if(isQEmpty())
	{
		cout<<"Q underflow Cannot delete"<<endl;
		return 0;
	}
	else{
		tmp=Q->qArr[Q->front];
		if(Q->front==Q->rear){ Q->rear= -1; Q->front=-1;}
		else Q->front=(Q->front+1)%MAX_LEN;
	}
			
	return tmp;
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


void levelSum(struct node *tree)
{
	int sum=0,level=0;
	struct node * tmp= new node();
	if(tree==NULL) return;
	enqueue(tree);
	enqueue(NULL);
	while(!isQEmpty())
	{		
		tmp=dequeue();
		if(tmp)
		{
			sum=sum+tmp->data;
			if(tmp->left)enqueue(tmp->left);
			if(tmp->right)enqueue(tmp->right);
		}
		else { cout << "Sum of Level "<< level<< " = "<<sum<<endl; sum=0;level++; 
			if(!isQEmpty())
				enqueue(NULL);
			}
		
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
  
		createQueue();
    levelSum(root);
	//enqueue(root);  
	//struct node* tmp=dequeue();
	//cout<<tmp->data;
	
	
  
  
  
  destroyQ();

  	

    

  return 0;
}

