#include "list.h"
#include <stdlib.h>
#include <stdio.h>



struct node* create(int x, int y) {
    struct node* new = (struct node*) malloc(sizeof(struct node));

    if (!new) {
        printf("couldn't create new linked list node.\n");
        exit(1);
    }

    new->x = x;
    new->y = y;
    return new;
}

void add_last(struct node* head, int x, int y) {

    while (head->next != NULL) {
        head = head->next;
    }

    struct node* new = create(x, y);
    if (!new) {
        printf("failed to create a new linked list node.\n");
        exit(1);
    }
    head->next = new;
}

struct node* find_match(struct node* head, int x, int y) {
    while (head != NULL) {
        if (head->x == x && head->y == y) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

//Doesn't check if last node is also the first but that shouldn't happen in this game.
void remove_last(struct node* head) {
    struct node* temp = head;
    struct node* prev;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp-> next;
    }
    free(temp);
    prev->next = NULL;
}

struct node* add_first(struct node* head, int x, int y) {
    struct node* new = create(x, y);
    if (!new) {
        printf("failed to create a new linked list node.\n");
        exit(1);
    }
    new->next = head;
    return new;
}

void print_list(struct node* head) {
    while (head != NULL) {
        printf("x: %d, y: %d", head->x, head->y);
        head = head->next;
    }
    printf("\n");
}

int list_size(struct node* head) {
    int size = 0;
    while (head != NULL) {
        size++;
        head = head->next;
    }
    printf("debug size: %d\n", size);
    return size;
}