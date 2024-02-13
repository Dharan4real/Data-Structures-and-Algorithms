#include<stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int lb, int ub)
{
    int pivot, start, end;
    pivot = lb;
    start = lb;
    end = ub;
    while(start<end){
        while(a[start]<=a[pivot]){
            start++;
        }
        while(a[end]>a[pivot]){
            end--;
        }
        if(start<end){
            swap(&a[start], &a[end]);
        }
    }
    swap(&a[pivot], &a[end]);
    return end;
}

void quicksort(int a[], int lb, int ub)
{
    int loc;
    if(lb<ub){
        loc = partition(a, lb, ub);
        quicksort(a, lb, loc-1);
        quicksort(a, loc+1, ub);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int a[100], n, i;
    scanf("%d",&n);
    for(i=0; i<n; i++) scanf("%d", &a[i]);
    quicksort(a, 0, n-1);
    printArray(a, n);
}