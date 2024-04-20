#include <stdio.h>
#include <stdlib.h>

void merge(int A[], int l , int mid , int h)
{
    int i=l, j=mid+1, k=l;
    int B[100];
    while (i<=mid && j<=h)
    {
        if(A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
    }
    for(;i<=mid;i++)
        B[k++]=A[i];
    for(;j<=h;j++)
        B[k++]=A[j];
    for(i=l;i<=h;i++)
        A[i]=B[i];
}

void MergeSort(int A[], int n)
{
    int p,l,h,mid,i;
    for(p=2;p<=n;p=p*2)
    {
        for(i=0;i+p-1<n;i=i+p)
        {
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            merge(A, l, mid, h);
        }
        if(n-i>p/2)
        {
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            merge(A, l, mid, n-1);
        }
    }
    if(p/2<n)
    {
        merge(A,0,p/2-1,n-1);
    }
}

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr) {
    printf("\nElements are: ");
    for (int i = 0; i < arr.length; i++) { printf("%d ", arr.A[i]);}
    printf("\n");
}

int BinarySearch(struct Array arr, int key)
{
    int l, mid,h;
    l=0;
    h=arr.length-1;
    while(l>=h)
    {
        mid=l=h/2;
        if(key==arr.A[mid])
            return mid;
        else if(key<arr.A[mid])
            h=mid-1;
        else
            l=mid+1;
    }
    return -1;
}

int main()
{
    struct Array arr = {{2,3,4,5,6},10,5};
    Display(arr);
    printf("%d\n",BinarySearch(arr, 2));
    
//    int A[]={11,5,14,2,6,3,1},n=7,i;
//    MergeSort(A, n);
//    for (i=0;i<n;i++)
//        printf("%d ",A[i]);
//    printf("\n");
    return 0;
}

