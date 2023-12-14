#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int knapSackRecursive(int W, int wt[], int val[], int n){
    if (n == 0 || W == 0) return 0;
    else if (wt[n-1] > W) return knapSackRecursive(W, wt, val, n-1);
    else return MAX(
        val[n-1] + knapSackRecursive(W-wt[n-1], wt, val, n-1),
        knapSackRecursive(W, wt, val, n-1)
    );
}
int main(){
    int W, n, i;
    int val[50];
    int wt[50];
    printf("Enter the number of objects: ");
    scanf("%d", &n);
    printf("Enter the Capacity of the knapsack: ");
    scanf("%d", &W);
    printf("-: Enter the details :-\n");
    for(i = 0; i< n; i++){
        printf("Enter the value of object %d: ", i+1);
        scanf("%d", &val[i]);
        printf("Enter its weight: ");
        scanf("%d", &wt[i]);
    }
    int max_value = knapSackRecursive(W, wt, val, n);
    printf("============================\n");
    printf("Maximum value that can be put in knapsack is: %d\n", max_value);

    return 0;
}