#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion_sort(int arr[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bucket_sort(int arr[], int num) {
    const int max_buckets = 10;
    int buckets[max_buckets][num];
    int bucket_sizes[max_buckets];

    for (int i = 0; i < max_buckets; i++) {
        bucket_sizes[i] = 0;
    }

    for (int i = 0; i < num; i++) {
        int bucket_index = arr[i] / max_buckets;
        buckets[bucket_index][bucket_sizes[bucket_index]++] = arr[i];
    }
    
    int index = 0;
    for (int i = 0; i < max_buckets; i++) {
        insertion_sort(buckets[i], bucket_sizes[i]);
        for (int j = 0; j < bucket_sizes[i]; j++) {
            arr[index++] = buckets[i][j];
            display(arr, num);
        }
    }
}

int main() {
    int choice, num;

    do {
        printf("\nChoose an operation of your choice:\n\n");
        printf("(1) Bucket sort.\n");
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
                printf("Bucket sort:\n");
                bucket_sort(arr, num);
                printf("Sorted array: ");
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
