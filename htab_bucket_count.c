//
// Created by aliakseiklimau on 4/18/22.
//

#include "htab.h"
#include "htab_pr.h"

size_t htab_bucket_count (const htab_t *table)
{
    return table->arr_size;
}
