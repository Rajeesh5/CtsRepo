#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

#define ELE_CNT 1000000
//#define MAX_ARR_SIZE 1000
#define MAX_ARR_SIZE 10

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
    cout<<endl<<randIndex;
    swapElement(arr+randIndex,arr+r);
    return 0;
}

void randomizedQuickSort(int *arr,int p,int r)
{
    int q=rPartition(arr,p,r);
    //randomizedQuickSort(arr,p,q-1);
    //randomizedQuickSort(arr,q+1,r);
}



int main()
{
    FILE *fp=fopen("RandomFile.txt","r");
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

    free(arr);


}
