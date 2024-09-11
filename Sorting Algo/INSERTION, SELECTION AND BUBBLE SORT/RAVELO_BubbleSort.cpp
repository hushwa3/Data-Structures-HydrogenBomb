#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int index = n - 1;
        printf("if i = %d\n", i);
		printf("Pass %d:\n", i + 1);

        while (index >= (i + 1)) {
            if (arr[index - 1] > arr[index]) {
                int temp = arr[index];
                arr[index] = arr[index - 1];
                arr[index - 1] = temp;
            }
            index = index - 1;

            printf("\t");
            for (int j = 0; j < n; j++) {
                printf("%d ", arr[j]);
            }
            printf("\n");
        }
    }
}

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, num;

    do {
        printf("\nChoose an operation of your choice:\n\n");
        printf("(1) Bubble sort.\n");
        printf("(2) Exit\n");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 2) {
            printf("Exiting...\n");
            break;
        }

        printf("\nHow many numbers do you want to input: ");
        scanf("%d", &num);

        int *arr = (int *)malloc(num * sizeof(int));

        printf("Insert the numbers: \n");
        for (int i = 0; i < num; i++) {
            scanf("%d", &arr[i]);
        }

        switch (choice) {
            case 1:
                bubble_sort(arr, num);
                printf("Sorted array using Bubble Sort: ");
                display(arr, num);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        free(arr);
    } while (choice != 2);
    return 0;
}
