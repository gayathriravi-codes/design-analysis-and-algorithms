#include <stdio.h>
#include <stdlib.h>
int topo[10],k;
void dfs(int a[10][10],int n, int visited[10],int source)
{
    int i;
    visited[source]=1;
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0 && a[source][i]==1)
            dfs(a,n,visited,i);
    }
    topo[++k]=source;
}
int main()
{
   int n, i,j,a[10][10],visited[10];
   printf("\nRead number of nodes: ");
   scanf("%d",&n);
   printf("\nRead adjaceny matrix:\n");
   for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
           scanf("%d",&a[i][j]);
   for(i=1;i<=n;i++)
       visited[i]=0;
   for(i=1;i<=n;i++)
   {
       if(visited[i]==0)
          dfs(a,n,visited,i);
   }
   printf("\nTopological ordering is \n");
   for(i=k;i>=1;i--)
       printf("%d\t",topo[i]);
   return 0;
}
