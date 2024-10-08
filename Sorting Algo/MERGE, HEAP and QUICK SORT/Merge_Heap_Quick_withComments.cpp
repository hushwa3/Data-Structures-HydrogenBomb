#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// Function to perform merge operation in merge sort
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);

    // Print pass
    printf("Merge Sort Pass (left=%d, right=%d): ", left, right);
    display(arr + left, right - left + 1);
  }
}


// Function to perform heapify operation in heap sort
void heapify(int arr[], int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  for (int i = n - 1; i > 0; i--) {
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;

    heapify(arr, i, 0);

    // Print pass
    printf("Heap Sort Pass (%d): ", n - i);
    display(arr, n);
  }
}

// Function to perform partition operation in quicksort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot element
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i + 1] and arr[high] (pivot)
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

    // Print pass
    printf("Quick Sort Pass (low=%d, high=%d): ", low, high);
    display(arr + low, high - low + 1);
  }
}

int main() {
    int choice, num;

    do {
        printf("\nChoose an operation of your choice:\n\n");
        printf("(1) Merge sort.\n");
        printf("(2) Heap sort.\n");
        printf("(3) Quick sort.\n");
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
                printf("Merge sort:\n");
                merge_sort(arr, 0, num - 1);
                printf("Sorted array: ");
                display(arr, num);
                break;
            case 2:
                printf("Heap sort:\n");
                heap_sort(arr, num);
                printf("Sorted array: ");
                display(arr, num);
                break;
            case 3:
                printf("Quick sort:\n");
                quick_sort(arr, 0, num - 1);
                printf("Sorted array: ");
                display(arr, num);
                 break;
            default:
                printf("Invalid choice\n");
                break;
        }
        free(arr);
    } while (choice != 4);

    return 0;
}
