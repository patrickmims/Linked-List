#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node
{
    int data;
    struct Node *next;
};

FILE *linkedlist_error_log();
void *new_node();
void list_insert(struct Node **, int);

#endif
