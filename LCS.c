#include <stdio.h>
#include <string.h>

// Function to find the longest common subsequence of two strings
void longest_common_subsequence(char* str1, char* str2, int m, int n) {
    int lcs_matrix[m+1][n+1];
    int i, j;

    // Initialize the matrix to store LCS lengths
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                lcs_matrix[i][j] = 0;
            } else if (str1[i-1] == str2[j-1]) {
                lcs_matrix[i][j] = lcs_matrix[i-1][j-1] + 1;
            } else {
                lcs_matrix[i][j] = (lcs_matrix[i-1][j] > lcs_matrix[i][j-1]) ? 
                lcs_matrix[i-1][j] : lcs_matrix[i][j-1];
            }
        }
    }

    // Extract the LCS from the matrix
    int index = lcs_matrix[m][n];
    char lcs[index+1];
    lcs[index] = '\0';
    i = m;
    j = n;
    while (i > 0 && j > 0) {
        if (str1[i-1] == str2[j-1]) {
            lcs[index-1] = str1[i-1];
            i--;
            j--;
            index--;
        } else if (lcs_matrix[i-1][j] > lcs_matrix[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    // Print the LCS
    printf("\nLongest common subsequence: %s\n", lcs);
}

int main() {
    char str1[100], str2[100];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    int m = strlen(str1);
    int n = strlen(str2);

    longest_common_subsequence(str1, str2, m, n);

    return 0;
}