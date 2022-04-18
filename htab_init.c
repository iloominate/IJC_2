



#include "htab.h"
#include <stdlib.h>
#include "htab_pr.h"

htab_t *htab_init(size_t size_n) {

    htab_t *table;
    table = malloc (sizeof(htab_t) + size_n * sizeof(struct htab_item));

    table->size = 0;
    table->arr_size = size_n;

    for (int i = 0; i < size_n; i++)
        table->arr_ptr[i] = NULL;
    return table;
}


