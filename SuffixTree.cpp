#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <iostream>

using namespace std;

struct suffixNode
{
    char data,count;
    struct suffixNode *children,*next;
    bool isLeaf;
};

struct suffixNode *getNode(void)
{
    struct suffixNode *pNode = NULL;
    pNode = (struct suffixNode *)malloc(sizeof(struct suffixNode));
    pNode->data='\0';
    pNode->count=0;
    pNode->isLeaf=false;
    pNode->children=NULL;
    pNode->next=NULL;
    return pNode;
}



void buildSuffixTree(struct suffixNode ** root,const char str[])
{

    struct suffixNode *tnode=getNode();
    int len=strlen(str);
    if(*root==NULL){*root=tnode;}
    else
    {
        if( (*root)->data > str[0]) //Add node beggning of list
        {
            tnode->next=*root; *root=tnode;
        }

        else if((*root)->data < str[0])  //
        {
            suffixNode *walker = *root;
            while( walker->next != NULL and walker->data < str[0] )
                walker=walker->next;
            walker->next=tnode;

        }

        else{}   // Common prefix Found...

    }


    for(int i=0;i<len;i++)
    {
        tnode->count++;
        tnode->data=str[i];
        //tnode->next=NULL;
        if(i==len-1){tnode->isLeaf=true;}
        else{
            tnode->children=getNode();
            tnode=tnode->children;
        }
    }

    printf("");

}


int main()
{
    const char *inputStr="banana";
    int len=strlen(inputStr),i;

    struct suffixNode *root=NULL;

    for(i=0;i<len;i++)
        buildSuffixTree(&root,inputStr+i);


    return 0;
}
