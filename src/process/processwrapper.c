#include "ds.h"
#include "linkedlist.h"

datastructures_t l; // create a reference to

FILE *process_error_log() // <= error
{
    FILE *filePtr = NULL; 

    if((filePtr = fopen("error_log.txt", "a")) == NULL)
        exit(EXIT_FAILURE);

    return filePtr;
}

// This should be the file you're going to call to do the work in the thread
void modifyMe(datastructures_t *d)
{
    d->stack.ptr = 55;
    printf("What's in this function: %d\n", d->stack.ptr);
}

/* ------------------------------------------------ void get_json(void *) */

void *get_json(void *ptr) // <= function that runs in the thread
{
    datastructures_t *p = (datastructures_t * )ptr;  // <= Cast before using
    p->linkedlist.data = 5000; // <= Test data - and it works!
    printf("get_json() [ %d ]\n", p->linkedlist.data);
}

/* ------------------------------------------- void create_process(pid_t) */

void create_process(pid_t process)
{
    datastructures_t *list = &l; // Create a pointer to the reference above

    // Crete a function pointer to get_json(), which takes one param
    void *(*fn)(void *) = get_json;  // This runs in the background

    // Determine if the process is successful
    switch(process = fork())
    {
        case -1:
            fprintf(process_error_log(), "Error: create_process()");
            break;
        case 0: 
            pthread_t thread; // define and pass the thread
            create_thread(thread, fn, list);
            break;
        case 1:  
            sleep(3);
            break;
    }
}
