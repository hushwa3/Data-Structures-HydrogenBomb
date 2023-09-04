#include <stdio.h>

void printArray(int arr[]) {
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void deleteNumber(int arr[], int number) {
    int i, j;
    for (i = 0; i < 10; i++) {
        if (arr[i] == number) {
            for (j = i; j < 9; j++) {
                arr[j] = arr[j + 1];
            }
            arr[9] = 0;
            break;
        }
    }
}


int main() {
    int arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int choice, position, number;
    printf("Enter 6 integers:\n");
    for (int i = 0; i < 6; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("These are the values of the Array: ");
    printArray(arr);
    
	do {
        printf("Choose a Number:\n");
        printf("1. Delete a number from the Array\n");
        printf("2. Exit?\n");
        printf("\nInput your choice: \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
            	printf("Enter the number you want to delete: ");
                scanf("%d", &number);
                deleteNumber(arr, number);
                printf("Array elements: ");
                printArray(arr);
                break;
            case 2:
                printf("Byee...for now...\n");
                break;
            default:
                printf("Invalid\n");
                break;
        }
    } while (choice != 2);
    return 0;
}
