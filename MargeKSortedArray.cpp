
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

/*








MinHeap::MinHeap(MinHeapNode a[], int size)
{
    heap_size = size;
    harr = a;  // store address of array
    int i = (heap_size - 1)/2;
    while (i >= 0)
    {
        MinHeapify(i);
        i--;
    }
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l].element < harr[i].element)
        smallest = l;
    if (r < heap_size && harr[r].element < harr[smallest].element)
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

void swap(MinHeapNode *x, MinHeapNode *y)
{
    MinHeapNode temp = *x;  *x = *y;  *y = temp;
}





*/

void printArray(int arr[], int size)
{
   for (int i=0; i < size; i++)
   {
       cout << arr[i] << " ";
	   //if((i+1)%n==0)cout<<"\n";
   }
}


class MinHeap
{
    MinHeapNode *harr;
    int heapSize;
	int capacity;
public:

    MinHeap();
    void minHeapify(int );
	void insertIntoHeap(int);
	void printHeap();
    int getLeftIndex(int i)  { if(2*i + 1 > heapSize) return -1; else return (2*i + 1); }
    int getRightIndex(int i) { if(2*i + 2 > heapSize) return -1; else return (2*i + 2); }
	int getParentIndex(int i){ if(i<=0 || i >= heapSize)return -1; else return (i-1)/2; }
    MinHeapNode getMin() { return harr[0]; }
    //void replaceMin(MinHeapNode x) { harr[0] = x;  MinHeapify(0); }
};

void MinHeap::printHeap()
{
	for(int i=0;i<heapSize;i++)
		cout<<harr[i].element<<" ";
	cout<<endl;
}
void swap(MinHeapNode *x, MinHeapNode *y)
{


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

void MinHeap::insertIntoHeap(int data)
{
	int p;
	if(heapSize+1 >= MAX_CAPACITY)
	{
		cout<<"HEAP IS FULL , Cant Insert more element\n";
		return ;
	}
	harr[heapSize++].element=data;
	p=getParentIndex(heapSize-1);
	if(p<0)return;
	for(int i=heapSize-1;i >=0 && harr[p].element >= data ;i=((i-1)/2))
	{
		int tmp=harr[p].element;
		harr[p].element=harr[i].element;
		harr[i].element=tmp;

		p=getParentIndex(p);
	}
	
}

/*

int * mergeKArrays(int **arr, int k)
{
	int i;
	MinHeap *mHeap=new MinHeap();
	for(i=0;i<k;i++)
		insertIntoHeap(arr[1][i]);

	while(mHeap->heapSize>0)
	{

	}

}
*/








int main()
{

    int arr[][n] = {{ 1,3,3,7,9,10,13},
					{2,3,4,7,7,9,10},
					{5,6,7,9,10,11,14},
					{9,11,13,14,16,20,22}};


    int k = sizeof(arr)/sizeof(arr[0]);
 	printArray(arr[0],n*k);

	MinHeap *mHeap=new MinHeap();

	for (int i=0; i < k; i++)
	{
		for(int j=0; j < n ; j++)
		mHeap->insertIntoHeap(arr[i][j]);
	}

	cout<<endl;
	mHeap->printHeap();
	
	
    //int *output = mergeKArrays(arr, k);
    //cout << "Merged array is " << endl;
    //printArray(output, n*k);

    return 0;
}
