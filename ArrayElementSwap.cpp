#include<stdio.h>
#include<iostream>


		//int arr[]={1,2,3,4,5};
int *arr;

void printArr()
{
	for(int i=0;i<5;i++)
		printf("%d ",arr[i]);
	printf("\n");

}
void swapElement(int *x,int *y )
{
	int *t=x;
	*x=*y;
	*y=*t;
	//printArr();

}


int main()
{

    arr=new int[5];
    for(int i=0;i<5;i++)
        arr[i]=i;

	swapElement(arr+1,arr+5);

	printArr();

	//printArr();

	return 0;


}

