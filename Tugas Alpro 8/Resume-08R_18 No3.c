/*  
    Exercise 8 - C structure
    Tue, 16th November 2021

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

typedef struct data {
	char nama[30];
	int jumlahMatkul;
	int *kodeMatkul;
	int *sks;
	char *nilai;
	int *bobot;
	int *status;
}Data;

int programMenu();
void helpScreen();
void exitScreen();
int option(int low, int up);
void holdScreen();
void titleScreen();
void inputData(Data *mahasiswa);
float IPK(Data *mahasiswa);
float IPL(Data *mahasiswa);
void printData(Data *mahasiswa, float IPK, float IPL);

int main() {
	int i, input, reset = 1;
	Data mahasiswa;
	titleScreen();
	do {
        switch(programMenu()) {
            case 1:
            	do{
	            	system("cls");
					printf("Masukkan nama mahasiswa = ");
					scanf("\n");
					scanf("%[^\n]s", mahasiswa.nama);	
					printf("Jumlah Matkul = ");
					mahasiswa.jumlahMatkul = option(1, 100);
					mahasiswa.kodeMatkul = (int *)malloc(mahasiswa.jumlahMatkul * sizeof(int));
					mahasiswa.sks = (int *)malloc(mahasiswa.jumlahMatkul * sizeof(int));
					mahasiswa.nilai = (char *)malloc(mahasiswa.jumlahMatkul * sizeof(char));
					mahasiswa.bobot = (int *)malloc(mahasiswa.jumlahMatkul * sizeof(int));
					mahasiswa.status = (int *)malloc(mahasiswa.jumlahMatkul * sizeof(int));
					
					inputData(&mahasiswa);
					printData(&mahasiswa, IPK(&mahasiswa), IPL(&mahasiswa));
					
					printf("\n\nApakah ingin menginput data lagi? (1/0) = ");
					input = option(0, 1);
				}while(input == 1);
                break;
            case 2:
                helpScreen();
                break;
            default:
                reset = 0;
                break;
        }
    } while(reset);

    exitScreen();	
	return 0;
}

void inputData(Data *mahasiswa) {
	int i;
	
	system("cls");
	for(i = 0; i < mahasiswa->jumlahMatkul; i++) {
		printf("Mata Kuliah ke - %d\n", i+1);
		printf("Masukkan kode = ");
		*(mahasiswa->kodeMatkul+i) = option(1, 9999999);;
		printf("Masukkan nilai = ");
		scanf("%s", mahasiswa->nilai+i);
		printf("Masukkan sks = ");
		*(mahasiswa->sks+i) = option(0, 24);
		printf("=================================\n\n");
		if(*(mahasiswa->nilai+i) < 69) *(mahasiswa->bobot+i) = 69 - *(mahasiswa->nilai+i);
		else *(mahasiswa->bobot+i) = 0;
		if(*(mahasiswa->bobot+i) > 1) *(mahasiswa->status+i) = 1;
		else *(mahasiswa->status+i) = 0;
	}
}

float IPK(Data *mahasiswa) {
	int i, sumNilaiMK = 0, sumSksMK = 0;
	float result;
	
	for(i = 0; i < mahasiswa->jumlahMatkul; i++) {
		sumNilaiMK += (*(mahasiswa->sks+i) * *(mahasiswa->bobot+i));
		sumSksMK += *(mahasiswa->sks+i);
	}
	
	result = (float)sumNilaiMK / sumSksMK;
	return result;
}

float IPL(Data *mahasiswa) {
	int i, sumNilaiMKLulus = 0, sumSksMKLulus = 0;
	float result;
	
	for(i = 0; i < mahasiswa->jumlahMatkul; i++) {
		sumNilaiMKLulus += (*(mahasiswa->sks+i) * *(mahasiswa->bobot+i) * *(mahasiswa->status+i));
		sumSksMKLulus += (*(mahasiswa->sks+i) * *(mahasiswa->status+i));
	}
	
	result = (float)sumNilaiMKLulus / sumSksMKLulus;
	return result;
}

void printData(Data *mahasiswa, float IPK, float IPL) {
	int i;
	
	system("cls");
	
	printf("Nama mahasiswa = %s", mahasiswa->nama);
	
    printf("\n\n%4s", "No");
    printf("%15s", "Kode");
    printf("%15s", "SKS");
    printf("%15s", "Nilai");
    printf("%15s", "Bobot");
    printf("%15s", "Status");
    printf("\n--------------------------------------------------");
    printf("---------------------------------------------\n");
    
    for(i = 0; i < mahasiswa->jumlahMatkul; i++) {
		printf("%4d", i+1);
        printf("%15d", *(mahasiswa->kodeMatkul+i));
		printf("%15d", *(mahasiswa->sks+i));
		printf("%15c", *(mahasiswa->nilai+i));
		printf("%15d", *(mahasiswa->bobot+i));
		*(mahasiswa->status+i) == 1 ? printf("%15s\n", "Lulus") : printf("%15s\n", "Tidak Lulus");
    }
    printf("IPK = %.2f\n", IPK);
    printf("IPL = %.2f", IPL);
}

void holdScreen() {
    printf("\n\n\n\nPress any key to continue . . . ");
    getch();
}

void titleScreen() {
    system("cls");
    printf("\"Exercise 8 - C Structure\"\n\n");
    printf("Algoritma dan Pemrograman-01\n");
    printf("Group 18:\n");
    printf("Irfan Arif Maulana\t\t(1906379270)\n");
    printf("Raden Wisnu Andhika Pranidhia\t(1906379270)\n\n");
    printf("Teknik Elektro Fakultas Teknik\n");
    printf("Universitas Indonesia 2021");
    
    holdScreen();
}

int option(int low, int up) {
    int input;

	while(1) {
        scanf("%d", &input);
        if(input >= low && input <= up) break;
        else printf("Option %d is not available.\n\nPlease re-input: ", input);
    }
    return input;
}

int programMenu() {
    system("cls");
    printf("Program Menghitung IPK dan IPL Mahasiswa\n\n\n");
    printf("Menu:\n");
    printf("1. Masuk Ke program\n2. Help\n");
    printf("3. Exit program");
    printf("\n\n");
    return inputOptionRange(1, 3);
}

int inputOptionRange(int low, int up) {
    int input;

    printf("Input your selection (number): ");
    if(low < up) {
        while(1) {
            scanf("%d", &input);
            if(input >= low && input <= up) break;
            else printf("Option %d is not available.\n\nPlease re-input: ", input);
        }
        return input;
    } else {
        printf("\n\nPROGRAMMER ERROR\n");
        printf("Invalid argument (%d >= %d). Lower bound must be less than upper bound!", low, up);
        holdScreen();
        return -1;
    }
}

void helpScreen() {
    system("cls");
    printf("HELP\n\n");
    printf("1. Masuk ke program untuk menghitung nilai IPK dan IPL\n");
    printf("2. Masuk ke help screen\n");
    printf("3. Exit Program\n");
    printf("\n\n\n\nPress any key to go back . . . ");
    getch();
}

void exitScreen() {
    system("cls");
    printf("Thank you!\n");
    printf("-Irfan and Andhika");

    printf("\n\n\n\nPress any key to exit program . . . ");
    getch();
}
