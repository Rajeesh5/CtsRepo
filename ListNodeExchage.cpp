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
	
}

int main()
{
	head = newNode(10);
	head->next=newNode(20);
	head->next->next=newNode(30);
	head->next->next->next=newNode(40);
	head->next->next->next->next=newNode(50);
	displayList(head);
	
	struct node *node1=head;
	struct node *node2=head->next;	
	
	while(node2)
	{
		node1->next=node2->next;
		
		
		
	}
	
	
	
	return 0;



}