// htab_free.c
// IJC-DU2, 20.04.2022
// Author: Aliaksei Klimau, FIT
// Compiled: gcc 7.5.0


#include "htab_pr.h"
#include "htab.h"
#include <malloc.h>


void htab_free(htab_t * table)
{
    htab_clear(table);
    free(table);
}