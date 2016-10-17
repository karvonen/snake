

#ifndef SNAKE_LIST_H
#define SNAKE_LIST_H

extern struct node* create(int x, int y);
extern void add_last(struct node* head, int x, int y);
extern struct node* add_first(struct node* head, int x, int y);
struct node* find_match(struct node* head, int x, int y);

#endif
