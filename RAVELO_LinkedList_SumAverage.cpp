#include <stdio.h>
#include <stdlib.h>

struct node {
    int x;
    struct node* next;
};
typedef struct node nd;

nd* head, * p;

void sum_and_average(nd* head, int* sum, float* average) {
    *sum = 0;
    int count = 0;
    p = head;

    while (p != NULL) {
        *sum += p->x;
        count++;
        p = p->next;
    }

    if (count > 0) {
        *average = (float)*sum / count;
    } else {
        *average = 0.0;
    }
}

int main() {
    int num, ans;
    int sum = 0;
    float average = 0.0;

    head = NULL; // Initialize head as NULL

    do {
        printf("Enter a number: ");
        scanf("%d", &num);

        if (head == NULL) {
            // If it's the first input, create the head node
            head = (nd*)malloc(sizeof(nd));
            p = head;
        } else {
            p->next = (nd*)malloc(sizeof(nd));
            p = p->next;
        }

        p->x = num;
        p->next = NULL;

        printf("Press 1 to enter another num or any number to quit: ");
        scanf("%d", &ans);

    } while (ans == 1);

    sum_and_average(head, &sum, &average);
    printf("The sum is %d\n", sum);
    printf("The average is %.2f\n", average);

    // Memory is not freed here, which may cause memory leaks.

    return 0;
}

