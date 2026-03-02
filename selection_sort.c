#include<stdio.h>
#include<stdlib.h>
int count;
void selection_sort(int A[10],int n)
{
    int i,j,temp,min;
    for(i=0;i<=n-2;i++)
    {
        min=i;
        for(j=i+1;j<=n-1;j++)
        {
            count=count+1;
            if(A[j]<A[min])
                min=j;
        }
        temp=A[i];
        A[i]=A[min];
        A[min]=temp;
    }
}
int main()
{
    int n,i,A[10];
    printf("\nRead array size: ");
    scanf("%d",&n);
    printf("\nRead the array elements: \n");
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    selection_sort(A,n);
    printf("\nThe sorted elements are: \n");
    for(i=0;i<n;i++)
        printf("%d\t",A[i]);
    printf("\nTotal number of comparisons= %d",count);
    return 0;
}
