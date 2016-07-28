#include<stdio.h>
#include<malloc.h>
#define MIN_HEAP 0
#define MAX_HEAP 1
#define HEAP_LEN 50


using namespace std;

struct Heap 
{
	int *arr;
	int capacity,heapSize;
	int type;
}*minh,*maxh;

int getLeftChildIndex(int i) {if((2*i+1)>h->capacity)return -1; else return (2*i+1);}
int getRightChildIndex(int i){if((2*i+2)>h->capacity)return -1 ;else return (2*i+2);}
int getParentIndex(int i){if(i<=0)return -1; else return (i-1)/2; }


void heapInitialize(Heap *h, int t)
{
	h->capacity=HEAP_LEN;
	h->arr=(int*)malloc(HEAP_LEN*sizeof(int));
	h->type=t;
	h->heapSize=0;	
}

void heapify(heap **h,int i)
{
	int lIndex=getLeftChildIndex(i);
	int rIndex=getRightChildIndex(i);
	int maxIndex=-1;
	if(lIndex!=-1 && *h->arr[i] < *h->arr[lIndex])
		maxIndex=lIndex;
	else maxIndex=i;
	if(rIndex!=-1 && *h->arr[maxIndex] < *h->arr[rIndex])
		maxIndex=rIndex;
	if(maxIndex!=i)
	{
		int tmp=*h->arr[maxIndex];
		*h->arr[maxIndex]=*h->arr[i];
		*h->arr[i]=tmp;
		heapify(&h,maxIndex);
	}
}


void printHeapArr(heap *h)
{
	for(int i=0;i< h->heapSize;i++)
		printf("\d ", h->arr[i]);
	printf("\n");
	
}

int findTopOfHeap(heap *h)


void insertEle(heap **minH,heap **maxH,int data)
{
	//Checking Balance Factor

	if(*maxH->heapSize==0)
	{
		
		
	}
	
	else{
		
		
		
	}


	
}





int main()
{
	int streamArr[]={1,9,0,1,7,5,12,9,3,9,2,20,22,15,19,3,3,8};
	int streamLen=18,i=0;
	for(i=0;i<streamLen;i++)
		insertEle(minh,maxh,streamArr[i]);
	
	
	
	
	
	
	
}


