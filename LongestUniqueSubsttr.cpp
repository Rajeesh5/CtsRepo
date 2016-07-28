#include<stdio.h>
#include<iostream>
#include<malloc.h>
#include<string.h>
#define MAXLEN 50
using namespace std;

int main()
{
	char const *Str="RAJEEVKUMARSHARMA";
	int strLen=strlen(Str),i=0,maxSubStrLen=0;
	char *maxSubStr=(char *)malloc(sizeof(char)*MAXLEN);
	int subStrIndex=0,j,found=0;
	char ch;
	while(i++<strLen)
	{

	    if(subStrIndex==0)
        {
                maxSubStr[subStrIndex++]=Str[i];
                continue;
        }
        ch=Str[i];
	    for(j=0;j<subStrIndex;j++)
        {
            if(maxSubStr[j]==ch)
            {
                found=1;
            }
        }
        if(found)
        {
            maxSubStrLen=subStrIndex;
            cout<<maxSubStr<<endl;
            cout<<maxSubStr;
            break;
        }

        if(!found)
            maxSubStr[subStrIndex++]=Str[i];


	}

	return 0;


}
