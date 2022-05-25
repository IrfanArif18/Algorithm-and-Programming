#include <stdio.h>

float inputNilai();
float rata2Nilai(float total);
void kategoriIP(float hasil);

int main(){
	float total_nilai, rata_nilai;
	total_nilai = inputNilai();
	rata_nilai = rata2Nilai(total_nilai);
	kategoriIP(rata_nilai);
	
	return 0;
}

float inputNilai(){
	float total = 0, n;
	int i;
	for(i = 0; i < 7; i++){
		printf("Masukkan Nilai Matkul %d: ", i+1);
		scanf("%f", &n);
		total = total + n;
	}
	return total;
}

float rata2Nilai(float total){
	float hasil;
	hasil = total / 7;
	printf("Rata-rata nilai: %.2f\n", hasil);
	return hasil;
}

void kategoriIP(float hasil){
	if(hasil <= 39.99){
		printf("IP = E");
	}
	else if(hasil <= 54.99){
		printf("IP = D");
	}
	else if(hasil <= 59.99){
		printf("IP = C");
	}
	else if(hasil <= 74.99){
		printf("IP = B");
	}
	else if(hasil <= 100){
		printf("IP = A");
	}
}
