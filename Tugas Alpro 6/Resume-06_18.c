/*  
    Exercise 6 - Sorting
    Mon, 10th October 2021

    Algoritma dan Pemrograman-01
    Group 18:
    Irfan Arif Maulana              (1906379270)
    Raden Wisnu Andhika Pranidhia   (1906354545)

    Teknik Elektro
    Departemen Teknik Elektro Fakultas Teknik
    Universitas Indonesia
    2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define QTTY 5 // Number of students
#define SIZE 100

void inputData(char[][SIZE], float[], float[], float[], float[], int[]);
float calcScore(float, float, float, int*);

void bubbleSort(int, char[][SIZE], float[], float[], float[], float[], int[]);
void swapStr(char[], char[]);
void swapFloat(float*, float*);
void swapInt(int*, int*);

void dispScreen(char[][SIZE], float[], float[], float[], float[], int[]);
void dispData(char[][SIZE], float[], float[], float[], float[], int[]);

float inputRange(float, float);
void titleScreen();
void holdScreen();
int option(int);
void exitScreen();

int main() {
    char name[QTTY][SIZE];
    float hw[QTTY], mid[QTTY], final[QTTY], score[QTTY];
    int pass[QTTY];
    int reset = 1;

    titleScreen();
    inputData(name, hw, mid, final, score, pass);

    do {
        switch(option(0)) {
            case 1: inputData(name, hw, mid, final, score, pass);
                    break;
            case 2: dispScreen(name, hw, mid, final, score, pass);
                    break;
            default:  reset = 0;
                      break;
        }
    } while(reset);

    exitScreen();

    return 0;
}

void inputData(char name[][SIZE], float hw[], float mid[], float final[], float score[], int pass[]) {
	int i;

	system("cls");

	for(i = 0; i < QTTY; i++) {
		printf("For student number #%d,\n", i + 1);

		printf("Student's name\t: ");
        scanf("\n%[^\n]s", &name[i]);

		printf("Homework score\t: ");
		hw[i] = inputRange(0, 100);

		printf("Midterm score\t: ");
		mid[i] = inputRange(0, 100);

		printf("Final score\t: ");
		final[i] = inputRange(0, 100);

		printf("\n");
	}
	
	for(i = 0; i < QTTY; i++) score[i] = calcScore(hw[i], mid[i], final[i], &pass[i]);
	
	holdScreen();
}

float calcScore(float hw, float mid, float final, int* pass) {
    float score;

    score = (0.2 * hw) + (0.35 * mid) + (0.45 * final);
    if(score >= 60) *pass = 1;
    else *pass = 0;

    return score;
}

void dispScreen(char name[][SIZE], float hw[], float mid[], float final[], float score[], int pass[]) {
	int select;

    system("cls");
    dispData(name, hw, mid, final, score, pass);

    while(1) {
        select = option(1);
        bubbleSort(select, name, hw, mid, final, score, pass);
        dispData(name, hw, mid, final, score, pass);
        if(select == 5) break;
    }
}

void dispData(char name[][SIZE], float hw[], float mid[], float final[], float score[], int pass[]) {
    int i;

    system("cls");
    printf("%20s", "Name");
    printf("%20s", "Homework");
    printf("%20s", "Mid Exam");
    printf("%20s", "Final Exam");
    printf("%20s", "Final Score");
    printf("%20s\n", "Status");

    for(i = 0; i < QTTY; i++) {
        printf("%20s", name[i]);
        printf("%20.2f", hw[i]);
        printf("%20.2f", mid[i]);
        printf("%20.2f", final[i]);
        printf("%20.2f", score[i]);
        pass[i] == 1 ? printf("%20s\n", "Passed") : printf("%20s\n", "Failed");
    }
}

void bubbleSort(int flag, char name[][SIZE], float hw[], float mid[], float final[], float score[], int pass[]) {
    int i, j;
    char upcase[QTTY][SIZE];

    for(i = 0; i < QTTY; i++) {
        strcpy(upcase[i], name[i]);
        strupr(upcase[i]);
    }

    switch(flag) {
        case 1:
            for(i = 0; i < QTTY - 1; i++) {
                for(j = 0; j < QTTY - i - 1; j++) {
                    if(score[j] > score[j + 1]) {
                        swapStr(upcase[j], upcase[j + 1]);
                        swapStr(name[j], name[j + 1]);
                        swapFloat(&hw[j], &hw[j + 1]);
                        swapFloat(&mid[j], &mid[j + 1]);
                        swapFloat(&final[j], &final[j + 1]);
                        swapFloat(&score[j], &score[j + 1]);
                        swapInt(&pass[j], &pass[j + 1]);
                    }
                }
            }
            break;
        case 2:
            for(i = 0; i < QTTY - 1; i++) {
                for(j = 0; j < QTTY - i - 1; j++) {
                    if(score[j] < score[j + 1]) {
                        swapStr(upcase[j], upcase[j + 1]);
                        swapStr(name[j], name[j + 1]);
                        swapFloat(&hw[j], &hw[j + 1]);
                        swapFloat(&mid[j], &mid[j + 1]);
                        swapFloat(&final[j], &final[j + 1]);
                        swapFloat(&score[j], &score[j + 1]);
                        swapInt(&pass[j], &pass[j + 1]);
                    }
                }
            }
            break;
        case 3:
            for(i = 0; i < QTTY - 1; i++) {
                for(j = 0; j < QTTY - i - 1; j++) {
                    if(strcmp(upcase[j], upcase[j + 1]) > 0) {
                        swapStr(upcase[j], upcase[j + 1]);
                        swapStr(name[j], name[j + 1]);
                        swapFloat(&hw[j], &hw[j + 1]);
                        swapFloat(&mid[j], &mid[j + 1]);
                        swapFloat(&final[j], &final[j + 1]);
                        swapFloat(&score[j], &score[j + 1]);
                        swapInt(&pass[j], &pass[j + 1]);
                    }
                }
            }
            break;
        case 4:
            for(i = 0; i < QTTY - 1; i++) {
                for(j = 0; j < QTTY - i - 1; j++) {
                    if(strcmp(upcase[j + 1], upcase[j]) > 0) {
                        swapStr(upcase[j], upcase[j + 1]);
                        swapStr(name[j], name[j + 1]);
                        swapFloat(&hw[j], &hw[j + 1]);
                        swapFloat(&mid[j], &mid[j + 1]);
                        swapFloat(&final[j], &final[j + 1]);
                        swapFloat(&score[j], &score[j + 1]);
                        swapInt(&pass[j], &pass[j + 1]);
                    }
                }
            }
            break;
    }
}

void swapStr(char current[], char next[]) {
    char temp[SIZE];

    strcpy(temp, current);
    strcpy(current, next);
    strcpy(next, temp);
}

void swapFloat(float* current, float* next) {
    float temp = *current;

    *current = *next;
    *next = temp;
}

void swapInt(int* current, int* next) {
    int temp = *current;

    *current = *next;
    *next = temp;
}

float inputRange(float low, float up) {
    float numb;

    if(low < up) {

        while(1) {
            scanf("%f", &numb);
            if(numb >= low && numb <= up) break;
            else printf("Input must be in between %.2f - %.2f!\n\n", low, up);
            printf("Please re-input: ");
        }

    } else {
        printf("Invalid argument (%.2f < %.2f). Lower bound must be less than upper bound!\n\n", low, up);
        return -1;
    }

    return numb;
}

void titleScreen() {
    system("cls");
    printf("\"Exercise 6 - Sorting\"\n\n");
    printf("Algoritma dan Pemrograman-01\n");
    printf("Group 18:\n");
    printf("Irfan Arif Maulana\t\t(1906379270)\n");
    printf("Raden Wisnu Andhika Pranidhia\t(1906379270)\n\n");
    printf("Teknik Elektro Fakultas Teknik\n");
    printf("Universitas Indonesia 2021");
    
    holdScreen();
}

void holdScreen() {
    printf("\n\n\n\nPress any key to continue . . . ");
    getch();
}

int option(int flag) {
    int input;
    
    if(flag == 0) {

        system("cls");
        printf("Menu:");
        printf("\n1. Input student data\n2. Display student data\n3. Exit program");
        printf("\n\nInput your selection (number): ");

        while(1) {
            scanf("%d", &input);
            if(input >= 1 && input <= 3) break;
            else printf("Option %d is not available.\n\nPlease re-input: ", input);
        }

    } else {

        printf("\n\nMenu: ");
        printf("\n1. Sort based on ascending score\n2. Sort based on descending score");
        printf("\n3. Sort based on ascending name\n4. Sort based on descending name");
        printf("\n5. Back to main menu");
        printf("\n\nInput your selection (number): ");

        while(1) {
            scanf("%d", &input);
            if(input >= 1 && input <= 5) break;
            else printf("Option %d is not available.\n\nPlease re-input: ", input);
        }
    }

    return input;
}

void exitScreen() {
    system("cls");
    printf("Thank you!\n");
    printf("-Irfan and Andhika");

    printf("\n\n\n\nPress any key to exit program . . . ");
    getch();
}
