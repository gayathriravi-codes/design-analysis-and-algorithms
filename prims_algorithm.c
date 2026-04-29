#include <stdio.h>
#include <stdlib.h>
void prims(int cost[10][10], int n)
{
    int i, j, u, v, mincost = 0, min, x, y;
    int visited[10], ne = 1;

    for (i = 1; i <= n; i++)
        visited[i] = 0;

    visited[1] = 1;

    printf("\n The edges considered are:\n");

    while (ne < n)
    {
        for (i = 1, min = 999; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    if (visited[i] != 0)
                    {
                        min = cost[i][j];
                        x = u = i;
                        y = v = j;
                    }
                }
            }
        }

        if (visited[u] == 0 || visited[v] == 0)
        {
            printf("\n Edge %d, (%d %d) = %d", ne++, x, y, min);
            mincost = mincost + min;
            visited[y] = 1;
        }

        cost[x][y] = cost[y][x] = 999;
    }

    printf("\n The cost of MST is %d", mincost);
}
int main()
{
    int n, i, j, cost[10][10];

    printf("\n Read number of vertices:");
    scanf("%d", &n);

    printf("\n Read the cost matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    prims(cost, n);
    return 0;
}

