#include <stdio.h>
#include <stdlib.h>
void bfs(int a[10][10],int n,int visited[10],int source)
{
    int q[10],front=0,rear=-1,i,delnode;
    q[++rear]=source;
    visited[source]=1;
    while(front<=rear)
    {
        delnode=q[front++];
        for(i=0;i<n;i++)
        {
            if(a[delnode][i]==1 && visited[i]==0)
            {
                q[++rear]=i;
                visited[i]=1;
            }
        }
    }
}
int main()
{
    int n,a[10][10],i,j,count=0,visited[10];
    printf("\nRead number of nodes: ");
    scanf("%d",&n);
    printf("\nRead adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
        visited[i]=0;
    for(i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            bfs(a,n,visited,i);
            count++;
        }
    }
    if(count==1)
        printf("\nGraph is connected");
    else
        printf("\nGraph is not connected and it has %d components.\n",count);
    return 0;
}
