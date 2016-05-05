#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
}*head;




void push(struct node **head_ref, int new_data)
{
	struct node* new_node =(struct node*) malloc(sizeof(struct node));
	new_node->data  = new_data;
	new_node->next = (*head_ref);    
	(*head_ref)    = new_node;
} 
void printList(struct node *node)
{
  while(node!=NULL)
  {
   printf("%d->", node->data);
   node = node->next;
  }
  printf("\n");
} 

struct node *findMid(struct node * tmpHead)
{
	if(tmpHead==NULL){return NULL;}
	struct node* node1x=tmpHead;
	struct node* node2x=tmpHead;
	while(1)
	{
		if(node2x->next->next==NULL) break;
		node1x=node1x->next;
		node2x=node2x->next->next;
		if(node2x==NULL || node2x->next==NULL || node2x->next->next==NULL ) break;
		
	}
	//node1x->next=NULL;
	return node1x;
}

struct node* MergeSort(struct node *tmpHead)
{
	if(tmpHead==NULL)return NULL;
	struct node *midHead= findMid(tmpHead);
	//Add mid list Null Properties
	
	printList(tmpHead);
	printList(midHead);
	MergeSort(tmpHead);
	MergeSort(midHead);
}



int main()
{
  
  
  push(&head, 45);
  push(&head, 30);
  push(&head, 51); 
  push(&head, 15);
  push(&head, 10);
  push(&head, 5); 
  push(&head, 20);
  push(&head, 3);
  push(&head, 2); 
  
  printList(head );           
  MergeSort(head);
    
  
   
  return 0;
}