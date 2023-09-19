#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node nd;
nd *head = NULL;

void insertion(int num) {
    nd *newNode = (nd*)malloc(sizeof(nd));
    newNode->data = num;
    newNode->next = NULL;

    nd *previous = NULL;
    nd *current = head;
   while (current != NULL && num > current->data) {
     previous = current;
     current = current->next;
  }

   if (previous == NULL) {
     head = newNode;
   } else {
    previous->next = newNode;
   }

   newNode->next = current;
}

void print() {
    nd *current = head;
     while (current != NULL) {
     printf("%d ", current->data);
    current = current->next;
   }
  printf("\n");
}

int main() {
    int num;
    char choice;

  do {
    printf("Enter a number: ");
    scanf("%d", &num);

    insertion(num);

    printf("Press 1 to enter another number: ");
    scanf(" %c", &choice);
  } while (choice == '1');

  print();

  do {
    printf("Insert a number? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y') {
      int insertNum;
      printf("Enter a number to insert: ");
      scanf("%d", &insertNum);

      insertion(insertNum);

      print();
    }
  } while (choice == 'y');

  return 0;
}

