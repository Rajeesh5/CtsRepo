#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct node
{
    int data;
    struct node* next;
}*head;

struct node *marge(struct node**,struct node **);

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
void splitMid(struct node **headRef,struct node **lst1,struct node **lst2)
{
	if(*headRef==NULL){return ;}
	struct node* node1x=*headRef;
	struct node* node2x= *headRef;
	while(1)
	{
		if(node2x->next->next==NULL) break;
		node1x=node1x->next;
		node2x=node2x->next->next;
		if(node2x==NULL || node2x->next==NULL || node2x->next->next==NULL ) break;
	}
	*lst2=node1x->next;
	*lst1=*headRef;
	node1x->next=NULL;

}
struct node* SortedMerge(struct node* a, struct node* b)
{
    struct node* result = NULL;
    if (a == NULL)
        return(b);
    else if (b==NULL)
        return(a);

    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return(result);
}


struct node* MergeSort(struct node **headRef)
{
	struct node * lst1,*lst2;
	if(*headRef==NULL || (*headRef)->next==NULL){return *headRef;}

	splitMid(headRef,&lst1,&lst2);

	printf("FirstList=  ");printList(lst1);
	MergeSort(&lst1);
	printf("LastList=  ");printList(lst2);
	MergeSort(&lst2);
	//*headRef=SortedMerge(lst1,lst2);    //Recursive
	*headRef=marge(&lst1,&lst2);    //iterative
	//printf("FirstList=  ");printList(lst1);
	//printf("LastList=  ");printList(lst2);
	//printList(*headRef);
	//printList(head);


}



int main()
{


    head=NULL;


  push(&head, 45);
  push(&head, 30);
  push(&head, 51);
  push(&head, 15);
  push(&head, 10);
  push(&head, 5);
  push(&head, 20);
  push(&head, 2);
  push(&head, 3);
  printList(head );
  MergeSort(&head);
  printList(head );
  return 0;
}














struct node *marge(struct node **list1,struct node **list2)
{
    struct node *walker,*sortedHead;
    sortedHead=NULL;


    while(*list1 && *list2)
    {


    if((*list1)->data > (*list2)->data)
    {
        if(sortedHead==NULL)
        {
            walker=(node *)malloc(sizeof(node));
            walker->data=(*list2)->data;
            sortedHead=walker;
            (*list2)=(*list2)->next;
            continue;
        }
        walker->next=(node *)malloc(sizeof(node));
        walker=walker->next;
        walker->data=(*list2)->data;
        *list2=(*list2)->next;
    }
    else{
        if(sortedHead==NULL)
        {
            walker=(node *)malloc(sizeof(node));
            walker->data=(*list1)->data;
            sortedHead=walker;
            *list1=(*list1)->next;
            continue;
        }
        walker->next=(node *)malloc(sizeof(node));
        walker=walker->next;
        walker->data=(*list1)->data;
        *list1=(*list1)->next;

    }
    }



    if(*list1==NULL && *list2)
        walker->next=*list2;

    if(*list2==NULL && *list1)
        walker->next=*list1;



   return sortedHead;

}

