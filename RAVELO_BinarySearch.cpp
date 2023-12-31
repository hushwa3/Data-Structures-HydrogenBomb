#include <stdio.h>
#define max 10

int BinarySearch(int find, int A[]);

int main() {
    int A[max] = {1, 3, 5, 7, 11, 13, 19, 23, 29, 31};
    int find, choice, j;

    printf("10 Initialized Integers: ");
    for (int i = 0; i < max; i++) {
        printf("%d ", A[i]);
    }

    do {
        printf("\nInput the Number to Search for: ");
        scanf("%d", &find);
        j = BinarySearch(find, A);
        if (j == -1)
            printf("The digit %d was not found\n", find);
        else
            printf("The digit %d is at index %d\n", find, j);

        printf("Continue? (1 = Yes | 0 = No): ");
        scanf("%d", &choice);
    } while (choice != 0);

    return 0;
}

int BinarySearch(int find, int A[]) {
    int l, r, MidPoint;
    l = 0;
    r = max - 1;

    while (l <= r) {
        MidPoint = (l + r) / 2;
        if (find == A[MidPoint])
            return MidPoint;
        else if (find > A[MidPoint])
            l = MidPoint + 1;
        else
            r = MidPoint - 1;
    }
    return -1;
}
