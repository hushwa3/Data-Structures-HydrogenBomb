#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node nd;
nd *head, *newNode, *previous, *current, *temp;

void insert(nd** head, int data) {
    // Allocate memory for a new node
   	newNode = (nd*)malloc(sizeof(nd));
    newNode->data = data;
    newNode->next = NULL;

    // Insert the new node in the appropriate position
    previous = NULL;
    current = *head;
    while (current != NULL && data > current->data) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        *head = newNode;
    } else {
        previous->next = newNode;
    }

    newNode->next = current;
}

void printList(nd* head) {
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    head = NULL;

    int num;
    char choice;

    do {
        printf("Enter a number: ");
        scanf("%d", &num);
        insert(&head, num);

        printf("Press 1 to enter another number: ");
        scanf(" %c", &choice);
    } while (choice == '1');

    printf("List: ");
    printList(head);

    do {
        printf("Do you want to insert a number? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y') {
            int insertNum;
            printf("Enter a number to insert: ");
            scanf("%d", &insertNum);

            insert(&head, insertNum);

            printf("Current list: ");
            printList(head);
        }
    } while (choice == 'y');

    // Free allocated memory
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

