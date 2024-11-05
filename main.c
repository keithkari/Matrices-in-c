#include <stdio.h>

void printMatrix(int matrix[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[2][2], i, j;
    int c[2];
    double aws[2];
    double inverse[2][2];
    double determinant;
    char choice;

    do {
        printf("\n\nEnter the 4 elements of the 2x2 matrix A:\n");
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                scanf("%d", &a[i][j]);
            }
        }

        printf("\n\nEnter the 2 elements of the constant matrix B:\n");
        for (i = 0; i < 2; i++) {
            scanf("%d", &c[i]);
        }

        // Calculate determinant
        determinant = a[0][0] * a[1][1] - a[1][0] * a[0][1];
        if (determinant == 0) {
            printf("\nThe matrix is singular and cannot be inverted.\n");
            printf("Do you want to continue (Y/N)? ");
            scanf(" %c", &choice);
            continue;
        }

        printf("\nDeterminant of 2x2 matrix is: %0.2f\n", determinant);

        // Calculate inverse matrix
        inverse[0][0] = a[1][1] / determinant;
        inverse[0][1] = -a[0][1] / determinant;
        inverse[1][0] = -a[1][0] / determinant;
        inverse[1][1] = a[0][0] / determinant;

        printf("\nInverse matrix is:\n");
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                printf("%0.2f ", inverse[i][j]);
            }
            printf("\n");
        }

        // Multiply inverse matrix with B
        for (i = 0; i < 2; i++) {
            aws[i] = 0;
            for (j = 0; j < 2; j++) {
                aws[i] += inverse[i][j] * c[j];
            }
        }

        printf("\nResult: x = %0.2f, y = %0.2f\n", aws[0], aws[1]);

        printf("Do you want to continue (Y/N)? ");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');

    return 0;
}
