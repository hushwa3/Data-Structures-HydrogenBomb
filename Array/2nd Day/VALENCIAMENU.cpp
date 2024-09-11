#include <stdio.h>

void print_array(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int search_array(int arr[], int size, int value) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

void insert_array(int arr[], int *size, int pos, int value) {
    int i;
    for (i = *size - 1; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos - 1] = value;
    (*size)++;
}

void delete_array(int arr[], int *size, int pos) {
    int i;
    for (i = pos - 1; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

int main() {
    int size, i, choice, pos, value;
    printf("Enter array size: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter array elements:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Array elements: ");
    print_array(arr, size);
    do {
        printf("Choose an option:\n");
        printf("1. Search\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &value);
                pos = search_array(arr, size, value);
                if (pos == -1) {
                    printf("Element not found\n");
                } else {
                    printf("Element found at position %d\n", pos + 1);
                }
                break;
            case 2:
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert_array(arr, &size, pos, value);
                printf("Array elements: ");
                print_array(arr, size);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete_array(arr, &size, pos);
                printf("Array elements: ");
                print_array(arr, size);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 4);
    return 0;
}
