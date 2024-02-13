#include<stdio.h>

void mergearray();

void merge(int a[], int lb, int mid, int ub)
{
    int i, j, k, b[100];
    i = lb; j = mid+1; k = lb;
    while(i <= mid && j <= ub){
        if(a[i] <= a[j]){
            b[k] = a[i];
            i++;
        }
        else{
            b[k] = a[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=ub){
            b[k] = a[j];
            j++; k++;
        }
    }
    else{
        while(i<=mid){
            b[k] = a[i];
            i++; k++;
        }
    }
    for(k=lb; k<=ub; k++) a[k] = b[k];
}

void mergeSort(int a[], int lb, int ub)
{
    int mid;
    if(lb<ub){
        mid = (lb+ub)/2;
        mergeSort(a, lb, mid);
        mergeSort(a, mid+1, ub);
        merge(a, lb, mid, ub);
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
    mergeSort(a, 0, n-1);
    printArray(a, n);
}