#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
    int x;
    struct treenode* leftptr;
    struct treenode* rightptr;
} tree;

typedef tree* TREENODEPTR;

void insert(TREENODEPTR* root, int value) {
    if (*root == NULL) {
        *root = (TREENODEPTR)malloc(sizeof(tree));
        (*root)->x = value;
        (*root)->leftptr = NULL;
        (*root)->rightptr = NULL;
    } else if (value < (*root)->x) {
        insert(&(*root)->leftptr, value);
    } else {
        insert(&(*root)->rightptr, value);
    }
}

void displayINORDER(TREENODEPTR root) {
    if (root == NULL) {
        return;
    }

    displayINORDER(root->leftptr);
    printf("%d ", root->x);
    displayINORDER(root->rightptr);
}

int main() {
    TREENODEPTR root = NULL;

    int choice;
    int value;

    do {
        printf("\n1. Insert a value\n");
        printf("2. Display list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(&root, value);
                break;
            case 2:
                printf("Inorder: ");
                displayINORDER(root);
                printf("\n");
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 3);

    return 0;
}

