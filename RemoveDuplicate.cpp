#include<iostream>
#include<string.h>
#include<stdio.h>
#include<malloc.h>
#include<math.h>
#define SPACIAL_CHAR '$'
using namespace std;

void removeDuplicateUnsortedChar(char arr[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]==arr[j])
			{
				arr[j]=arr[n-1];
				if(arr[j]==arr[n-1]){j--;} //Spacial condition where a[i],a[j]and a[n-1](last ele) all are same.
				arr[n-1]='\0';             //Set Last Char as a NULL 
				n--;                       //Decrement Array Bound.
				
			}
		}
	}
}
void bucketSort(int arr[],int n)
{
	int *range=(int*)calloc(10,sizeof(int));
	int i;
	for(i=0;i<n;i++)
	{
		range[arr[i]]=range[arr[i]]+1;
	}
	int count=0;
	for(i=0;i<10;i++)
	{
		while(range[i]!=0)
		{
			//cout<<i<<",";
			arr[count++]=i;
			range[i]--;
		}
	}
	free(range);
}
void exchange(char *a, char *b)
{
  char temp;
  temp = *a;
  *a   = *b;
  *b   = temp;
}
int partition(char A[], int si, int ei)
{
  char x = A[ei];
  int i = (si - 1);
  int j;
 
  for (j = si; j <= ei - 1; j++)
  {
    if (A[j] <= x)
    {
      i++;
      exchange(&A[i], &A[j]);
    }
  }
  exchange (&A[i + 1], &A[ei]);
  return (i + 1);
}
void quickSort(char A[], int si, int ei)
{
  int pi;    /* Partitioning index */
  if (si < ei)
  {
    pi = partition(A, si, ei);
    quickSort(A, si, pi - 1);
    quickSort(A, pi + 1, ei);
  }
}
void rdFormStr(char str[],int len)
{
	int curr,pre;
	for(curr=1;curr<len;curr++)
	{
		pre=curr-1;
		if(str[curr]==str[pre])
			str[pre]=SPACIAL_CHAR;
	}
	for(curr=0;curr<len;curr++)
	{
		if(str[curr]==SPACIAL_CHAR)
		{
			while(str[len-1]==SPACIAL_CHAR)
			{
				len--;
			}
			str[curr]=str[len-1];
			len--;
		}
		 
	}
	str[len]='\0';
	
	
}
 
 

int main()
{
	int  unsortedIntArr[]={0,1,2,3,3,5,0,0,1,6,7,4,5,8,9,0,2,3,4,5,1,6,9,7,8,9,1,9};
	char unsortedCharArr[]={'R','A','J','E','E','V','K','U','M','A','R','S','H','A','R','M','A'};
	int len1=sizeof(unsortedIntArr)/sizeof(int);
	int len2=sizeof(unsortedCharArr)/sizeof(char);
/*
	removeDuplicateUnsortedChar(unsortedCharArr,len2);
	cout<<unsortedCharArr<<endl;	
	
	bucketSort(unsortedIntArr,len1);
	for(int i=0;i<len1;i++)
	{
		cout<<unsortedIntArr[i]<<",";
	}
	printRepeating(arr,arr_size);
*/
	
	quickSort(unsortedCharArr,0,len2-1);
	
	cout<<unsortedCharArr<<endl;
	rdFormStr(unsortedCharArr,len2);
	cout<<unsortedCharArr<<endl;
	return 0;
	
}
