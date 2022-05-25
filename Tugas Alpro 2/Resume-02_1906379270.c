#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define INIT 3000   // Initial fee
#define ACCU 1000   // Hourly accumulative value
#define DISC 10000  // Discount value

void inputScreen(int entry[], int exit[]);
float calcFee(int entry[], int exit[], int diff[]);
void outputScreen(int entry[], int exit[], int diff[], float);

int inputRange(int, int);
int inputWholeNumb();

int main() {
    float fee;
    int entry[3], exit[3], diff[3];

    inputScreen(entry, exit);
    fee = calcFee(entry, exit, diff);
    outputScreen(entry, exit, diff, fee);

    return 0;
}

void inputScreen(int entry[], int exit[]) {
    system("cls");
    printf("PARKING FEE CALCULATION PROGRAM\n\n\n");

    printf("For parking entry,\n");
    printf("Input hour\t: ");
    entry[0] = inputRange(0, 23);
    printf("Input minute\t: ");
    entry[1] = inputRange(0, 59);
    entry[2] = 0;

    printf("\nFor parking exit,\n");
    printf("Input hour\t: ");
    exit[0] = inputRange(0, 23);
    printf("Input minute\t: ");
    exit[1] = inputRange(0, 59);
    printf("Input number of day(s) spent parking: ");
    exit[2] = inputWholeNumb();

    printf("\n\n\nPress any key to continue . . . ");
    getch();

}

float calcFee(int entry[], int exit[], int diff[]) {
    float fee = 0;
    int i;

    /* Calculates the parking duration through entry - exit time difference */
    for(i = 0; i <= 2; i++) {
        diff[i] = exit[i] - entry[i];
    }
    
    /* For when the minute difference is negative */
    if(diff[1] < 0) {
        diff[1] += 60;
        diff[0]--;
    }
    
    /* For when the hour difference is negative */
    if(diff[0] < 0) {
        diff[0] += 24;
    }
    
    /* Sets initial fee then adds hourly increment */
    if(diff[0] > 0 || diff[1] > 0 || diff[2] > 0) {
        fee = INIT;
        fee += ACCU * (diff[0] - 1);
    }

    /* Adds extra fee from extra minutes */
    if(diff[1] > 0) {
        fee += ACCU;
    }

    /* Calculates daily fee and its discount */
    if(diff[2] > 0) {
        fee += ACCU * 24 * diff[2];
        fee -= DISC * diff[2];
    }

    return fee;
}

void outputScreen(int entry[], int exit[], int diff[], float fee) {
    system("cls");
    printf("PARKING FEE CALCULATION PROGRAM\n\n\n");

    printf("Entry time\t: %02d:%02d\n", entry[0], entry[1]);
    printf("Exit time\t: %02d:%02d\n", exit[0], exit[1]);
    
    printf("Duration\t: ");

    if(exit[2] > 1) {
        printf("%d days ", exit[2]);
    } else {
        printf("%d day ", exit[2]);
    }

    if(diff[0] > 1) {
        printf("%d hours ", diff[0]);
    } else {
        printf("%d hour ", diff[0]);
    }

    if(diff[1] > 1) {
        printf("%d minutes\n\n", diff[1]);
    } else {
        printf("%d minute\n\n", diff[1]);
    }

    printf("Parking fee\t: Rp%.2f", fee);

    printf("\n\n\nPress any key to exit program . . . ");
    getch();

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

int inputWholeNumb() {
    int numb;

    while(1) {
        scanf("%d", &numb);

        if(numb >= 0) {
            break;
        } else {
            printf("Input must be a whole number!\n\n");
            printf("Please re-input: ");
        }
    }

    return numb;
}

