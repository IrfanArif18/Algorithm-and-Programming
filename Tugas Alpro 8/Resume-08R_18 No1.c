#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QTTY 10
#define PLY 2

typedef struct dominoCard {
    int num1;
    int num2;
} dominoCard;

typedef struct player {
    dominoCard card[QTTY];
    int sumRound;
    int total;
} player;

void initPlayer(player[]);
void game(player[]);
int random(int, int);
void delay(int);

int main() {
    srand(time(NULL));
    player player[PLY];
    initPlayer(player);

    system("cls");
    printf("DOMINO CARD PROGRAM\n\n\n");

    game(player);

    printf("\n\n\n\nPress any key to END program . . . ");
    getch();

    return 0;
}

void initPlayer(player player[]) {
    int i;
    for(i = 0; i < PLY; i++) player[i].total = 0;
}

void game(player player[]) {
    int cd, pl;

    for(cd = 0; cd < QTTY; cd++) {
        printf("ROUND %d:\n", cd + 1);

        for(pl = 0; pl < PLY; pl++) {
            player[pl].card[cd].num1 = random(0, 6);
            player[pl].card[cd].num2 = random(0, 6);
            player[pl].sumRound = player[pl].card[cd].num1 + player[pl].card[cd].num2;
            player[pl].total += player[pl].sumRound;
            printf("Player %d: %d + %d = %d\n", pl + 1, player[pl].card[cd].num1, player[pl].card[cd].num2, player[pl].sumRound);
        }

        if(player[0].sumRound > player[1].sumRound) {
            printf("(Player %d wins!)\n", 1);
        } else {
            printf("(Player %d wins!)\n", 2);
        }

        printf("\n");
        delay(250);
    }

    printf("\nRESULT:\n");
    if(player[0].total > player[1].total) {
        printf("Player %d won the game! With total = %d\n", 1, player[0].total);
    } else {
        printf("Player %d won the game! With total = %d\n", 2, player[1].total);
    }
}

int random(int low, int up) {
    int num, i;

    if(low <= up) {
        num = (rand() % (up - low + 1)) + low;     
        return num;
    } else {
        printf("\n\nPROGRAMMER ERROR\n");
        printf("Invalid argument (%d >= %d). Lower bound must be less than upper bound!", low, up);
        printf("Press any key to continue . . . ");
        getch();
        return -1;
    }
}

void delay(int ms) {
    long pause;
    clock_t now, then;

    pause = ms * (CLOCKS_PER_SEC / 1000);
    now = clock();
    then = now;
    while((now - then) < pause) {
        now = clock();
    }
}
