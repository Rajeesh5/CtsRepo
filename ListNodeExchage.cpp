#include<iostream>
#include<stdio.h>
#include<malloc.h>
#define MAX_LEN 50
using namespace std;

struct node
{
    int data;
    struct node* next;
}*head=NULL;


struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->next=NULL;
  return(node);
}


void displayList(struct node *tmp)
{
	while(tmp)
	{
		cout<<tmp->data<<" ";
		tmp=tmp->next;
	}
	printf("\n");
}

void revList(struct node *nd)
{
	if(nd->next==NULL)
		{
			head=nd;
			return;
		}
	struct node *tmp=nd->next;
	nd->next=NULL;
	revList(tmp);
	tmp->next=nd;	
}

void revListIter(struct node *nd)
{
	
}


int main()
{
	head = newNode(10);
	head->next=newNode(20);
	head->next->next=newNode(30);
	head->next->next->next=newNode(40);
	head->next->next->next->next=newNode(50);
	displayList(head);
	
	revList(head);
	displayList(head);
	
	return 0;



}