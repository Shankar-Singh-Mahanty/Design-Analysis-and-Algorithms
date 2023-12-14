#include<stdio.h>
#include<limits.h>

int minCost[10][10];
int key[10][10];
int p[10], i, j, n;
// function declaration
int matrixChainOrder(int p[], int n);
void print_optimal(int i, int j);

int main() {
    printf("Enter the number of matrix: ");
    scanf("%d", &n);
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            minCost[i][i]=0;
            minCost[i][j]= -1;
            key[i][j]=0;
        }
    }
    printf("Enter the dimensions of the matrices:-\n");
    for (int i = 0; i <= n; i++) {
        printf("p[%d] = ", i);
        scanf("%d", &p[i]);
    }

    int minMultiplications = matrixChainOrder(p, n);
    printf("Minimum number of scalar multiplications: %d\n", minMultiplications);

        i = 1, j = n;
        printf("\nMultiplication sequence is: ");
        print_optimal(i, j);    // function call

    return 0;
}
// function defination to find minimum number of scalar multiplication
int matrixChainOrder(int p[], int n) {
    if(n <= 1) {    // Base case: if there is only one matrix, there are
        printf("No Scalar Multiplication Needed.");
        return 0;
    }
    else if(n == 2) {    // Base case: if there are two matrices
        printf("There is only one way to multiply them.");
        return p[0] *  p[1] * p[2];
    }
    else {
        // Creation of a table to store the minimum number of
        // scalar multiplications needed to multiply the matrices i, i+1, ..., j
        int count;
        int k, d;
        minCost[i][j] = 0;  // Initialization of the table with 0's
        key[i][j] = 0;
//  d is the difference between i and j in digonal insertion
        for(d = 1; d < n-1; d++) {
            for(i = 1; i < n-d; i++) {
                j = i + d;
                minCost[i][j] = -1;
                for(int k =  1; k <= j-1; k++) {
                    count = minCost[i][k] + minCost[k+1][j] + p[i-1] * p[k] * p[j];
                    if (count < minCost[i][j]) {
                        minCost[i][j] = count;
                        key[i][j] = k;
                    }
                }
            }
        }   // returning minimum number of scalar multiplication
        return minCost[1][n-1];
    }
}

void print_optimal(int i, int j) {  // Parenthesization by inorder traversing
    if(i == j) {
        printf(" A%d ", i);
    }
    else {
        printf("( ");
        print_optimal(i, key[i][j]);        
        print_optimal(key[i][j] + 1, j);        
        printf(" )");
    }
}