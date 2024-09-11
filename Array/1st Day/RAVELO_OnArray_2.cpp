#include <stdio.h>

int main() {
  int list[10], number, position, i;

  // Create a list of numbers.
  for (i = 0; i < 10; i++) {
    list[i] = i + 1;
  }

  // Get the number to be inserted.
  printf("Enter the number to be inserted: ");
  scanf("%d", &number);

  // Get the position where the number should be inserted.
  printf("Enter the position where the number should be inserted: ");
  scanf("%d", &position);

  // Create a copy of the list.
  int new_list[10];
  for (i = 0; i < 10; i++) {
    new_list[i] = list[i];
  }

  // Insert the number at the specified position.
  for (i = 9; i >= position; i--) {
    new_list[i + 1] = new_list[i];
  }
  new_list[position] = number;

  // Print the new list.
  printf("The new list is: ");
  for (i = 0; i < 10; i++) {
    printf("%d ", new_list[i]);
  }
  printf("\n");

  return 0;
}

