#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QTTY 10 // Number of rounds (card draw chances per player)
#define PLY 5 // Number of players

typedef struct dominoCard {
    int num1;
    int num2;
} dominoCard;

typedef struct player {
    dominoCard card[QTTY];
    int sumRound;
    int sumGame;
    int winCount;
} player;

void initPlayer(player[]);
void game(player[]);
int drawCard(int, int);
int searchRound(player[]);
int searchGame(player[]);
void delay(int);
int restart();

int main() {
    player player[PLY];
    
    do {
        srand(time(NULL));
        initPlayer(player);
        system("cls");
        printf("DOMINO CARD GAME\n\n\n");
        game(player);
    } while(restart());

    return 0;
}

void initPlayer(player player[]) {
    int i;
    for(i = 0; i < PLY; i++) {
        player[i].sumGame = 0;
        player[i].winCount = 0;
    }
}

void game(player player[]) {
    int win, cd, pl;

    for(cd = 0; cd < QTTY; cd++) {
        printf("ROUND %d:\n", cd + 1);
        for(pl = 0; pl < PLY; pl++) {
            player[pl].card[cd].num1 = drawCard(0, 6);
            player[pl].card[cd].num2 = drawCard(0, 6);
            player[pl].sumRound = player[pl].card[cd].num1 + player[pl].card[cd].num2;
            player[pl].sumGame += player[pl].sumRound;
            printf("Player %d: %d + %d = %d\n", pl + 1, player[pl].card[cd].num1, player[pl].card[cd].num2, player[pl].sumRound);
        }

        win = searchRound(player);
        printf("(Player %d won the round!)\n\n", win + 1);
        delay(250); // Delay in between rounds
    }

    printf("\n\nRESULT:\n");
    for(pl = 0; pl < PLY; pl++)
        printf("Player %d\t: Won %d/%d with total %d\n", pl +1, player[pl].winCount, QTTY, player[pl].sumGame);

    win = searchGame(player);
    printf("\nPlayer %d won the game! With total = %d", win + 1, player[win].sumGame);
}

int drawCard(int low, int up) {
    int num;

    if(low <= up) {
        num = (rand() % (up - low + 1)) + low;     
        return num;
    } else {
        printf("\n\nPROGRAMMER ERROR\n");
        printf("Invalid argument (%d >= %d). Lower bound must be less than upper bound!", low, up);
        printf("\nPress any key to continue . . . ");
        getch();
        printf("\n");
        return -1;
    }
}

int searchRound(player player[]) {
    int index = 0, i;
    for(i = 1; i < PLY; i++)
        if(player[i].sumRound > player[index].sumRound)
            index = i;
    player[index].winCount++;
    return index;
}

int searchGame(player player[]) {
    int index = 0, win, sum;
    for(win = 1; win < PLY; win++)
        if(player[win].winCount > player[index].winCount)
            for(sum = 1; sum < PLY; sum++)
                if(player[sum].sumGame > player[index].sumGame) {
                    index = sum;
                } else {
                    index = win;
                }
    return index;
}

void delay(int ms) {
    long pause;
    clock_t now, then;

    pause = ms * (CLOCKS_PER_SEC / 1000);
    now = clock();
    then = now;
    while((now - then) < pause) now = clock();
}

int restart() {
    char input;

    printf("\n\n\n\nPlay again? [Y/N]: ");
    while(1) {
        scanf(" %c", &input);
        if(input == 'Y' || input == 'y' || input == 'N' || input == 'n') {
            break;
        } else {
            printf("Invalid input.\n\nPlease re-input: ");
        }
    }

    if(input == 'Y' || input == 'y') {
        return 1;
    } else {
        return 0;
    }
}
