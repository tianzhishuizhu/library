// kmp.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void lpsArray(char *pat, int M, int *lps);

void kmp(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;  

    lpsArray(pat, M, lps);

    int i = 0;  
    while (i < N)
    {
      if (pat[j] == txt[i]) {
        j++;
        i++;
      }

      if (j == M) {
        printf("Found pattern at index %d \n", i-j);
        j = lps[j-1];
	  }
      else if (i < N && pat[j] != txt[i]) {
        if (j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    free(lps); 
}

void lpsArray(char *pat, int M, int *lps)
{
    int len = 0;  
    int i;

    lps[0] = 0; 
    i = 1;

    while (i < M) {
       if (pat[i] == pat[len]) {
         len++;
         lps[i] = len;
         i++;
       }
       else 
       {
         if (len != 0) {
           len = lps[len-1];
         }
         else {
           lps[i] = 0;
           i++;
         }
       }
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
   char *txt = "ABABDABACDABABCABAB";
   char *pat = "ABABCABAB";
   kmp(pat, txt);
   return 0;
}

