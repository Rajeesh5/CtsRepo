#include<iostream>
#include<string.h>

using namespace std;

 struct DBString {
        char *dest,*DB,*accessName,*accessCode,*accessType;
    };
void getDBAttr(char *buff,DBString *DBStr)
{

}

void LTrim(char **str)
{
   while(isspace(**str)){*str=*str+1;}  //LTRIM
   int len=strlen(*str); len--;
   while(isspace(*(*str+len))) len--;   //RTRIM
   *(str+len+1)='\0';
}


int main()
{

    char * buff="  Rajeev   ";
    //DBString *DBStr=new DBString();
    //getDBAttr(buff,DBStr);

    LTrim(&buff);
    cout<<strlen(buff)<<endl;


    return 0;
}
