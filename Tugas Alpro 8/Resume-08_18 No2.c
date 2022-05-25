#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct complex {
    float re;
    float im;
} complex;

 complex insertNum();
 void printNum(complex*);
 complex sum(complex, complex);
 complex mul(complex, complex);
 int checkInt(float);

int main() {
    complex a, b, sumOut, mulOut;
    
    system("cls");
    printf("PROGRAM PENJUMLAHAN DAN PERKALIAN BILANGAN KOMPLEKS\n\n");

    printf("\nUntuk bilangan kompleks pertama,\n");
    a = insertNum();
    printf("\nUntuk bilangan kompleks kedua,\n");
    b = insertNum();

    printf("\n\nAnda memasukkan:");
    printf("\na = ");
    printNum(&a);
    printf("\nb = ");
    printNum(&b);

    sumOut = sum(a, b);
    mulOut = mul(a, b);

    printf("\n\n\nOutput:");
    printf("\na + b = ");
    printNum(&sumOut);
    printf("\na * b = ");
    printNum(&mulOut);

    printf("\n\n\n\nTekan tombol apa saja untuk mengakhiri program . . . ");
    getch();

    return 0;
}

complex insertNum() {
    complex input;

    printf("Masukkan nilai komponen real: ");
    scanf("%f", &input.re);
    printf("Masukkan nilai komponen imajiner: ");
    scanf("%f", &input.im);

    return input;
}

void printNum(complex* c) {
    if(checkInt(c->re)) {
        printf("%.0f", c->re);
    } else {
        printf("%.3f", c->re);
    }

    if(c->im >= 0) {
        printf(" + ");
    } else {
        printf(" - ");
    }

    if(c->im == 1) {
        printf("i");
    } else if(checkInt(c->im)) {
        printf("i%.0f", fabs(c->im));
    } else {
        printf("i%.3f", fabs(c->im));
    }
}

complex sum(complex a, complex b) {
    complex sum;
    sum.re = a.re + b.re;
    sum.im = a.im + b.im;
    return sum;
}

complex mul(complex a, complex b) {
    complex mul;
    mul.re = (a.re * b.re) - (a.im * b.im);
    mul.im = (a.re * b.im) + (a.im * b.re);
    return mul;
}

int checkInt(float numb) {
    if(numb / floor(numb) == 1) {
        return 1;
    } else {
        return 0;
    }
}