// htab_print_t.c
// IJC-DU2, 20.04.2022
// Author: Aliaksei Klimau, FIT
// Compiled: gcc 7.5.0

#include "htab_pr.h"
#include "htab.h"
#include "stdio.h"

void htab_print_t (htab_pair_t *pair)
{
    printf("%s\t%d\n", pair->key, pair->value);
}
