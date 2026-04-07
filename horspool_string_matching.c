#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256
int Table[SIZE];
void shift_table(char p[10])
{
    int i,m;
    m=strlen(p);
    for(i=0;i<SIZE;i++)
        Table[i]=m;
    for(i=0;i<=m-2;i++)
        Table[p[i]]=m-1-i;
}
int horspool(char t[50],char p[10])
{
    int i,m,k,n;
    shift_table(p);
    n=strlen(t);
    m=strlen(p);
    i=m-1;
    while(i<=n-1)
    {
        k=0;
        while(k<m && p[m-1-k]== t[i-k])
            k=k+1;
        if(k==m)
            return i-m+1;
        else
            i=i+Table[t[i]];
    }
    return -1;
}
int main()
{
    char t[50],p[10];
    int pos=-1;
    printf("\nRead Text -\n");
    scanf("%s",t);
    printf("\nRead Pattern -\n");
    scanf("%s",p);
    pos=horspool(t,p);
    if(pos==-1)
        printf("\nPattern not found");
    else
        printf("\nPattern found at %d",pos);
    return 0;
}
