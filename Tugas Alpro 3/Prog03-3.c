#include <stdio.h>

int inputNumb();
int cekLimit(int numb);
void outputFormat(int numb);

int main(){
    int numb;

    numb = inputNumb();
    numb = cekLimit(numb);
    outputFormat(numb);

    return 0;
}

int inputNumb(){
    int numb;
    printf("Kelompok 18\n");
    printf("Program conditional statements in c\n\n");
    printf("Enter your input: ");
    scanf("%d", &numb);
    
    return numb;
}

int cekLimit(int numb){
    if(numb >= 1 && numb <= 1000000000){
        return numb;
    }
    else{
        system("cls");
        printf("Input range invalid (1<= n <= 10^9)\n");
        printf("Please, re-enter your input: ");
        scanf("%d", &numb);
        numb = cekLimit(numb);
        return numb;
    }
}

void outputFormat(int numb){
    if(numb >= 1 && numb <= 9){
        if(numb == 1) printf("one\n");
        else if(numb == 2) printf("two\n");
        else if(numb == 3) printf("three\n");
        else if(numb == 4) printf("four\n");
        else if(numb == 5) printf("five\n");
        else if(numb == 6) printf("six\n");
        else if(numb == 7) printf("seven\n");
        else if(numb == 8) printf("eight\n");
        else if(numb == 9) printf("nine\n");    
    }else printf("Greater than 9\n");
}

