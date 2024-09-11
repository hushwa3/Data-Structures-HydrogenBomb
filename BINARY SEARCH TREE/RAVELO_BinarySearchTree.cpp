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

void displayPREORDER(TREENODEPTR root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->x);
    displayPREORDER(root->leftptr);
    displayPREORDER(root->rightptr);
}

void displayPOSTORDER(TREENODEPTR root) {
    if (root == NULL) {
        return;
    }

    displayPOSTORDER(root->leftptr);
    displayPOSTORDER(root->rightptr);
    printf("%d ", root->x);
}

TREENODEPTR findMin(TREENODEPTR node) {
    while (node->leftptr != NULL) {
        node = node->leftptr;
    }
    return node;
}

TREENODEPTR deleteNode(TREENODEPTR root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->x) {
        root->leftptr = deleteNode(root->leftptr, key);
    } else if (key > root->x) {
        root->rightptr = deleteNode(root->rightptr, key);
    } else {
        if (root->leftptr == NULL) {
            TREENODEPTR temp = root->rightptr;
            free(root);
            return temp;
        } else if (root->rightptr == NULL) {
            TREENODEPTR temp = root->leftptr;
            free(root);
            return temp;
        }

        TREENODEPTR temp = findMin(root->rightptr);
        root->x = temp->x;
        root->rightptr = deleteNode(root->rightptr, temp->x);
    }

    return root;
}

int main() {
    TREENODEPTR root = NULL;

    int choice;
    int value;

    do {
        printf("\n1. Insert a value\n");
        printf("2. Display list\n");
        printf("3. Delete a value\n");
        printf("4. Exit\n");
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

                printf("Preorder: ");
                displayPREORDER(root);
                printf("\n");

                printf("Postorder: ");
                displayPOSTORDER(root);
                printf("\n");
                break;
            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

