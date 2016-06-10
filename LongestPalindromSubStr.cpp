#include<stdio.h>
#include<iostream>
#include<malloc.h>
#include<string.h>

using namespace std;

void printStr(char str[],int low,int hi)
{
    for(int i=low;i<=hi;i++)
    {
        cout<<str[i];
    }
    cout<<endl;
}


int main()
{
	char str[]= "BBABCBCAB";
	//char str[]= "ABCD";
	int len=strlen(str);
	int i,j;
	for(i=0;i<len;i++)
        for(j=0;j<len;j=j+1)
            if(j>=i && j-i > 0)
                printStr(str,i,j);


	return 0;
}

