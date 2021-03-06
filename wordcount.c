// wordcount.c
// IJC-DU2, 20.04.2022
// Author: Aliaksei Klimau, FIT
// Compiled: gcc 7.5.0

#include "htab.h"
#include "htab_pr.h"
#include "stdio.h"
#include "stdlib.h"
#include <stdint.h>
#include "stdbool.h"
#include "io.h"

#ifdef HASHTEST

// djb2 by Dan Bernstein
size_t htab_hash_function (const char *str)
{
    uint32_t hash = 5381;
    int c;
    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash;
}
#endif

// min length 100 + null byte
#define MAX_SIZE_WRD 101

// Prime number for max length
#define HTAB_SIZE 16651

int main (void)
{
    bool warning_c = false;
    char s[MAX_SIZE_WRD];
    int c_counter;
    htab_pair_t *pair;

    htab_t *table = htab_init(HTAB_SIZE);
    if (table == NULL)
    {
        fprintf(stderr, "Hash table allocation error \n");
        return 1;
    }

    while ((c_counter = read_word(s, MAX_SIZE_WRD, stdin)) != EOF)
    {
        if ((c_counter >= MAX_SIZE_WRD) && !warning_c) {
            fprintf(stderr, "Word is too long \n");
            warning_c = true;
        }
        pair = htab_lookup_add(table, s);

        if (pair == NULL)
        {
            fprintf(stderr, "Pair allocation error \n");
            htab_free(table);
            return 1;
        }
        pair->value++;
        printf("%s\t%d\n", pair->key, pair->value);
    }

    htab_for_each(table, htab_print_t);

    htab_free(table);
    return 0;

}