#include <stdio.h>
#include <stdlib.h>

int w[10], x[10], d, n;

void sum_of_subsets(int s, int k, int r)
{
    int i;
    static int count = 1;

    if (k > n) return;   

    x[k] = 1;

    if (s + w[k] == d)
    {
        printf("\nSolution %d = ", count++);
        for (i = 1; i <= k; i++)
        {
            if (x[i] == 1)
                printf("%d ", w[i]);
        }
    }
    else if (k < n && s + w[k] + w[k+1] <= d)
    {
        sum_of_subsets(s + w[k], k + 1, r - w[k]);
    }

    if (k < n && (s + r - w[k] >= d) && (s + w[k+1] <= d))
    {
        x[k] = 0;
        sum_of_subsets(s, k + 1, r - w[k]);
    }
}

int main()
{
    int i, sum = 0;

    printf("Read number of elements: ");
    scanf("%d", &n);

    printf("Read elements in ascending order:\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
        x[i] = 0;   
        sum += w[i];
    }

    printf("Read value for d: ");
    scanf("%d", &d);

    sum_of_subsets(0, 1, sum);

    return 0;
}
