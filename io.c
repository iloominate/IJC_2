// io.c
// IJC-DU2, 20.04.2022
// Author: Aliaksei Klimau, FIT
// Compiled: gcc 7.5.0


#include "io.h"

int read_word(char *s, int max, FILE *f) {
    if (!f) {
        fprintf(stderr, "Invalid file \n");
        return -1;
    }
    if (max < 0) {
        fprintf(stderr, "Invalid max length \n");
        return -1;
    }

    int c;
    int c_counter = 0;

    // skip spaces in the beginning
    while ((c = fgetc(f)) && isspace(c)) {}

    if (c == EOF)
        return EOF;

    s[c_counter++] = c;

    while (c_counter < max - 1) {
        c = fgetc(f);

        if (isspace(c) || c == EOF)
            break;

        s[c_counter++] = c;
    }


    s[c_counter] = '\0';

    if (max == c_counter + 1)
    {
        while (1)
        {
            if ((c = fgetc(f) == EOF) || isspace(c))
                break;
            else c_counter++;
        }
    }
    return c_counter;
}