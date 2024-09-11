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
        else if (choice == 'n') {
            printf("Delete a number? (y/n): ");
            scanf(" %c", &choice);
            
            if (choice == 'n') {
                break; // exit the loop
            }

            if (choice == 'y') {
                int deleteNum;
                printf("Enter a number to delete: ");
                scanf("%d", &deleteNum);

                previous = NULL;
                current = head;

                while (current != NULL && current->data != deleteNum) {
                    previous = current;
                    current = current->next;
                }

                if (current != NULL) {
                    if (previous == NULL) {
                        head = current->next;
                    } else {
                        previous->next = current->next;
                    }

                    free(current);
                    printf("Number %d deleted.\n", deleteNum);
                } else {
                    printf("The number is not in the linked list.\n");
                }

                printf("Current list: ");
                current = head;
                while (current != NULL) {
                    printf("%d ", current->data);
                    current = current->next;
                }
                printf("\n");
            }
        }
    } while (1);

    current = head;
    while (current != NULL) {
        temp = current->next;
        free(current);
        current = temp;
    }
    return 0;
}

