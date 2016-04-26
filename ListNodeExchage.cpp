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

void listDataExchange(struct node *nd)
{
    int tmp;
    if(nd==NULL || nd->next==NULL){return;}

    while(1)
    {
        //exchange(nd->data,nd->next->data);
        tmp=nd->data;
        nd->data=nd->next->data;
        nd->next->data=tmp;
        nd=nd->next->next;
        if(nd==NULL || nd->next==NULL) break;

    }
}

void listLinkExchange(struct node *nd)
{
    struct node *nodeNext;
    if(nd==NULL || nd->next==NULL) return;
    while(1)
    {
        nodeNext=nd->next->next;
        nd->next->next=nd;

        if(nd->next->next==head){head=nd->next;}

        nd->next=nodeNext;
        nd=nodeNext;
        if(nodeNext==NULL || nodeNext->next==NULL)break;
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
	
	revList(head);
	displayList(head);
	
	return 0;



}
