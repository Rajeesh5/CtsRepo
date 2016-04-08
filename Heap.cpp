
#include<stdio.h>
#include<malloc.h>
using namespace std;

struct Heap //MAX_HEAP
{
	int *arr;
	int capacity,heapSize;
}*h;

int getLeftChildIndex(int i) {if((2*i+1)>h->capacity)return -1; else return (2*i+1);}
int getRightChildIndex(int i){if((2*i+2)>h->capacity)return -1 ;else return (2*i+2);}
int getParentIndex(int i){if(i<=0)return -1; else return (i-1)/2; }

Heap *createHeap(int i)
{
	h=(Heap *)malloc(sizeof(Heap));
	h->capacity=i;
	h->heapSize=0;
	h->arr=(int *)malloc(sizeof(int)*i);
	return h;
}
void distroyHeap()
{
	free(h->arr);h->arr=NULL;
	free(h);h=NULL;	
}
void heapifyDown(int i)
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
		h->arr[i]=h->arr[maxIndex];
		h->arr[maxIndex]=tmp;
		heapifyDown(maxIndex);
	}
}


void buildHeap(int *A,int size_of_A)
{
	int i;
	if(size_of_A > h->capacity)
	{	
		//cout<<"Exceed Heap Limit"<<endl;
		printf("Exceed Heap Limit\n");
		return;
	}
	for(i=0;i<size_of_A;i++)
		h->arr[i]=A[i];
	for(i=0;i<(size_of_A-1)/2;i++)
	{
		heapifyDown(i);
		h->heapSize++;
	}
}



void displayHeap()
{
	for(int i=0;i<=h->heapSize;i++)
		printf("%d ", h->arr[i]);
		//cout<<h->arr[i]<<","<<endl;
		
}


int main()
{
	int A[]={5,8,12,1,17,9};
	h=createHeap(6);
	buildHeap(A,6);
	displayHeap();
	distroyHeap();
	
	return 0;
}




























