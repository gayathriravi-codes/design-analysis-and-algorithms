#include <stdio.h>
#include <stdlib.h>
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main()
{
    int n,W,w[10],p[10],i,j,V[10][10],x[10]={0};
    printf("\nRead the number of objects: ");
    scanf("%d",&n);
    printf("\nRead knapsack capacity: ");
    scanf("%d",&W);
    printf("\nRead the weights of the objects: ");
    for(i=1;i<=n;i++)
        scanf("%d",&w[i]);
    printf("\nRead the profits of the objects: ");
    for(i=1;i<=n;i++)
        scanf("%d",&p[i]);
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=W;j++)
        {
            if(i==0 || j==0)
                V[i][j]=0;
            else if(j-w[i]<0)
                V[i][j]=V[i-1][j];
            else
                V[i][j]=max(V[i-1][j],V[i-1][j-w[i]]+p[i]);
            printf("%d\t",V[i][j]);
        }
        printf("\n");
    }
    return 0;
}
