#include<stdio.h>
#include<malloc.h>
#include<iostream>
#include<string.h>

using namespace std;


char* cut(char *str,char delim,int pos)
{
    int n=1,i=0,j=0,len;
    char *output=new char[128];
    memset(output,'\0',128);

    while(1){
        if(pos==n){
            while(str[i]!=delim && str[i]!='\0')
                output[j++]=str[i++];
            break;
        }
        else{
            while(str[i]!=delim || str[i]=='\0')
                i++;
            i++;
            n++;
        }
    }
    output[j+1]='\0';

    while(isspace(*output)){output++;}
    len=strlen(output); len--;
    while(isspace(*(output+len)))len--;
    *(output+len+1)='\0';

    return output;
}

int main()
{
    char *str=new char[1024];
    memset(str,'\0',1024);
    strcpy(str,"      Rajeev , APPS10   ,   readonly      ,     reports       , SQLSERVER  ");

    char *fld;
    int i=1;
    while(i<=5)
    {
        fld = cut(str,',',i++);
        cout<<fld<<"||||"<<fld<<"||||"<<endl;
    }

    return 0;

}

