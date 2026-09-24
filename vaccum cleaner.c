#include <stdio.h>

int main() {
    int A, B;
    char pos;

    printf("Room A (1=DIRTY, 0=CLEAN): ");
    scanf("%d", &A);

    printf("Room B (1=DIRTY, 0=CLEAN): ");
    scanf("%d", &B);

    printf("Vacuum Position (A/B): ");
    scanf(" %c", &pos);

    if (pos == 'A' || pos == 'a') {
        if (A == 1) {
            printf("SUCK A\n");
            A = 0;
        }
        printf("MOVE RIGHT\n");
        if (B == 1) {
            printf("SUCK B\n");
            B = 0;
        }
    } else {
        if (B == 1) {
            printf("SUCK B\n");
            B = 0;
        }
        printf("MOVE LEFT\n");
        if (A == 1) {
            printf("SUCK A\n");
            A = 0;
        }
    }

    printf("\nFinal State:\n");
    printf("A = %s\n", A == 0 ? "CLEAN" : "DIRTY");
    printf("B = %s\n", B == 0 ? "CLEAN" : "DIRTY");

    return 0;
}
