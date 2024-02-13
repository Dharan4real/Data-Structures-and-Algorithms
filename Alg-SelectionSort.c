#include<stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int a[], int n)
{
    int min, i, j;
    for(i=0; i<n-1; i++){
        min = i;
        for(j=i+1; j<n; j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        if(min != i){
            swap(&a[i], &a[min]);
        }
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
    int n, a[1000], i;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &a[i]);
    printf("The array before sorting:\n");
    printArray(a, n);
    selectionSort(a, n);
    printf("The array after sorting:\n");
    printArray(a, n);

}