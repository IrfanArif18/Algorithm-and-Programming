#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int inputLimit();
void outPattern(int);

int main() {
    int n;

    system("cls");
    printf("HackerRank Printing Pattern Using Loops Challenge Program\n\n\n");

    printf("Input number: ");
    n = inputLimit();

    printf("\nOutput:\n");
    outPattern(n);

    printf("\n\n\nPress any key to exit program . . . ");
    getch();

    return 0;
}

int inputLimit() {
    int numb;

    while(1) {
        scanf("%d", &numb);

        if(numb >= 1 && numb <= 1000) {
            break;
        } else {
            printf("Input number n must be in the range of 1 <= n <= 1000!\n\n");
            printf("Please re-input: ");
        }
    }

    return numb;
}

void outPattern(int n) {
    int dist, y, x;

    /* Iteration for Y-axis */
    for(y = n - 1; y >= -1 * (n - 1); y--) {
        /* Iteration for X-axis */
        for(x = -1 * (n - 1); x <= n - 1; x++) {
            // printf("(yx = %d %d)\n", y, x);

            /* Compares the abscissa and ordinate to determine which has the largest absolute value */
            /* Then assigns the largest absolute value to the dist variable */
            if(abs(y) > abs(x)) {
                dist = abs(y);
            } else {
                dist = abs(x);
            }
            
            /* Increments the distance by 1 */
            dist += 1;

            printf("%d ", dist);
        }
        printf("\n");
    }

}
