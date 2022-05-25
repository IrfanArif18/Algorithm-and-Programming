#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
    char nama[50];
    int kode;
    int sks;
    char nilai;
    int *jmlMatkul;
};

void inputData();

int main() {
    struct data *siswa[3];

    int jumlahMatkul = (struct list *)malloc(sizeof(struct list));
    printf("Masukkan berapa banyak mahasiswa: ");
    scanf("%d", &jumlahSiswa);
    printf("Masukkan berapa banyak matakuliah: ");
    scanf("%d", &jumlahMatkul);


    return 0;
}