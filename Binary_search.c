#include<stdio.h>

int binsearch(int arr[], int key, int low, int high);
int main()
{
    int num, key, pos;
    int low, high, list[100];
    printf("Enter the total number of elements: ");
    scanf("%d", &num);
    printf("Enter %d elements in ascending order:-\n", num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &list[i]);
    }
    low = 0;
    high = num - 1;
    printf("Enter element to be searched: ");
    scanf("%d", &key);
    pos = binsearch(list, key, low, high);
    if (pos != -1) {
        printf("Number present %d index and at %d position.", pos, (pos + 1));
    }
    else
    {
        printf("The number is not present in the list !");
    }
    return 0;
}
// Binary Search function
int binsearch(int arr[], int key, int low, int high) {
    int mid;
    if (low > high){
        return -1;
    }
    mid = (low + high) / 2;
    if (key == arr[mid]) {
        return (mid);
    }
    else if (key < arr[mid]) {
        binsearch(arr, key, low, mid - 1);
    }
    else
    {
        binsearch(arr, key, mid + 1, high);
    }
}