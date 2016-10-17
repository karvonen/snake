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
        if (head->x == x && head->y == y) return head;
        head = head->next;
    }
    return NULL;
}

struct node* add_first(struct node* head, int x, int y) {
    struct node* new = create(x, y);
    if (!new) {
        printf("failed to create a new linked list node.\n");
        exit(1);
    }

    head = new;
    return head;

}
