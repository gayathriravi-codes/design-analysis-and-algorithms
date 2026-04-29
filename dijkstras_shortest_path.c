#include <stdio.h>
#include <stdlib.h>
void dijkstras(int cost[10][10],int n,int source,int dist[10])
{
    int i,visited[10],min,v,count=1;
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
        dist[i]=cost[source][i];
    }
    dist[source]=0;
    visited[source]=1;
    while(count<=n)
    {
        min=999;
        for(i=1;i<=n;i++)
            if (dist[i]<min && visited[i]==0)
            {
                min=dist[i];
                v=i;
            }
        visited[v]=1;
        count++;
        for(i=1;i<=n;i++)
            if (dist[i]>dist[v]+cost[v][i])
                dist[i]=dist[v]+cost[v][i];
    }
}
int main()
{
    int i, j,n,cost[10][10],source,dist[10];
    printf("\nRead the number of vertex: ");
    scanf("%d",&n);
    printf("\nRead the cost matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }
    printf("\nRead source vertex: ");
    scanf("%d",&source);
    dijkstras(cost,n,source,dist);
    for(i=1;i<=n;i++)
    {
        if(source!=i)
            printf("\nThe shortest path from %d to %d is %d",source,i,dist[i]);
    }
    return 0;
}
