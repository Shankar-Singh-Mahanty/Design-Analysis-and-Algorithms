#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int lb, int ub) {
    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    while (start < end){
    while(arr[start] <= pivot) {
        start++;
    }
    while(arr[end] > pivot){
        end--;
    }
    if(start < end){
        swap(&arr[start], &arr[end]);
    }
    }
    swap(&pivot, &arr[end]);
    return end;
}

void quickSort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int pos = partition(arr, lb, ub);
        quickSort(arr, lb, pos-1);
        quickSort(arr, pos + 1, ub);
    }
}
void printArray(int a[], int size) {
    for (int i = 0; i < size; ++i) {
    printf("%d  ", a[i]);
    }
    printf("\n");
}

int main() {
    int arr[20], n;
    printf("\nEnter the array size: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {   
        printf("a[%d]= ", i);
        scanf("%d", &arr[i]);
    }

	printf("Unsorted array \n");
	printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("\nSorted array in ascending order: \n");
    printArray(arr, n);

	return 0;
}