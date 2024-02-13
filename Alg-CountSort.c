#include<stdio.h>

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

int maximum(int a[], int n)
{
    int max = a[0], i;
    for(i=1; i<n; i++){
        if(a[i]>max) max = a[i];
    }
    return max;
}

void countSort(int a[], int n, int k)
{
    int count[k+1], b[n], i;
    for(i=0; i<n; i++)
    {
        ++count[a[i]];
    }

    for(i=0; i<k; i++)
    {
        count[i] = count[i] + count[i-1];
    }

    for(i=n-1; i>=0; i--)
    {
        b[--count[a[i]]] = a[i];
    }

    for(i=0; i<n; i++)
    {
        a[i] = b[i];
    }
    printArray(a, n);
}

int main()
{
    int n, a[1000], i, max;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &a[i]);
    max = maximum(a, n);
    printf("The array before sorting:\n");
    printArray(a, n);
    printf("The array after sorting:\n");
    countSort(a, n, max);
}