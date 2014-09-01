#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void getNext(char *p, int len, int *next)
{
    int j = 0;
    int q = -1;
    //int len = strlen(p);
    //next = (int *)malloc(sizeof(int)*len);

    next[j] = q;

    while (j < len-1)
    {
        if (q==-1 || p[q] == p[j])
        {
            ++q;
            ++j;
            if (p[q] != p[j])
                next[j] = q;
            else
                next[j] = next[q];
        }
        else
        {
            q = next[q];
        }
    }
}

int kmp(char *p, char *s)
{
    int plen = strlen(p);
    int slen = strlen(s);
    int n = 0;
    int i = 0;
    int *next = (int *)malloc(sizeof(int)*plen);
    getNext(p, plen, next);
    
    while (i < slen-1)
    {
        if (n==-1 || p[n] == s[i])
        {
            ++n;
            ++i;
        }
        else
            n = next[n];
        if (n == plen-1)
            return 1;
    }
    printf("%d\n", n);
    return n==plen-1;
}

int main()
{
    char *p = "ababaca";
    char *t = "bacbababacaabcbab";
    int i,j;
    int len = strlen(p);
    int *next = (int *)malloc(sizeof(int)*len);
    getNext(p, len, next);
    printf("%s\n", p);
    for (i = 0; i<len; ++i)
        printf("%d, ", next[i]);
    printf("\n");
    int r = kmp(p, t);
    if (r)
        printf("true\n");
    else
        printf("false\n");
    return 0;
}
