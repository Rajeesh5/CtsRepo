#include<iostream>
#include<stdio.h>

using namespace std;

int max(int a,int b){if(a>b)return a; else return b;}
int min(int a,int b){if(a<b)return a; else return b;}

int getMedian(int arrA[],int alow,int ahigh,int arrB[],int blow,int bhigh)
{
	int size=ahigh-alow+1;
	int t=size/2;
	int medA,medB;
	if(t==0){return -1;}
	if(t==1){
		
		return ( max(arrA[alow], arrB[blow]) + min(arrA[ahigh], arrB[bhigh]) )/2;
	}
	else
	{
	
		if(size%2 == 1)
		{
			medA=arrA[t];
			medB=arrB[t];
			if(medA==medB) return medA;
			else
			{
				if(medA < medB)
					return getMedian(arrA,alow+t,size-1,arrB,blow,blow+t);			
				else
					return getMedian(arrA,alow,t,arrB,t,size-1);
			}
		}
		else
		{
			medA=(arrA[t]+arrA[t-1])/2;
			medB=(arrB[t]+arrB[t-1])/2;
			if(medA==medB) return medA;
			else
			{
				if(medA > medB)
					return getMedian(arrA,alow,t-1,arrB,t,size-1);			
				else
					return getMedian(arrA,t,size-1,arrB,blow,t-1);			
			}
		}
	}
}



int main()
{
    int ar1[] = {2,9,17,18,19,20,28};
    int ar2[] = {5,10,15,20,25,30,35};
 
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    if (n1 == n2)
        printf("Median is %d", getMedian(ar1 ,0,n1-1, ar2, 0,n1-1));
    else
        printf("Doesn't work for arrays of unequal size");
    
    return 0;
}