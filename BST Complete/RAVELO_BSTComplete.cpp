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
    } else if(value > (*root)->x){
        insert(&(*root)->rightptr, value);
    } else {
        return;
    }
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

int height(TREENODEPTR root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = height(root->leftptr);
        int rightHeight = height(root->rightptr);
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}

int size(TREENODEPTR root) {
    if (root == NULL) {
        return 0;
    } else {
        return size(root->leftptr) + 1 + size(root->rightptr);
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
    int choice, value;

    do {
        printf("\nChoose an operation of your choice.\n");
        printf("1. Insert a node in the binary search tree.\n");
        printf("2. Display nodes in ascending order.\n");
        printf("3. Delete a node from a binary tree.\n");
        printf("4. Find Height of the tree.\n");
        printf("5. Find the size of the tree.\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(&root, value);
                break;
            case 2:
                printf("Ascending (in-order): ");
                displayINORDER(root);
                printf("\n");
                break;
            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 4:
                printf("Height of the binary tree: %d\n", height(root));
                break;
            case 5:
            	printf("Size of the tree: %d\n", size(root));
                break;
            case 6:
			    printf("Exiting...\n");
                break;    
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
