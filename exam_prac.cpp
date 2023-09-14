#include <stdio.h>

void swap_arrays(int a[], int b[]) {
  int i;
  int temp;

  for (i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
    temp = a[i];
    a[i] = b[i];
    b[i] = temp;
  }
}

void print_array(int arr[]) {
  int i;

  for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int a[] = {1, 2, 3, 4, 5};
  int b[] = {6, 7, 8, 9, 10};

  printf("Before swapping:");
  print_array(a);
  print_array(b);

  swap_arrays(a, b);

  printf("After swapping:");
  print_array(a);
  print_array(b);

  return 0;
}


