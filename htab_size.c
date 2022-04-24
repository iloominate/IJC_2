// htab_size.c
// IJC-DU2, 20.04.2022
// Author: Aliaksei Klimau, FIT
// Compiled: gcc 7.5.0

#include "htab_pr.h"
#include "htab.h"

size_t htab_size( const htab_t* table)
{
    return table->size;
}