#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int arr[], int n) {
   for (int i = 1; i < n; i++) {
     int key = arr[i];
     int j = i - 1;
     printf("\nif i = %d\n", i);
     printf("Pass %d:\n", i);

     while (j >= 0 && arr[j] > key) {
       arr[j + 1] = arr[j];
       j = j - 1;
     }

     arr[j + 1] = key;

     printf("\t");
     for (int k = 0; k < n; k++) {
       printf("%d ", arr[k]);
     }
     printf("\n");
   }
}

void selection_sort(int arr[], int n) {
   for (int i = 0; i < n - 1; i++) {
     int min_index = i;
     printf("\nif i = %d\n", i);
     printf("Pass %d:\n", i + 1);

     for (int j = i + 1; j < n; j++) {
       if (arr[j] < arr[min_index]) {
         min_index = j;
       }
     }

     int temp = arr[min_index];
     arr[min_index] = arr[i];
     arr[i] = temp;

     printf("\t");
     for (int k = 0; k < n; k++) {
       printf("%d ", arr[k]);
     }
     printf("\n");
   }
}

void bubble_sort(int arr[], int n) {
   for (int i = 0; i < n - 1; i++) {
     int index = n - 1;
     printf("\nif i = %d\n", i);
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
     printf("(1) Insertion sort.\n");
     printf("(2) Selection sort.\n");
     printf("(3) Bubble sort.\n");
     printf("(4) Exit\n");
     printf("\n\nEnter your choice: ");
     scanf("%d", &choice);

     if (choice == 4) {
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
         insertion_sort(arr, num);
         printf("\n\nSorted array using Insertion Sort: ");
         display(arr, num);
         break;
       case 2:
         selection_sort(arr, num);
         printf("Sorted array using Selection Sort: ");
         display(arr, num);
         break;
       case 3:
         bubble_sort(arr, num);
         printf("Sorted array using Bubble Sort: ");
         display(arr, num);
       default:
         printf("Invalid choice\n");
         break;
     }
     free(arr);
   } while (choice != 4);
   return 0;
}
