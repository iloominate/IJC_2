//
// Created by aliakseiklimau on 4/18/22.
//

#include "htab_pr.h"
#include "htab.h"

void htab_resize(htab_t *table, size_t newn)
{
    htab_t *new_table;
    htab_t *tmp_table = table;

    new_table = htab_init(newn);

    for (int i = 0; i < table->arr_size; i++)
    {
        struct htab_item *tmp_item = table->arr_ptr[i];

        while (tmp_item->next != NULL)
        {
            htab_lookup_add(new_table, tmp_item->pair.key);
            tmp_item = tmp_item->next;
        }
        // check the last bucket
        if (tmp_item->pair.key != NULL)
            htab_lookup_add(new_table, tmp_item->pair.key);
    }

    table = new_table;
    htab_clear(tmp_table);
    htab_free(tmp_table);

}