#include <stdlib.h>
#include <stdio.h>
#include <zconf.h>
#include <time.h>
#include "list.h"

int BOARD_SIZE = 20;
int grow = 1;
int apples_eaten = 0;
struct node* head;

struct piece {
    int x;
    int y;
};


void clear_screen()
{
//    system("@cls||clear");
    system("clear");
}

void update(char board[][BOARD_SIZE]) {
    clear_screen();
    for (int k = 0; k < BOARD_SIZE + 2; ++k) {
        printf("#");
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; ++i) {
        printf("#");
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (find_match(head, j, i)) {
                putchar('o');
            } else putchar(board[i][j]);
        }
        printf("#\n");
    }
    for (int k = 0; k < BOARD_SIZE + 2; ++k) {
        printf("#");
    }
    printf("\n");
}

void initialize_board(char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
                board[i][j] = '.';
            }
        }
}

void remove_piece(char board[][BOARD_SIZE], int y, int x) {
    board[y][x] = '.';
}

int check_collision(char board[][BOARD_SIZE], int y, int x) {
    return find_match(head, y, x) == NULL && y >= 0 && x >= 0 && y < BOARD_SIZE && x < BOARD_SIZE;
}



void create_apple(char board[][BOARD_SIZE], struct piece* apple) {
    while (1) {
        int x = rand();
        int y = rand();
        if (board[y][x] == '.') {
            board[y][x] = '@';
            return;
        }
    }

}

void run() {
    char board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);


    srand(time(NULL));
    struct node* head = create(9, 9);

    head->y = 10;
    head->x = 10;

    while(1) {
        update(board);
        if (grow == 0 || apples_eaten > 2) {


        } else {
            grow--;
        }
        sleep(1);
    }

}


int main() {
    run();
    return 0;
}
