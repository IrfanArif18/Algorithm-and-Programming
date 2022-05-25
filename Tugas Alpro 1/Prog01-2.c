#include <stdio.h>

int inputRange(int, int);
int convert(int, int);
void printClock(int, int);

int main() {
    int wib, conv, i;

    system("cls");

    printf("Insert hour value (WIB / GMT+7): ");
    wib = inputRange(0, 23);

    printf("\n\n");

    for(i = -8; i <= 8; i++) {
        conv = convert(wib, i);
        printClock(conv, i);
    }

    return 0;
}

int inputRange(int low, int up) {
    int numb;

    if(low < up) {
        while(1) {
            scanf("%d", &numb);

            if(numb >= low && numb <= up) {
                break;
            } else {
                printf("Input must be between %d - %d!\n\n", low, up);
                printf("Please re-input: ");
            }
        }

    } else {
        printf("Invalid argument. Lower bound must be less than upper bound!\n\n");
    }

    return numb;
}

int convert(int wib, int i) {
    int conv;

    conv = wib - 7 + i;

    if(conv < 0) {
        conv = 24 + conv;
    }

    return conv;
}

void printClock(int conv, int i) {
    if(i < 0) {
        printf("GMT%d: %d\n", i, conv);
    } else if(i > 0) {
        printf("GMT+%d: %d\n", i, conv);
    } else {
        printf("GMT: %d\n", conv);
    }
}

