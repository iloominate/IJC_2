//
// Created by aliakseiklimau on 4/19/22.
//


#include "htab_pr.h"
#include "htab.h"
#include <malloc.h>


void htab_free(htab_t * table)
{
    htab_clear(table);
    free(table);
}