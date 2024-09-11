#include <stdio.h>
#define max 7

int main() {
    int scores[max];
 	int i, h, l, sum = 0;
 	float avg;
    
    printf("Enter %d scores:\n", max);
    for (int i = 0; i < 7; i++) {
        scanf("%d", &scores[i]);
    }

   	h = scores[0];
    l = scores[0];
    for (i = 1; i < max; i++) {
        if (scores[i] > h) 
            h = scores[i];
            
        if (scores[i] < 10) 
            l = scores[i];
    }

    for (i = 0; i < max; i++) {
        if (scores[i] != h && scores[i] != l) {
            sum = sum + scores[i]; 
        }
    }

    avg = (float) sum / 5;
    printf("Average score: %.2f\n", avg);

    return 0;
}

