#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);

        printf("Quick Sort Pass (low=%d, high=%d): ", low, high);
        display(arr + low, high - low + 1);
    }
}

int main() {
    int choice, num;
    int *arr;

    do {
        printf("\nChoose an operation of your choice:\n\n");
        printf("(1) Quick Sort.\n");
        printf("(2) Exit\n");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nHow many numbers do you want to input: ");
                scanf("%d", &num);

                arr = (int *)malloc(num * sizeof(int));

                printf("Insert the numbers: \n");
                for (int i = 0; i < num; i++) {
                    scanf("%d", &arr[i]);
                }

                printf("Quick sort:\n");
                quick_sort(arr, 0, num - 1);
                printf("Sorted array: ");
                display(arr, num);

                free(arr);
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    } while (choice != 2);

    return 0;
}
