#include<stdio.h>

void swap(int* a, int* b)
{
 
    int temp = *a;
 
    *a = *b;
 
    *b = temp;
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

void max_heapify(int a[], int n, int i)
{
    int largest = i;
    int l = (2*i)+1;
    int r = (2*i)+2;

    while(l < n && a[l] > a[largest]){
        largest = l;
    }
    while(r < n && a[r] > a[largest])
    {
        largest = r;
    }

    if(largest != i){
        swap(&a[i], &a[largest]);
        max_heapify(a, n, largest);
    }    
}

void heapSort(int a[], int n)
{
    //for creating a max heap
    for(int i = n/2-1; i >= 0; i--){
        max_heapify(a, n, i);
    }

    //for deletion in max heap so that the array will be sorted
    for(int i =n-1; i >= 0; i--){
        swap(&a[0], &a[i]);
        max_heapify(a, i, 0);
    }
    
    printArray(a, n);
}

int main()
{
    int a[100], n, i;
    scanf("%d",&n);
    for(i=0; i<n; i++) scanf("%d", &a[i]);
    heapSort(a, n);
}