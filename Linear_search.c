#include<stdio.h>

int linearsearch(int arr[], int n, int key) {
    for(int i=0;i<n;i++) {
        if(arr[i]==key) {
            return i;
        }
    }
    return -1;
}
int main() {
    int arr[100], n, key, pos;
    printf("\nEnter the array size: ");
    scanf("%d",&n);
    printf("Enter %d elements into array:-\n",n);
    for(int i=0;i<n;i++) {
        printf("a[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("Enter the search key element: ");
    scanf("%d",&key);
    
    pos = linearsearch(arr, n, key);
    if(pos>=0){
        printf("Element found at %d index and %d position.", pos, pos+1);
    }
    else {
        printf("Element not found !");
    }
    return 0;
}
