#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    char *name;
    int *data;
    int ptr;
    int size;
};

typedef struct 
{
    struct Node linkedlist;
    struct Stack stack;
} datastructures_t;

FILE *linkedlist_error_log();
void *new_node();
void list_insert(struct Node **, int);

#endif
