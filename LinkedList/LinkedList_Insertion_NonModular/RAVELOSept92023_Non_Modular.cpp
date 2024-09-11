#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node nd;
nd *head, *newNode, *previous, *current, *temp;

int main() {
    head = NULL;

    int num;
    char choice;

    do {
        printf("Enter a number: ");
        scanf("%d", &num);

        newNode = (nd*)malloc(sizeof(nd));
        newNode->data = num;
        newNode->next = NULL;

        previous = NULL;
        current = head;
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

        printf("Press 1 to enter another number: ");
        scanf(" %c", &choice);
    } while (choice == '1');

    printf("Current List: ");
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    do {
        printf("Insert a number? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y') {
            int insertNum;
            printf("Enter a number to insert: ");
            scanf("%d", &insertNum);

            newNode = (nd*)malloc(sizeof(nd));
            newNode->data = insertNum;
            newNode->next = NULL;

            previous = NULL;
            current = head;
            while (current != NULL && insertNum > current->data) {
                previous = current;
                current = current->next;
            }

            if (previous == NULL) {
                head = newNode;
            } else {
                previous->next = newNode;
            }

            newNode->next = current;

            printf("Current list: ");
            current = head;
            while (current != NULL) {
                printf("%d ", current->data);
                current = current->next;
            }
            printf("\n");
        }
    } while (choice == 'y');
    return 0;
}

