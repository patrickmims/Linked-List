#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

FILE *linkedlist_error_log()
{
    FILE *filePtr = NULL;

    if((filePtr = fopen("linkedlist_error_log.txt", "a")) == NULL)
        exit(EXIT_FAILURE);

    return filePtr;
}

void *new_node()
{
    void *node = NULL;

    if((node = malloc(sizeof(void *))) == NULL)
        fprintf(linkedlist_error_log(), "Error: new_node()");

    return node;
}

void list_insert(struct Node **list, int item)
{
    struct Node *node = (struct Node *)new_node();

    node->data = item;
    node->next = *list;
    *list = node;
} 
