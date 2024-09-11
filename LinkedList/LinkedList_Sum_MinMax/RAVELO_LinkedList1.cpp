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

void getMinMax(nd* head, int* min, int* max){
    p = head;
    
    while(p != NULL){
        if(*min > p->x){
            *min = p->x;
        }
        if(*max < p->x){
            *max = p->x;
        }
        p = p ->next;
    }
    
}

int main() {
    int num, ans, sum = 0, min, max;
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
    
    getMinMax(head, &min, &max);
    printf("The Minimum number is %d", min);
    printf("\nThe Maximum number is %d", max);

    return 0;
}
