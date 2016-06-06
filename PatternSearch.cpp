#include<stdio.h>
#include<string.h>
#include<malloc.h>

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


int main()
{
   
   const char *pat = "ABABACA";
   int M = strlen(pat);
   int *lps = (int *)malloc(sizeof(int)*M);
   int j  = 0;  
   computeLPSArray(pat, M, lps);
   for(j=0;j<M;j++)
	   printf( "%d," , lps[j] );
   
   return 0;
}



