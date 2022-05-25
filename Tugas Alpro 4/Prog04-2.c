/*  
    Exercise 5.1 no. E1 (Page 169) "Data Structures and Program Design in C++"
    Sat, 18th September 2021

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

void displayFunc();
unsigned int function(int);
unsigned int inputPosInt();

void titleScreen();
int reset();
void exitScreen();

int main() {
    do {
        titleScreen();
        displayFunc();
    } while(reset());
    exitScreen();

    return 0;
}

void displayFunc() {
    unsigned int n, result;

    printf("Consider the function f(n) defined as follows, where n is a nonnegative integer:\n");
    printf("f(n) = 0\t\tif n = 0;\n");
    printf("f(n) = f(n / 2)\t\tif n is even, n > 0;\n");
    printf("f(n) = 1 + f(n - 1)\tif n is odd, n > 0.\n\n");

    printf("Enter a nonnegative integer: ");
    n = inputPosInt();

    result = function(n);

    printf("\nOutput: f(%d) = %d", n, result);
}

unsigned int function(int n) {
    if(n == 0) return 0;
    else if(n % 2 == 0) return function(n / 2);
    else return 1 + function(n - 1);
}

unsigned int inputPosInt() {
    unsigned int numb;

    while(1) {
        scanf("%d", &numb);

        if(numb >= 0) {
            break;
        } else {
            printf("Input must be a nonnegative integer!\n\n");
            printf("Please re-input: ");
        }
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
    printf("Exercise 5.1 no. E1 (Page 169)\n");
    printf("Data Structures and Program Design in C++\n");
    printf("Kruse, Robert L. and Ryba, Alexander J.\n\n\n");
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
