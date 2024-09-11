#include <stdio.h>

void printArray(int arr[]) {
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void deleteArray(int arr[], int pos) {
    int i;
    for (i = pos - 1; i < 9; i++) {
        arr[i] = arr[i + 1];
    }
    arr[9] = 0;
}

int main(){
	int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0 , 0};
    int choice, pos, number;
    
    printf("Enter 6 integers:\n");
    for (int i = 0; i < 6; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("These are the values of the Array: ");
    printArray(arr);
    
    while (1) {
        printf("Choose an option:\n");
        printf("1. Delete\n");
        printf("2. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice) {
        	case 1:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteArray(arr, pos);
                printf("Array elements after deleting: ");
                printArray(arr);
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        if (choice == 2) {
            break;
        }
    }
}

