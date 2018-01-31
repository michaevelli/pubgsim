#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1
#define TEAMS 100

int teama(int array[SIZE][TEAMS]);
int alive(int array[SIZE][TEAMS]);
int print(int array[SIZE][TEAMS]);

int main(void){
    srand(time(NULL));

    int ppl[SIZE][TEAMS];
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < TEAMS; j++){
            ppl[i][j] = 0;
        }
    }

    int change = alive(ppl);
    while(alive(ppl) > 1){
        int rx = rand()%TEAMS;
        int ry = rand()%SIZE;
        ppl[ry][rx] = 1;
        if(alive(ppl) != change){
            printf("%d\t", teama(ppl));
            change = alive(ppl);
        }
    }
    printf("\n");
}


int teama(int array[SIZE][TEAMS]){
    int teams = 0;
    for(int i = 0; i < TEAMS; i++){
        for(int j = 0; j < SIZE; j++){
            if(array[j][i] == 0){
                teams++;
                break;
            }
        }
    }
    return teams;
}

int alive(int array[SIZE][TEAMS]){
    int al = 0;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < TEAMS; j++){
            if(array[i][j] == 0){
                al++;
            }
        }
    }
    return al;
}

int print(int array[SIZE][TEAMS]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < TEAMS; j++){
            if(array[i][j] == 0){
                printf("O");
            } else {
                printf("X");
            }
        }
        printf("\n");
    }
}