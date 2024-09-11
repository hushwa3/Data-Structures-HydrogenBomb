#include <stdio.h>
#include <stdlib.h>

struct node {
    int x;
    struct node* next;
};
typedef struct node nd;

void add_element(nd** head, int num) {
    nd* newNode = (nd*)malloc(sizeof(nd));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->x = num;
    newNode->next = NULL;

    if (*head == NULL || num < (*head)->x) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    nd* current = *head;
    while (current->next != NULL && current->next->x < num) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void delete_element(nd** head, int num) {
    nd* current = *head;
    nd* prev = NULL;

    while (current != NULL) {
        if (current->x == num) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Element %d deleted from the list\n", num);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Element %d not found in the list\n", num);
}

void display_list(nd* head) {
	 printf("List elements: ");
    nd* current = head;
    while (current != NULL) {
        printf("%d ", current->x);
        current = current->next;
    }
    printf("\n");
}


int main(){
	int choice, num;
	nd *list = NULL;
	
	do
	{
	printf("\nChoose an operation:\n");
	printf("1 - Add an element \n");
	printf("2 - Delete an element \n");
	printf("3 - Display an element \n");
	printf("4 - Exit\n");
	printf("Enter your choice(1-4): ");
	scanf("%i", &choice);
	if (choice == 1){
		printf("Enter item to be inserted: ");
		scanf("%d", &num);
		add_element(&list, num);
	} 
	else if (choice == 2){
		printf("Enter item to be deleted: ");
		scanf("%d", &num);
		delete_element(&list, num);
	}
	else if (choice == 3)
		display_list(list);
	} while (choice != 4); printf("Exiting the program...\n");
	
	while (list != NULL) {
        nd* temp = list;
        list = list->next;
        free(temp);
    }
    return 0;
}
