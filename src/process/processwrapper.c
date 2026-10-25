#include "ds.h"
#include "linkedlist.h"

FILE *process_error_log()
{
    FILE *filePtr = NULL; 

    if((filePtr = fopen("error_log.txt", "a")) == NULL)
        exit(EXIT_FAILURE);

    return filePtr;
}

void create_process(pid_t process)
{
    switch(process = fork())
    {
        case -1:
            fprintf(process_error_log(), "Error: create_process()");
        case 1: 
            struct Node ll;
            struct Node *linkedlist = NULL;
            linkedlist = &ll;
            puts("process wrapper, case 1");
            // create_thread();
            break;
        case 0:  
            sleep(3);
            break;
    }
}
