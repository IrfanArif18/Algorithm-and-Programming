/*  
    Exercise 7 - Searching
    Sat, 9th October 2021

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

#define QTTY 3 // Number of students
#define SIZE 100

void inputData();
float calcScore(float, float, float, int*);

int linearSearch(int);

void bubbleSort(int);
void swapStr(char[], char[]);
void swapFloat(float*, float*);
void swapInt(int*, int*);

void dispScreen();
void dispData(int, int);

float inputRange(float, float);
void titleScreen();
void helpScreen();
void holdScreen();
int option(int);
void exitScreen();

char name[QTTY][SIZE];
float hw[QTTY], mid[QTTY], final[QTTY], score[QTTY];
int pass[QTTY];

char tempName[QTTY][SIZE];
float tempHw[QTTY], tempMid[QTTY], tempFinal[QTTY], tempScore[QTTY];
int tempPass[QTTY];

int main() {
    int reset = 1;

    titleScreen();
    inputData();

    do {
        switch(option(0)) {
            case 1: inputData();
                    break;
            case 2: dispScreen();
                    break;
            case 3: helpScreen();
                    break;
            default:  reset = 0;
                      break;
        }
    } while(reset);

    exitScreen();

    return 0;
}

void inputData() {
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

void dispScreen() {
	int menu, select, input;
    int searchIndex;

    system("cls");
    menu = option(1);

    if(menu == 1) {
        while(1) {
            select = option(2);
            bubbleSort(1);
            searchIndex = linearSearch(select);
            if(searchIndex == -1) {
            	printf("Not Available");
			}
            if(select == 4) break;
        }
    } else {
        dispData(menu, 0);
        while(1) {
            select = option(3);
            bubbleSort(select);
            dispData(menu, 0);
            if(select == 5) break;
        }
    }
}

void dispData(int menu, int searchIndex) {
    int i, input;

    system("cls");
    printf("%20s", "Name");
    printf("%15s", "Homework");
    printf("%15s", "Mid Exam");
    printf("%15s", "Final Exam");
    printf("%15s", "Final Score");
    printf("%15s", "Status");
    printf("\n--------------------------------------------------");
    printf("---------------------------------------------\n");

    if(menu == 1) {
        for(i = 0; i <= QTTY - searchIndex ; i++) {
            printf("%20s", tempName[i]);
            printf("%15.2f", tempHw[i]);
            printf("%15.2f", tempMid[i]);
            printf("%15.2f", tempFinal[i]); 
            printf("%15.2f", tempScore[i]);
            tempPass[i] == 1 ? printf("%15s\n", "Passed") : printf("%15s\n", "Failed");
        }
    } else {
        for(i = 0; i < QTTY; i++) {
            printf("%20s", name[i]);
            printf("%15.2f", hw[i]);
            printf("%15.2f", mid[i]);
            printf("%15.2f", final[i]);
            printf("%15.2f", score[i]);
            pass[i] == 1 ? printf("%15s\n", "Passed") : printf("%15s\n", "Failed");
        }
    }
}

int linearSearch(int select) {
	int input, i, searchScore;
    switch(select) {
        case 1:
        	
            break;
        case 2:
        	printf("Menu:");
        	printf("\n1. Greater than\n2. less than");
        	printf("\n\nInput your selection (number): ");
        	
       		while(1) {
            	scanf("%d", &input);
            	if(input >= 1 && input <= 2) break;
            	else printf("Option %d is not available.\n\nPlease re-input: ", input);
        	}
        	
        	printf("Input the score: ");
        	while(1) {
                scanf("%d", &searchScore);
                if(searchScore >= 0 && searchScore <= 100) break;
                else printf("Option %d is not available.\n\nPlease re-input: ", input);
            }
        	system("cls");
    		printf("%20s", "Name");
    		printf("%15s", "Homework");
    		printf("%15s", "Mid Exam");
    		printf("%15s", "Final Exam");
    		printf("%15s", "Final Score");
    		printf("%15s", "Status");
    		printf("\n--------------------------------------------------");
    		printf("---------------------------------------------\n");

            if(input == 1) {
            	for(i = 0; i < QTTY ; i++) {
            		if(score[i] >= searchScore) {
            			printf("%20s", name[i]);
            			printf("%15.2f", hw[i]);
            			printf("%15.2f", mid[i]);
            			printf("%15.2f", final[i]);
            			printf("%15.2f", score[i]);
            			pass[i] == 1 ? printf("%15s\n", "Passed") : printf("%15s\n", "Failed");
					}
        		}
        		holdScreen();
        		system("cls");
				return 1;
			} else if(input == 2) {
				for(i = 0; i < QTTY ; i++) {
            		if(score[i] <= searchScore) {
            			printf("%20s", name[i]);
            			printf("%15.2f", hw[i]);
            			printf("%15.2f", mid[i]);
            			printf("%15.2f", final[i]);
            			printf("%15.2f", score[i]);
            			pass[i] == 1 ? printf("%15s\n", "Passed") : printf("%15s\n", "Failed");
					}
        		}
        		holdScreen();
        		system("cls");
				return 1;
			}
            break;
        case 3:
        	system("cls");
        	printf("Menu:");
        	printf("\n1. Success\n2. Failed");
        	printf("\n\nInput your selection (number): ");

       		while(1) {
            	scanf("%d", &input);
            	if(input >= 1 && input <= 2) break;
            	else printf("Option %d is not available.\n\nPlease re-input: ", input);
        	}
        	system("cls");
    		printf("%20s", "Name");
    		printf("%15s", "Homework");
    		printf("%15s", "Mid Exam");
    		printf("%15s", "Final Exam");
    		printf("%15s", "Final Score");
    		printf("%15s", "Status");
    		printf("\n--------------------------------------------------");
    		printf("---------------------------------------------\n");
            if(input == 1) {
            	for(i = 0; i < QTTY ; i++) {
            		if(pass[i] == 1) {
            			printf("%20s", name[i]);
            			printf("%15.2f", hw[i]);
            			printf("%15.2f", mid[i]);
            			printf("%15.2f", final[i]);
            			printf("%15.2f", score[i]);
            			pass[i] == 1 ? printf("%15s\n", "Passed") : printf("%15s\n", "Failed");
					}
        		}
        		holdScreen();
        		system("cls");
				return 1;
			} else if(input == 2) {
				for(i = 0; i < QTTY ; i++) {
            		if(pass[i] == 0) {
            			printf("%20s", name[i]);
            			printf("%15.2f", hw[i]);
            			printf("%15.2f", mid[i]);
            			printf("%15.2f", final[i]);
            			printf("%15.2f", score[i]);
            			pass[i] == 1 ? printf("%15s\n", "Passed") : printf("%15s\n", "Failed");
					}
        		}
        		holdScreen();
        		system("cls");
				return 1;
			}
        	break;
        default: return;
    }
}

void bubbleSort(int type) {
    int i, j;

    switch(type) {
        case 1:
            for(i = 0; i < QTTY - 1; i++) {
                for(j = 0; j < QTTY - i - 1; j++) {
                    if(score[j] > score[j + 1]) {
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
                    if(strcmpi(name[j], name[j + 1]) > 0) {
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
                    if(strcmpi(name[j + 1], name[j]) > 0) {
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

void helpScreen() {
    system("cls");

    printf("Press 1 if you want to re-input data. \nPress 2 if you want to display data.\nPress 4 if you want to exit the program.");


    printf("\n\n\n\nPress any key to go back . . . ");
    getch();
}

void titleScreen() {
    system("cls");
    printf("\"Exercise 7 - Searching\"\n\n");
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
    
    switch(flag) {
        case 0:
            system("cls");
            printf("Menu:");
            printf("\n1. Input student data\n2. Display student data\n3. Help\n4. Exit program");
            printf("\n\nInput your selection (number): ");

            while(1) {
                scanf("%d", &input);
                if(input >= 1 && input <= 4) break;
                else printf("Option %d is not available.\n\nPlease re-input: ", input);
            }
            break;
        case 1:
            printf("Menu:");
            printf("\n1. Search data\n2. Sort data");
            printf("\n\nInput your selection (number): ");

            while(1) {
                scanf("%d", &input);
                if(input >= 1 && input <= 2) break;
                else printf("Option %d is not available.\n\nPlease re-input: ", input);
            }
            break;
        case 2:
            printf("\n\nSearch: ");
            printf("\n1. Student's name\n2. Final score");
            printf("\n3. Status");
            printf("\n4. Back to main menu");
            printf("\n\nInput your selection (number): ");
            
            while(1) {
                scanf("%d", &input);
                if(input >= 1 && input <= 4) break;
                else printf("Option %d is not available.\n\nPlease re-input: ", input);
            }
            break;
        case 3:
            printf("\n\nSort: ");
            printf("\n1. Ascending score\n2. Descending score");
            printf("\n3. Ascending name\n4. Descending name");
            printf("\n5. Back to main menu");
            printf("\n\nInput your selection (number): ");

            while(1) {
                scanf("%d", &input);
                if(input >= 1 && input <= 5) break;
                else printf("Option %d is not available.\n\nPlease re-input: ", input);
            }
            break;          
        default: break;
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
