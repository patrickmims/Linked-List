#ifndef DS_H
#define DS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

FILE *process_error_log();
void create_process(pid_t);

#endif
