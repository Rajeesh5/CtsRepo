#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<ctype.h>
#include<math.h>
#define VAL_TO_INDX(c) ((int)c - 65 +1)

void computeLPSArray(const char *pat, int M, int *lps)
{
    int len = 0,i=1;
    lps[0] = 0;

    while (i < M)
    {
       if (pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else
       {
         if (len != 0)
            len = lps[len-1];
         else
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}
void bruteMethod(const char *txt,const char *pat)
{
    int lenTxt=strlen(txt),i,j=0;
    int lenPat=strlen(pat);
    for(i=0;i<lenTxt;i++)
    {
        j=0;
        while(txt[i]==pat[j])
        {
            j++;
            i++;
        }
        if(j==lenPat){ printf("found Match at Location =%d\n",i-j); i--;}
        else if(j>0)i=i-j;

    }
}

void karpMatcher(const char *txt,const char *pat)
{
    int primeFactor=3,patternValue=0,txtValue=0,i=0,j=0;
    int pattLen=strlen(pat);
    int txtLen =strlen(txt);
    while(i < pattLen)
    {
        patternValue +=  pow(primeFactor,i) * VAL_TO_INDX(toupper(pat[i])) ;
        txtValue     +=  pow(primeFactor,i) * VAL_TO_INDX(toupper(txt[i])) ;
        i++;
    }

    i=0;
    while(i+pattLen-1 < txtLen)
    {
        if(patternValue==txtValue)
        {
            printf("pattern Found at location %d = ",i);
            i++;
            continue;
        }
        txtValue=txtValue - VAL_TO_INDX(toupper(txt[i-1]));
        txtValue=txtValue / primeFactor;
        txtValue=txtValue + pow(primeFactor,pattLen-1) * VAL_TO_INDX(toupper(txt[i+pattLen-1]));
        i++;
    }

}

int main()
{
   const char *str="ABBABB";
   const char *pat = "AAB";
   /*
   int M = strlen(pat);
   int *lps = (int *)malloc(sizeof(int)*M);
   int j  = 0;
   computeLPSArray(pat, M, lps);
   for(j=0;j<M;j++)
	   printf( "%d," , lps[j] );
   */

   //bruteMethod(str,pat);

    karpMatcher(str,pat);



   return 0;
}



