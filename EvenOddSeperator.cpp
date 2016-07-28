#include<stdio.h>
#include<iostream>

void swap(int *a, int *b)
{
  int temp;
  temp = *a;
  *a   = *b;
  *b   = temp;
}

void EOpartition(int arr[],int low,int high)
{
	int r=arr[high];
	int p=-1;	
	while(low != high)
	{
		if(arr[low]%2==0)
		{
			p++;
			swap(&arr[p],&arr[low]);
			low++;
		}
		else
		{
			low++;
		}
		
		
	}
	swap(&arr[p+1],&arr[high]);
}
void printArr(int arr[],int len)
{
	for(int i=0;i<len;i++)
		printf("%d ,", arr[i]);
	printf("\n");
	
}



int main()
{
	int arr[]={2,67,3,68,33,4,79,24,47,89,40,55,60}; //Last Elemt even must
	int len=sizeof(arr)/sizeof(int);
	printArr(arr,len);
	EOpartition(arr,0,len-1);
	printArr(arr,len);
	
	
	
	
	
	return 0;
}