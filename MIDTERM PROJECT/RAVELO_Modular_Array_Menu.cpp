#include <stdio.h>
#include <stdlib.h>

// Function to add an element to the array and arrange elements in ascending order
void addElement(int arr[], int *size, int num) {
    int i, j;
    // Add the element at the end of the array
    arr[*size] = num;
    (*size)++;

    // Arrange the elements in ascending order using insertion sort
    for (i = 1; i < *size; i++) {
        int key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to delete an element from the array
void deleteElement(int arr[], int *size, int pos) {
    if (pos < 0 || pos >= *size) {
        printf("Invalid position!\n");
    } else {
        for (int i = pos; i < *size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*size)--;
    }
}

// Function to display all array elements
void displayAllElements(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
    } else {
        printf("Array elements:\n");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int size = 0, choice, pos, value;
    printf("Enter array size: ");
    scanf("%d", &size);
    int arr[size];
    int num; // Declare num to store the item to be inserted or deleted

    do {
        printf("Choose an operation:\n");
        printf("1 - Add an element \n");
        printf("2 - Delete an element \n");
        printf("3 - Display all elements \n");
        printf("4 - Exit\n");
        printf("Enter your choice(1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to be inserted: ");
                scanf("%d", &num);
                addElement(arr, &size, num);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteElement(arr, &size, pos);
                break;
            case 3:
                displayAllElements(arr, size);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid choice (1-4).\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
