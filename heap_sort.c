#include <stdio.h>
#include <stdlib.h>
void heapify(int H[10],int n)
{
    int i,j,k,v,heap;
    for(i=n/2;i>=1;i--)
    {
        k=i;
        v=H[k];
        heap=0;
        while(!heap && 2*k<=n)
        {
            j=2*k;
            if(j<n && H[j]<H[j+1])
                j=j+1;
            if(v>=H[j])
                heap=1;
            else
            {
                H[k]=H[j];
                k=j;
            }
            H[k]=v;
        }
    }
}
void heapsort(int H[10],int n)
{
    int i,temp;
    for(i=n;i>1;i--)
    {
        temp=H[1];
        H[1]=H[i];
        H[i]=temp;
        heapify(H,i-1);
    }
}
int main()
{
    int i,n,H[10];
    printf("\nRead array size: ");
    scanf("%d",&n);
    printf("\nRead array elements:\n");
    for(i=1;i<=n;i++)
        scanf("%d",&H[i]);
    heapify(H,n);
    printf("\nElements after heap -\n");
    for(i=1;i<=n;i++)
        printf("%d\t",H[i]);
    heapsort(H,n);
    printf("\nSorted elements are -\n");
    for(i=1;i<=n;i++)
        printf("%d\t",H[i]);
    return 0;
}
