//
//  main.c
//  Longest-common-subsequence
//
//  Created by Md Moinuddin Quazi on 4/21/24.
//

#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}


int lcs(char * X, char* Y, int i, int j)
{
    if(X[i] == 0 || Y[j] == 0)
        return 0;
    if(X[i] == Y[j])
        return 1 + lcs(X, Y, i + 1, j + 1);
    else
        return max(lcs(X, Y, i, j + 1), lcs(X, Y, i + 1, j));
}

int main()
{
    char S1[] = "BD";
    char S2[] = "ABCD";
    int m = strlen(S1);
    int n = strlen(S2);
    int i = 0, j = 0;
    printf("Length=%d\n Length=%d\n",m,n);
    printf("Length of LCS=%d\n",lcs(S1, S2, i, j));
    return 0;
}
