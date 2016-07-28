#include<iostream>
#include<string.h>

using namespace std;


/*
void LTrim(char **str)
{
   while(isspace(**str)){*str=*str+1;}  //LTRIM
   int len=strlen(*str); len--;

   while(isspace(*(*str+len))) len--;   //RTRIM

   int i=0;
   //str[len]=NULL;
   while(**str)
   {
       cout<<str+i <<"  "<<*str[i]<<endl;
       i++;
       if(i==5)
        str[i]=NULL;
   }
    cout<<*str;
}
*/
int main()
{

    char  *buff=strdup("  Rajeev   ");
    int len;

    while(isspace(*buff)){buff++;}
    len=strlen(buff); len--;
    while(isspace(*(buff+len)))len--;
    *(buff+len+1)='\0';


    cout<<buff<<"||||||"<<buff<<"||||||"<<endl;

    return 0;
}
