#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

#define ELE_CNT 1000000
#define MAX_ARR_SIZE 1000

using namespace std;

void swapElement(int *a,int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}


int rPartition(int *arr,int p,int r)
{
    int randIndex=rand()%r;
    if(randIndex<p)randIndex+=p;
    swapElement(arr+randIndex,arr+r);
    int q=p-1;
    int pivot=arr[randIndex];
    while(p<r)
    {
        if(arr[p] <= pivot)
        {
            q++;
            swapElement(arr+p,arr+q);
        }
        p++;

    }
    q++;
    swapElement(arr+q,arr+r);
    arr[q]=pivot;
    return q;

}

void randomizedQuickSort(int *arr,int p,int r)
{
    if(p<r)
    {
        int q=rPartition(arr,p,r);
        randomizedQuickSort(arr,p,q-1);
        randomizedQuickSort(arr,q+1,r);
    }
}


void printArr(int *arr,int n)
{
        for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

}


int main()
{

    FILE *fp=fopen("RandomFile.txt","r");
    if(fp==NULL){printf("File Not Found"); return 1; }


    int *arr,i;
    time_t t;
    arr=(int*)calloc(sizeof(int),MAX_ARR_SIZE);
    srand((unsigned) time(&t));
    if(arr==NULL)
    {
        printf("Unable to Allocate Array Memory");
        return 1;
    }



    for(i=0;i<MAX_ARR_SIZE;i++)
        fscanf(fp,"%d",&arr[i]);
    fclose(fp);

    for(i=0;i<MAX_ARR_SIZE;i++)
        printf("%d ",arr[i]);

    randomizedQuickSort(arr,0,MAX_ARR_SIZE-1);

    cout<<endl;

    for(i=0;i<MAX_ARR_SIZE;i++)
        printf("%d ",arr[i]);

    free((void*)arr);
    arr=NULL;



}
