#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "list.h"

struct piece {
    int x;
    int y;
};

int BOARD_SIZE = 10;

struct node* head;
struct piece* apple;
enum direction{up, right, down, left};

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
            if (find_match(head, j, i) != NULL) {
                putchar('o');
            } else if (apple->x == j && apple->y == i) {
                putchar('@');
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

int is_move_possible(int x, int y) {
    return find_match(head, x, y) == NULL && y >= 0 && x >= 0 && y < BOARD_SIZE && x < BOARD_SIZE;
}



void create_apple(char board[][BOARD_SIZE], struct piece* apple) {
    while (1) {
        int x = rand() % BOARD_SIZE;
        int y = rand() % BOARD_SIZE;
        if (board[y][x] == '.' && find_match(head, x, y) == NULL) {
            apple->x = x;
            apple->y = y;
            return;
        }
    }

}

//Fix this thing to work with real time input.
enum direction get_direction() {

    char c;
    scanf("%c\n", &c);
    if (c == 'w') return up;
    if (c == 'a') return left;
    if (c == 's') return down;
    if (c == 'd') return right;
    exit(1); //rip
}


void run() {
    char board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);

    srand(time(NULL));
    head = create(BOARD_SIZE / 2, BOARD_SIZE / 2);

    apple = (struct piece*) malloc(sizeof(struct piece));
    create_apple(board, apple);

    enum direction direction;
    int grow = 2;       //times left to grow
    int apples_eaten = 0;

    update(board);
    while(1) {

        int x = head->x;
        int y = head->y;
        direction = get_direction();

        if (direction == up) y--;
        else if (direction == right) x++;
        else if (direction == down) y++;
        else if (direction == left) x--;

        if (!is_move_possible(x, y)) {
            printf("Game Over\n");
            printf("Apples eaten %d\n", apples_eaten);
            exit(0);
        } else {
            head = add_first(head, x, y);
        }

        if (apple->x == x && apple->y == y) {
            create_apple(board, apple);
            grow++;
            apples_eaten++;
        }

        if (grow == 0) {
            remove_last(head);
        } else {
            grow--;
        }

        update(board);
    }
}


int main() {
    run();
    return 0;
}
