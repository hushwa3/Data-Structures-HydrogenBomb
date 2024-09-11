#include <stdio.h>

#define MAX_SIZE 100

void add_element(int numbers[], int *size) {
    if (*size < MAX_SIZE) {
        printf("Enter a number to add: ");
        scanf("%d", &numbers[*size]);
        (*size)++;
        printf("Number added successfully!\n");
    } else {
        printf("Array is full. Cannot add more numbers.\n");
    }
}

void delete_element(int numbers[], int *size) {
    if (*size > 0) {
        int numToDelete;
        printf("Enter the number to delete: ");
        scanf("%d", &numToDelete);
        int found = 0; 

        for (int i = 0; i < *size; i++) {
            if (numbers[i] == numToDelete) {
                for (int j = i; j < *size - 1; j++) {
                    numbers[j] = numbers[j + 1];
                }
                (*size)--;
                found = 1;
                printf("Number %d deleted successfully!\n", numToDelete);
                break;
            }
        }

        if (!found) {
            printf("Number %d not found in the array. Nothing to delete.\n", numToDelete);
        }
    } else {
        printf("Array is empty. Nothing to delete.\n");
    }
}

void display_elements(int numbers[], int size) {
    if (size > 0) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (numbers[j] > numbers[j + 1]) {
                    int temp = numbers[j];
                    numbers[j] = numbers[j + 1];
                    numbers[j + 1] = temp;
                }
            }
        }
        printf("Array elements:\n");
        for (int i = 0; i < size; i++) {
            printf("%d ", numbers[i]);
        }
        printf("\n");
    } else {
        printf("Array is empty. Nothing to display.\n");
    }
}

int main() {
    int numbers[MAX_SIZE];
    int size = 0;
    int choice;

    while (1) {
        printf("\nChoose an operation:\n");
	    printf("1 - Add an element \n");
	    printf("2 - Delete an element \n");
	    printf("3 - Display an element \n");
	    printf("4 - Exit\n");
	    printf("Enter your choice(1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_element(numbers, &size);
                break;
            case 2:
                delete_element(numbers, &size);
                break;
            case 3:
                display_elements(numbers, size);
                break;
            case 4:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    }
    return 0;
}
