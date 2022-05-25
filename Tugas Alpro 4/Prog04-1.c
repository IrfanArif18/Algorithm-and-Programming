/*  
    C Program to Calculate Factorial and Fibonacci Series of a Given Input
    Wed, 15th September 2021

    Algoritma dan Pemrograman-01
    Group 18:
    Irfan Arif Maulana              (1906379270)
    Raden Wisnu Andhika Pranidhia   (1906354545)

    Teknik Elektro
    Departemen Teknik Elektro Fakultas Teknik
    Universitas Indonesia
    2021
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void factScreen();
unsigned long long int calcFact(int);
void fiboScreen();
void calcFibo(int, int, int);
int inputRange(int, int);

void titleScreen();
int option();
int reset();
void exitScreen();

int main() {
    do {
        titleScreen();
        option() == 1 ? factScreen() : fiboScreen();
    } while(reset());
    exitScreen();
    
    return 0;
}

void factScreen() {
    int numb, i;
    unsigned long long int fact;
    
    system("cls");
    printf("FACTORIAL CALCULATOR\n\n\n");

    printf("Enter a positive integer (max = 20): ");
    numb = inputRange(1, 20);

    fact = calcFact(numb);

    printf("\n%d! = ", numb);
    for(i = numb; i >= 2; i--) {
        printf("%d * ", i);
    }
    printf("1 = %lld", fact);
}

unsigned long long int calcFact(int numb) {
    if(numb == 1) return 1;
    else return numb * calcFact(numb - 1);
}

void fiboScreen() {
    int numb, seed1 = 0, seed2 = 1;

    system("cls");
    printf("FIBONACCI SEQUENCE\n\n\n");

    printf("For number of Fibonacci unit(s),\n");
    printf("Enter a positive integer (max = 47): ");
    numb = inputRange(1, 47); // Input is limited to 47 units of fibonacci sequence because 48 units exceed maximal positive value int can store

    printf("\n%d ", seed1);
    if(numb > 1) printf("%d ", seed2);
    calcFibo(seed1, seed2, numb - 2);
}

void calcFibo(int seed1, int seed2, int numb) {
    int n1 = seed1, n2 = seed2, n3;

    if(numb > 0) {
        n3 = n2 + n1;
        n1 = n2;
        n2 = n3;
        printf("%d ", n3);
        calcFibo(n1, n2, numb - 1);
    }
}

int inputRange(int low, int up) {
    int numb;

    if(low < up) {

        while(1) {
            scanf("%d", &numb);

            if(numb >= low && numb <= up) {
                break;
            } else if(numb < low) {
                printf("Input is not a positive integer!\n\n");
            } else {
                printf("Your input is too large! (max = %d)\n\n", up);
            }

            printf("Please re-input: ");
        }

    } else {
        printf("Invalid argument. Lower bound must be less than upper bound!\n\n");
    }

    return numb;
}

void titleScreen() {
    system("cls");
    printf("Algoritma dan Pemrograman-01\n");
    printf("Group 18:\n");
    printf("Irfan Arif Maulana\t\t(1906379270)\n");
    printf("Raden Wisnu Andhika Pranidhia\t(1906379270)\n\n");
    printf("Teknik Elektro Fakultas Teknik\n");
    printf("Universitas Indonesia 2021\n\n");
    printf("==================================================\n\n");
    printf("C PROGRAM TO CALCULATE FACTORIAL AND FIBONACCI SERIES OF A GIVEN INPUT\n\n\n");
}

int option() {
    int input;
    
    printf("Choose your calculator:");
    printf("\n1. Factorial\n2. Fibonacci Series");
    printf("\n\nInsert your input (number): ");

    while(1) {
        scanf("%d", &input);

        if(input >= 1 && input <= 2) {
            break;
        } else {
            printf("Option %d is not available.\n\nPlease re-input: ", input);
        }
    }

    return input;
}

int reset() {
    char input;

    printf("\n\n\n\nDo you want to reset the program? ");
    printf("(Y/y or N/n): ");

    while(1) {
        scanf(" %c", &input);

        if(input == 'Y' || input == 'y' || input == 'N' || input == 'n') {
            break;
        } else {
            printf("Invalid input.\n\nPlease re-input: ");
        }
    }

    if(input == 'Y' || input == 'y') {
        return 1;
    } else {
        return 0;
    }
}

void exitScreen() {
    system("cls");
    printf("Thank you!\n");
    printf("-Irfan and Andhika");

    printf("\n\n\n\nPress any key to exit program . . . ");
    getch();
}
