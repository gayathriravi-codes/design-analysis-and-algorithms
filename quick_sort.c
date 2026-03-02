#include <stdio.h>
#include <stdlib.h>
int count;
int partition(int A[10],int l,int r)
{
    int i,j,temp,pivot;
    pivot=A[l];
    i=l+1;
    j=r;
    while(1)
    {
        while(i<=r  && pivot>=A[i])
        {
            count++;
            i++;
        }
        while(j>=l && pivot<A[j])
        {
            count++;
            j--;
        }
        if(i<j)
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
        else
        {
            temp=A[l];
            A[l]=A[j];
            A[j]=temp;
            return j;
        }
    }
}
void quick_sort(int A[10],int l,int r)
{
    int s;
    if(l<r)
    {
        s=partition(A,l,r);
        quick_sort(A,l,s-1);
        quick_sort(A,s+1,r);
    }
}
int main()
{
    int i,n,A[10];
    printf("\nRead array size: ");
    scanf("%d",&n);
    printf("\nRead array elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    quick_sort(A,0,n-1);
    printf("\nThe sorted elements are:\n ");
    for(i=0;i<n;i++)
        printf("%d\t",A[i]);
    printf("\nTotal number of comparisions=%d",count);
    return 0;
}
