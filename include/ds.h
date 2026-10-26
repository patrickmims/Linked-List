#ifndef DS_H
#define DS_H

#include <curl/curl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

FILE *process_error_log();
void create_process(pid_t);
void create_thread(pthread_t, void *(*)(void *), void *);
void *get_json(void *);
void *requesthttp(void *(*)(void *), void *);

#endif
