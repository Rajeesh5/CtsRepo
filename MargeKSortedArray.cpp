
#include<iostream>
#include<malloc.h>
#include<limits.h>
#define n 7
#define MAX_CAPACITY 100

using namespace std;


struct MinHeapNode
{
    int element;
    int listNo;
    int listIndex;
};

class MinHeap
{
public:
    MinHeapNode *harr;
    int heapSize;
	int capacity;
public:

    MinHeap();
    void minHeapify(int );
	void insertIntoHeap(int,int,int);
	void printHeap();
    int getLeftIndex(int i)  { if(2*i + 1 > heapSize) return -1; else return (2*i + 1); }
    int getRightIndex(int i) { if(2*i + 2 > heapSize) return -1; else return (2*i + 2); }
	int getParentIndex(int i){ if(i<=0 || i >= heapSize)return -1; else return (i-1)/2; }
    MinHeapNode  extractMin();
    friend void margeKArrays(int **,int ,int*);
};

void printArray(int arr[], int size)
{
   for (int i=0; i < size; i++)
   {
       cout << arr[i] << " ";
	   if((i+1)%n==0)cout<<"\n";
   }
}

MinHeapNode MinHeap::extractMin()
{
    MinHeapNode tmpMin = harr[0];
    harr[0]=harr[heapSize-1];
    heapSize--;
    minHeapify(0);
    return tmpMin;
}

void MinHeap::minHeapify(int index)
{
    int minIndex=index;
    int leftIndex=getLeftIndex(index);
    int rightIndex=getRightIndex(index);
    if(leftIndex != -1 && harr[index].element > harr[leftIndex].element)
        minIndex=leftIndex;
    else minIndex=index;

    if(rightIndex != -1 && harr[minIndex].element > harr[rightIndex].element )
        minIndex=rightIndex;

    if(minIndex != index)
    {
        swap(harr[index],harr[minIndex]);
        minHeapify(minIndex);
     }

}

void MinHeap::printHeap()
{
	for(int i=0;i<heapSize;i++)
		cout<<harr[i].element<<" ";
	cout<<endl;
}

void swapNode(MinHeapNode *x, MinHeapNode *y)
{
    	MinHeapNode* tmpSwap= new MinHeapNode();
    	tmpSwap=x;
		x=y;
		y=tmpSwap;

		//delete tmpSwap;

}

MinHeap::MinHeap()
{
	harr=(MinHeapNode*)calloc(sizeof(MinHeapNode),MAX_CAPACITY);
	for(int i=0;i<MAX_CAPACITY;i++)
	{
		harr->listIndex=0;
		harr->listNo=-1;
	}
	capacity=MAX_CAPACITY;
	heapSize=0;
}

void MinHeap::insertIntoHeap(int data,int lstNo,int lstIndex)
{
	int p;
	if(heapSize+1 >= MAX_CAPACITY)
	{
		cout<<"HEAP IS FULL , Cant Insert more element\n";
		return ;
	}
	harr[heapSize].element=data;
	harr[heapSize].listNo=lstNo;
	harr[heapSize].listIndex=lstIndex;
	heapSize++;
	p=getParentIndex(heapSize-1);
	if(p<0)return;
	for(int i=heapSize-1;i >=0 && harr[p].element >= data ;i=((i-1)/2))
	{
		swapNode(&harr[i],&harr[p]);
		p=getParentIndex(p);
	}

}

void margeKArrays()
{
	int i,count=0;
	int arr[][n] = {{ 1,3,3,7,9,10,13},
					{2,3,4,7,7,9,10},
					{5,6,7,9,10,11,14},
					{9,11,13,14,16,20,22}};


    int k = sizeof(arr)/sizeof(arr[0]);
 	int *output=new int[n*k];
	MinHeap *mHeap=new MinHeap();

	for(i=0;i<k;i++)
		mHeap->insertIntoHeap(arr[i][0],i,0);

	while( mHeap->heapSize > 0)
	{

        MinHeapNode tmp=mHeap->extractMin();
        output[count++]=tmp.element;
        if(tmp.listIndex<k)
            mHeap->insertIntoHeap(arr[tmp.listNo][tmp.listIndex+1],tmp.listNo,tmp.listIndex+1);
	}
	printArray(output,k*n);

}

int main()
{

	margeKArrays();

    return 0;
}
