#include <stdio.h>

int SequentialSearch(int A[], int n, int find) {
    for (int i = 0; i < n; i++) {
        if (A[i] == find) {
            return i;
        }
    }
    return -1;
}

int main() {
    int A[10];
    int i, j, find, index;

    for (i = 0; i < 10; i++) {
        printf("Enter integers 1-10 (#%d): ", i + 1);
        scanf("%d", &A[i]);
    }

    printf("\nEnter the integer to search for: ");
    scanf("%d", &find);

    index = SequentialSearch(A, 10, find);

    if (index == -1) {
        printf("The integer %d was not found in the array.\n", find);
    } else {
        printf("The integer %d was found at index %d.\n", find, index);
    }

    printf("Do you want to continue? (1 = Yes | 0 = No): ");
    scanf("%d", &j);
    printf("\n");

    if (j == 1) {
        main(); // Recursive call to main if user wants to continue
    }

    return 0; // Return 0 to indicate successful program execution
}

