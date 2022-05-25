#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int inputLimit();
int inputValid(int);
void outputTxt(int);

int main() {
    int a, b, i;

    system("cls");
    printf("HackerRank For Loop in C Challenge Program\n\n\n");

    printf("Input first number: ");
    a = inputLimit();
    printf("Input second number: ");
    b = inputValid(a);

    printf("\nOutput:\n");
    
    for(i = a; i <= b; i++) {
        outputTxt(i);
    }

    printf("\n\n\nPress any key to exit program . . . ");
    getch();

    return 0;
}

int inputLimit() {
    int numb;

    while(1) {
        scanf("%d", &numb);

        if(numb >= 1 && numb <= 1e6) {
            break;
        } else {
            printf("Input number n must be in the range of 1 <= n <= 10^6!\n\n");
            printf("Please re-input: ");
        }
    }

    return numb;
}

int inputValid(int a) {
    int numb;

    while(1) {
        numb = inputLimit();

        if(numb >= a) {
            break;
        } else {
            printf("Input number n must be n >= %d!\n\n", a);
            printf("Please re-input: ");
        }
    }

    return numb;
}

void outputTxt(int i) {
    switch(i) {
        case 1: printf("one\n");
                break;
        case 2: printf("two\n");
                break;
        case 3: printf("three\n");
                break;
        case 4: printf("four\n");
                break;
        case 5: printf("five\n");
                break;
        case 6: printf("six\n");
                break;
        case 7: printf("seven\n");
                break;
        case 8: printf("eight\n");
                break;
        case 9: printf("nine\n");
                break;
        default:
            
            if(i % 2 == 0) {
                printf("even\n");
            } else {
                printf("odd\n");
            }

            break;
    }

}
