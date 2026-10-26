#include "ds.h"

void create_thread(pthread_t thread, void *(*fn)(), void *lst)
{
    void *result;

    if(pthread_create(&thread, NULL, fn(lst), NULL) != 0)
        fprintf(stderr, "Error: pthread_create()");

    int s = pthread_join(thread, &result);

    puts("This is create_thread...");
}
