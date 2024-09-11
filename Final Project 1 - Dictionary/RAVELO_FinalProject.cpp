#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char word[256];
    char meaning[256];
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char word[], char meaning[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->word, word);
    strcpy(newNode->meaning, meaning);
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, char word[], char meaning[]) {
    if (root == NULL) {
        return createNode(word, meaning);
    }
    int compare = strcmp(word, root->word);
    if (compare < 0) {
        root->left = insert(root->left, word, meaning);
    } else if (compare > 0) {
        root->right = insert(root->right, word, meaning);
    }
    return root;
}

struct Node* search(struct Node* root, char word[]) {
    if (root == NULL || strcasecmp(root->word, word) == 0) {
    	printf("The Dictionary is Empty\n");
        return root;
    }
    if (strcasecmp(word, root->word) < 0) {
        return search(root->left, word);
    }
    return search(root->right, word);
}

struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* deleteNode(struct Node* root, char word[]) {
    if (root == NULL) {
    	printf("The Dictionary is Empty\n");
        return root;
    }

    int compare = strcasecmp(word, root->word);
    if (compare < 0) {
        root->left = deleteNode(root->left, word);
    } else if (compare > 0) {
        root->right = deleteNode(root->right, word);
    } else {
        // ONE CHILD OR NO CHILD NODE
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // TWO CHILDREN NODE: WILL GET THE INORDER SUCCESSOR
        struct Node* temp = findMin(root->right);

        // COPYING INORDER SUCCESSOR'S CONTENT TO THIS NODE
        strcpy(root->word, temp->word);
        strcpy(root->meaning, temp->meaning);

        // DELETING THE INORDER SUCCESSOR 
        root->right = deleteNode(root->right, temp->word);
    }
    return root;
}

void display(struct Node* root) {
    if (root != NULL) {
        display(root->left);
        printf("Word: %s\n", root->word);
        printf("Meaning: %s\n", root->meaning);
        display(root->right);
    }
}

int main() {
    FILE *fp;
    fp = fopen("data.txt", "a+");
    fprintf(fp, "--------------------\n");

    int choice;
    char word[256], meaning[256];
    struct Node* root = NULL;
    struct Node* result = NULL;

    do {
        printf("\nDictionary: Choose an option\n");
        printf("1. Add a word\n");
        printf("2. Search\n");
        printf("3. Delete a word\n");
        printf("4. Display the library of Words\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fprintf(fp, "Choice of user: %d\n", choice);

        switch (choice) {
            case 1:
                printf("Enter a word to insert: ");
                scanf("%s", word);
                fprintf(fp, "Word: %s\n", word);
                printf("Enter the meaning of the word: ");
                scanf(" %199[^\n]", meaning);
                fprintf(fp, "Meaning: %s\n", meaning);
                root = insert(root, word, meaning);
                break;
            case 2:
                printf("What word do you want to search? ");
                scanf("%s", word);
                fprintf(fp, "Search: %s\n", word);
                result = search(root, word);
                if (result != NULL) {
                    printf("Word: %s\n", result->word);
                    printf("Meaning: %s\n", result->meaning);
                    fprintf(fp, "Word and Meaning: %s %s\n", result->word, result->meaning);
                } else {
                    printf("Word not found.\n");
                }
                break;
            case 3:
                printf("Enter a word to delete: ");
                scanf("%s", word);
                fprintf(fp, "Delete: %s\n", word);
                root = deleteNode(root, word);
                break;
            case 4:
                printf("\nThe Word(s) and Meaning(s)\n");
                display(root);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 5);
    fclose(fp);
    return 0;
}