#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;


struct treeNode
{
    int data;
    char info;
    struct node* left, *right;
};


struct Heap //MIN_HEAP
{
	treeNode **arr;
	int capacity,heapSize;
}*h;


int getLeftChildIndex(int i) {if((2*i+1)>=h->heapSize)return -1; else return (2*i+1);}
int getRightChildIndex(int i){if((2*i+2)>=h->heapSize)return -1 ;else return (2*i+2);}
int getParentIndex(int i){if(i<=0 || i >= h->heapSize)return -1; else return (i-1)/2; }

Heap *createHeap(int i)
{
	h=(Heap *)malloc(sizeof(Heap));
	h->capacity=i;
	h->heapSize=0;
	h->arr=(treeNode **)calloc(sizeof(treeNode*) , i);
	return h;
}
void distroyHeap()
{
	free(h->arr);
	h->arr=NULL;
	free(h);h=NULL;
}

void heapify(int i)
{
	int lIndex=getLeftChildIndex(i);
	int rIndex=getRightChildIndex(i);
	int maxIndex=-1;
	if(lIndex!=-1 && h->arr[i] < h->arr[lIndex])
		maxIndex=lIndex;
	else maxIndex=i;
	if(rIndex!=-1 && h->arr[maxIndex] < h->arr[rIndex])
		maxIndex=rIndex;
	if(maxIndex!=i)
	{
		int tmp=h->arr[maxIndex];
		h->arr[maxIndex]=h->arr[i];
		h->arr[i]=tmp;
		heapifyDown(maxIndex);
	}
}

void buildHeap(char *arr,int *freq,int size_of_A)
{
	int i;
	treeNode *tmp;
    h->heapSize=size_of_A;
	if(size_of_A > h->capacity)	{ printf("Exceed Heap Limit\n"); return;	}
	for(i=0;i<size_of_A;i++)
	{
	    tmp=new treeNode();
	    tmp->data=freq[i];
	    tmp->info=arr[i];
	    tmp->left=NULL;
	    tmp->right=NULL;
	    h->arr[i]=tmp;
	}

	for(i=0;i<(size_of_A-1)/2;i++)
			heapify(i);


}
void displayHeap()
{
	for(int i=0;i<h->heapSize;i++)
		printf("data:%d info:%c\n", h->arr[i]->data,h->arr[i]->info);
}
/*
void insertElement(int ele)
{
    h->heapSize++;
    if(h->heapSize > h->capacity)
        {printf("Need to resize the heap\n"); return;}
    int tmpIndex=h->heapSize-1;
    h->arr[tmpIndex]=ele;
    int p=getParentIndex(tmpIndex);

    while (p>=0)
    {
        if(h->arr[p]< h->arr[tmpIndex])
        {
            int tmp=h->arr[p];
            h->arr[p]=h->arr[tmpIndex];
            h->arr[tmpIndex]=tmp;
        }
        tmpIndex=p;
        p=getParentIndex(tmpIndex);
    }
}
int delEle()
{
    //Deletion of element in heap is always possibale through root element.
    int tmp=h->arr[0];
    h->arr[0]=h->arr[h->heapSize-1];
    h->heapSize--;
    heapifyDown(0);
    return tmp;

}

*/

int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

	h=createHeap(100);
	buildHeap(arr,freq,6);
	displayHeap();

	/*
	cout<<"After Inserting 50"<<endl;
	insertElement(50);
	cout<<"After Inserting 1"<<endl;
	insertElement(1);

   	displayHeap();

    //HEAP SORT
	while(h->heapSize>0)
        printf("%d\n",delEle());
    */

	distroyHeap();
	return 0;
}
