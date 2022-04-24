// tail.c
// IJC-DU2, 20.04.2022
// Author: Aliaksei Klimau, FIT
// Compiled: gcc 7.5.0

#include <stdio.h>
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"
#include <unistd.h>
#include <limits.h>


#define MAX_SIZE 4095
#define DEFAULT_SIZE 10
#include <errno.h>
int main(int argc, char *argv[]) {
    FILE *ptr = NULL;
    long file_bgn;
    long file_cur_pos;
    int n = 0;

    for (int i = 1; argv[i]; i++) {
        if (n != 0)
            continue;
        if (access(argv[i], F_OK) == 0) {
            if (ptr != NULL) {
                fprintf(stderr, "Too many files \n");
                return 1;
            }
            ptr = fopen(argv[i], "r");
            continue;
        }
        if (!strcmp(argv[i], "-n")) {
            char *helper = NULL;
            n = strtoul(argv[i+1], &helper, 10);
            if ( n < 1 )
            {
                fprintf(stderr, "Invalid n size \n");
                return 1;
            }
        }
    }
    if (!n)
        n = DEFAULT_SIZE;



    if (ptr == NULL)
    {
        ptr = stdin;
    }

    int l_counter = 0;
    int s_counter = 0;


    file_bgn = ftell(ptr);

    fseek(ptr, 0, SEEK_END);
    while (l_counter < n && file_cur_pos != file_bgn) {

        file_cur_pos = ftell(ptr);
        if (s_counter > MAX_SIZE) {
            fprintf(stderr, "Some lines are too long \n");
        }

        if (fgetc(ptr) == '\n') {
            l_counter++;
            s_counter = 0;
        }
        if (l_counter > n)
            break;
        s_counter++;
        fseek(ptr, -2, SEEK_CUR);
    }


    if (l_counter == n)
    {
        fseek(ptr, 2, SEEK_CUR);
    }
    int c = fgetc(ptr);
    while (c != EOF) {
        printf("%c", c);
        c = fgetc(ptr);
    }

    fclose(ptr);
    return 0;
}


