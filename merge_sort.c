#include <stdio.h>
#include <stdlib.h>
int count;
void merge(int A[10],int l,int m,int r)
{
    int i,j,k,B[10];
    i=l;
    j=m+1;
    k=l;
    while(i<=m && j<=r)
    {
        count++;
        i++;
    }
    while(i<=m)
        B[k++]=A[i++];
    while(j<=r)
        B[k++]=A[j++];
    for(i=l;i<=r;i++)
        A[i]=B[i];
}
void merge_Sort(int A[10],int l,int r)
{
    int m;
    if(l<r)
    {
        m=(l+r)/2;
        merge_sort(A,l,m);
        merge_sort(A,m+1,r);
        merge(A,l,m,r);
    }
}
int main()
{
    int i,n,A[10];
    printf("\nRead Array size: ");
    scanf("%d",&n);
    printf("\nRead array elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    merge_sort(A,0,n-1);
    printf("\nSorted elements are:\n");
    for(i=0;i<n;i++)
        printf("%d\t",A[i]);
    printf("\nTotal number of comparisons= %d",count);
    return 0;
}

