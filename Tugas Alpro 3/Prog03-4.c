#include <stdio.h>

int inputNumb();
int cekNumb(int numb);
void sumDigit(int numb);

int main() {
    int numb;
    printf("Kelompok 18\n");
    printf("Program sum of digits of a five digit number\n");
    numb = inputNumb();
    numb = cekNumb(numb);
    sumDigit(numb);
}

int inputNumb() {
    int numb;
    
    printf("\n\nEnter a positive 5 digit number: ");
    scanf("%d", &numb);
    
    return numb;
}

int cekNumb(int numb){
    if(numb >= 10000 && numb <= 99999){
        return numb;
    }
    else{
        printf("Wrong input, please re-enter a positive 5 digit number: ");
        scanf("%d", &numb);
        numb = cekNumb(numb);
        return numb;
    }
}

void sumDigit(int numb){
    printf("%d", (((numb/10000) % 10) + ((numb/1000) % 10) + ((numb/100) % 10) + ((numb/10) % 10) + ((numb/1) % 10)) );
}

