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



int main()
{
	
	
}



