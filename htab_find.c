// htab_find.c
// IJC-DU2, 20.04.2022
// Author: Aliaksei Klimau, FIT
// Compiled: gcc 7.5.0

#include "htab_pr.h"
#include "htab.h"
#include <string.h>

htab_pair_t * htab_find(htab_t * table, htab_key_t key)
{


    for (int i = 0; i < table->arr_size; i++)
    {
        struct htab_item *tmp_item = table->arr_ptr[i];


        // check the first bucket
        if (strcmp(tmp_item->pair->key, key) == 0)
            return tmp_item->pair;

        while (tmp_item->next != NULL)
        {
            if (strcmp(tmp_item->pair->key, key) == 0)
                return tmp_item->pair;
            tmp_item = tmp_item->next;
        }
        // check the last bucket
        if (strcmp(tmp_item->pair->key, key) == 0)
            return tmp_item->pair;

    }
    return NULL;
}