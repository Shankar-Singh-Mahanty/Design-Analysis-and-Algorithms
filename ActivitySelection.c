#include <stdio.h>
#include <conio.h>

void sort(int activities[][2], int size){
    int i, j, keys[] = { 0, 0 };
    for (i = 1; i < size; i++){
        keys[0] = activities[i][1];
        keys[1] = activities[i][0];
        j = i - 1;

        while ((j >= 0) && (activities[j][1] > keys[0])){
            activities[j + 1][1] = activities[j][1];
            activities[j + 1][0] = activities[j][0];
            j = j - 1;
        }
        activities[j + 1][1] = keys[0];
        activities[j + 1][0] = keys[1];
    }
}
int main(){
    int i = 0, j = 0, num_inputs = 0;
    printf("Enter the number of inputs = ");
    scanf("%d", &num_inputs);
    printf("\nNOTE: \"Starting time S[1]\" is the starting time of activity one...\n");
    printf("\t\t\t || AND ||\n");
    printf("      \"Finishing time F[1]\" is the finishing time of activity one...\n\n");

    int activities[num_inputs][2];
    for (i = 0; i < num_inputs; i++){
        for (j = 0; j < 2; j++){
            if (j == 0)
            {
                printf("Starting time S[%d] = ", i + 1);
            }
            else
            {
                printf("Finishing time F[%d] = ", i + 1);
            }
            scanf("%d", &activities[i][j]);
        }
    }
    sort(activities, num_inputs);
    printf("\nSorting activities by their finishing time...\n\n");

    for (i = 0; i < num_inputs; i++){
        for (j = 0; j < 2; j++){
            if (j == 0)
            {
                printf("Starting time S[%d] = %d\n", i + 1, activities[i][j]);
            }
            else
            {
                printf("Finishing time F[%d] = %d\n", i + 1, activities[i][j]);
            }
        }
    }
    printf("\nSelected activities = { ");
    j = 0;        // activity that ends first...
    printf("%d", j + 1);    // adding one (+1) with the index number because, activity (j + 1) is in index j...

    for (i = 1; i < num_inputs; i++){
        if (activities[i][0] >= activities[j][1])
        {
            printf(", %d", i + 1);    // adding one (+1) with the index number because, activity (i + 1) is in index i...
            j = i;
        }
    }
    printf(" }");
    getch();

    return 0;
}