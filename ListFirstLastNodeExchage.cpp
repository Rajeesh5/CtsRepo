#include<iostream>
#include<stdio.h>
#include<malloc.h>
#define MAX_LEN 50
using namespace std;

struct node
{
    int data;
    struct node* next;
};
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

void revList(struct node * headRef,struct node * walker,int count)
{
	if(walker==NULL)return;
	revList(headRef,walker->next,--count);
	int tmp=count;
	while(tmp>0)
	{
		headRef=headRef->next;
		tmp--;
	}
	cout<<headRef->data<<"   "<<walker->data<<"  "<< count<<endl;
		
}




int main()
{
	/*
	Input   10->20->30->40->50->60
	Output  10->60->20->50->30->40
	*/
	struct node *head=NULL;	
	head = newNode(10);
	head->next=newNode(20);
	head->next->next=newNode(30);
	head->next->next->next=newNode(40);
	head->next->next->next->next=newNode(50);
	head->next->next->next->next->next=newNode(60);
	displayList(head);
	
	revList(head,head,6);
	

	//displayList(head);
	
	return 0;



}