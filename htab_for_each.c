//
// Created by aliakseiklimau on 4/19/22.
//

#include "htab_pr.h"
#include "htab.h"

void htab_for_each(const htab_t * table, void (*f)(htab_pair_t *data))
{
    for (int i = 0; i < table->arr_size; i++)
    {
        struct htab_item *tmp_item = table->arr_ptr[i];

        while (tmp_item != NULL)
        {
            (*f)(&tmp_item->pair);
            tmp_item = tmp_item->next;
        }
    }
}