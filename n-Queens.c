#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int x[10], count = 1;
void print(int n)
{
    int i, j;
    printf("\nSolution = %d\n", count++);
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(x[j] == i)
                printf("\tQ");
            else
                printf("\t_");
        }
        printf("\n");
    }
}
int place(int k, int i)
{
    int j;
    for(j = 1; j <= k - 1; j++)
    {
        if((x[j] == i) || (abs(x[j] - i) == abs(j - k)))
            return 0;
    }
    return 1;
}
void nQueens(int k, int n)
{
    int i;
    for(i = 1; i <= n; i++)   // corrected
    {
        if(place(k, i))
        {
            x[k] = i;
            if(k == n)
                print(n);
            else
                nQueens(k + 1, n);
        }
    }
}
int main()
{
    int n;
    printf("\nRead the number of Queens: ");
    scanf("%d", &n);
    if(n == 1 || n == 2 || n == 3)
        printf("\nNo solution");
    else
        nQueens(1, n);
    return 0;
}
