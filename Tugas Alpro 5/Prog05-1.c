/*  
    Exercise 5 - Array 1D and 2D
    Mon, 27th September 2021

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

#define SIZE 100
#define QTTY 6

typedef struct employee {
    char name[SIZE];
    int no;
    int rank;
    int marital;
    int child;
    int salary;
    int gross_salary;
    int net_salary;
} em;

void rankCriteria();
int inputScreen(em[]);
em inputEmployee(int);
void calcSalary(em[]);
int printEmployee(em[], int);

int inputRange(int, int);
void titleScreen();
void holdScreen();
int option();
void exitScreen();

int main() {
    em person[QTTY];
    int reset = 1;
    int flag = 0;
    titleScreen();

    do {
        switch(option()) {
            case 1: flag = inputScreen(person);
                    break;
            case 2: printEmployee(person, flag);
                    break;
            case 3: rankCriteria();
            		break;
            default:  reset = 0;
                      break;
        }
    } while(reset);

    exitScreen();

    return 0;
}

em inputEmployee(int i) {
    em input;
    
    if(i == 0) printf("Input all employees data\n\n");

    printf("For employee #%d,\n", i + 1);
    printf("Input employee's name\t\t: ");
    getchar();
    gets(input.name);
    printf("Input employee's ID\t\t: ");
    input.no = inputRange(0, 1e11);
    printf("Input employee's rank (1 - 6)\t: ");
    input.rank = inputRange(1, 6);
    printf("Input employee's marital status (0: no, 1: yes)\t: ");
    input.marital = inputRange(0, 1);
    printf("Input employee's number of children\t\t: ");
    input.child = inputRange(0, 100);

    printf("\n\n");

    return input;
}

int inputRange(int low, int up) {
    int numb;

    if(low < up) {

        while(1) {
            scanf("%d", &numb);
            if(numb >= low && numb <= up) break;
            else printf("Input must be in between %d - %d!\n\n", low, up);
            printf("Please re-input: ");
        }

    } else {
        printf("Invalid argument. Lower bound must be less than upper bound!\n\n");
    }

    return numb;
}

int printEmployee(em person[], int flag) {
	int i;
	
	system("cls");
	if(flag == 0) {
		printf("Maaf, Data Employee belum terdaftar");
		holdScreen();
		return 0;
	}
	
	for (i = 0; i < QTTY; i++){
		printf("Nama\t: %s\n", person[i].name);
		printf("No. Pegawai\t: %d\n", person[i].no);
		printf("Golongan\t: %d\n", person[i].rank);
		if(person[i].marital == 1) printf("Status Marital\t: Menikah\n");
		else printf("Status Marital\t: Single\n");
		printf("Gaji Pokok\t: Rp.%d,00,-\n", person[i].salary);
		printf("Gaji Kotor\t: Rp.%d,00,-\n", person[i].gross_salary);
		printf("Gaji Bersih\t: Rp.%d,00,-\n\n", person[i].net_salary);
	}
	holdScreen();
	system("cls");
}

int inputScreen(em person[]) {
	int i;
	system("cls");
	for(i = 0; i < QTTY; i++){
		person[i] = inputEmployee(i);
	}
	calcSalary(person);
	system("cls");
	
	return 1;
}

void rankCriteria() {
	int i;
	int tableRef[6][4] = {
		{10000000, 20, 15, 10},
		{9000000, 18, 14, 9},
		{8000000, 16, 13, 8},
		{7000000, 14, 12, 7},
		{6000000, 12, 11, 6},
		{5000000, 10, 10, 5},
	};
	system("cls");
	printf("\t\tGaji Pokok\t\tT. Pasang\tT. Anak\t\tPajak\n");
	for (i = 0; i < 6; i++) {
		printf("Golongan -%d : Rp.%d,00,-\t\t%d%%\t\t%d%%\t\t%d%%\n", i+1, tableRef[i][0], tableRef[i][1], tableRef[i][2], tableRef[i][3]);
	}
	holdScreen();
	system("cls");
}

void calcSalary(em person[]){
	int i, gross_salary, net_salary;
	int tableRef[6][4] = {
		{10000000, 20, 15, 10},
		{9000000, 18, 14, 9},
		{8000000, 16, 13, 8},
		{7000000, 14, 12, 7},
		{6000000, 12, 11, 6},
		{5000000, 10, 10, 5},
	};
	for(i = 0; i < QTTY; i++) {
		gross_salary = tableRef[person[i].rank-1][0];
		if (person[i].marital == 1) gross_salary += (tableRef[person[i].rank-1][1]/100) * tableRef[person[i].rank-1][0];
		if (person[i].child < 0 && person[i].child <= 3) gross_salary += ((tableRef[person[i].rank-1][2]/100) * tableRef[person[i].rank-1][0]) * person[i].child;
		else if (person[i].child > 3) gross_salary += ((tableRef[person[i].rank-1][2]/100) * tableRef[person[i].rank-1][0]) * 3;
		
		net_salary = gross_salary - gross_salary * tableRef[person[i].rank-1][3];
		person[i].salary = tableRef[person[i].rank-1][0];
		person[i].gross_salary = gross_salary;
		person[i].net_salary = net_salary;
	}
}

void titleScreen() {
    system("cls");
    printf("Algoritma dan Pemrograman-01\n");
    printf("Group 18:\n");
    printf("Irfan Arif Maulana\t\t(1906379270)\n");
    printf("Raden Wisnu Andhika Pranidhia\t(1906379270)\n\n");
    printf("Teknik Elektro Fakultas Teknik\n");
    printf("Universitas Indonesia 2021\n\n");
    printf("\"Exercise 5 - Array 1D and 2D\"");
    
    holdScreen();
}

void holdScreen() {
    printf("\n\n\n\nPress any key to continue . . . ");
    getch();
    system("cls");
}

int option() {
    int input;
    
    printf("Menu:");
    printf("\n1. Input employee data\n2. Display employee data\n3. Rank Criteria\n4. Exit program");
    printf("\n\nInsert your input (number): ");

    while(1) {
        scanf("%d", &input);
        if(input >= 1 && input <= 4) break;
        else printf("Option %d is not available.\n\nPlease re-input: ", input);
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
