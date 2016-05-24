#include<stdio.h>
#include<iostream>
#define N 14
using namespace std;


void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];   
    int i = (low - 1); 
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;    
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void printArr(int A[])
{
	for(int i=0;i<N;i++)
		cout<<A[i]<<",";
	cout<<endl;
}
void quickSort(int A[],int lo,int hi)
{
	if(hi>=lo)
	{
		int q=partition(A,lo,hi);
		quickSort(A,lo,q-1);
		quickSort(A,q+1,hi);
	}
}
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)      
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1])
		   {
			   int t=arr[j+1];
			   arr[j+1]=arr[j];
			   arr[j]=t;
		   }
	for(i=0;i<n;i++)
		cout<<arr[i]<<",";
			
	cout<<endl;	  
}


int main()
{
	int arr[]={51,78,8,1,96,67,4,5,78,45,7,34,38,50};
	//int arr[]={3,2,6,7,1,5};
	//bubbleSort(arr,N);
	printArr(arr);
	 

	int k=3;
	int q=partition(arr,0,N-1);
	while(q!=k)
	{
		if(q > k)
		{
			q=partition(arr,0,q-1);
		}
		else
		{
			q=partition(arr,q+1,N-1);
		}
	}		
	
	cout<<arr[k];


//	quickSort(arr,0,N-1);
//	printArr(arr);
	
}	

