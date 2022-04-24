// htab_erase.c
// IJC-DU2, 20.04.2022
// Author: Aliaksei Klimau, FIT
// Compiled: gcc 7.5.0

#include "htab.h"
#include "htab_pr.h"
#include "malloc.h"
#include <math.h>

bool htab_erase(htab_t * table, htab_key_t key)
{

    size_t index = htab_hash_function(key) % table->arr_size;
    struct htab_item *item = table->arr_ptr[index];
    struct htab_item *item_tmp = item;

    if (item == NULL)
        return false;

    if (strcmp(item->pair->key, key) == 0)
    {
        table->arr_ptr[index] = item->next;
        table->size--;
        free((char *) item->pair->key);
        free(item);
        if ((table->size / table->arr_size) < AVG_LEN_MIN)
            htab_resize(table, table->size / 2);
        return true;
    } else
    {
        item = item->next;
        while (item != NULL)
        {
            if (strcmp(item->pair->key, key) == 0)
            {
                item_tmp->next = item->next;
                table->size--;
                free((char *) item->pair->key);
                free(item);
                if ((table->size / table->arr_size) < AVG_LEN_MIN)
                    htab_resize(table, table->size / 2);
                return true;
            }
            item_tmp = item;
            item = item->next;
        }
    }
    return false;


}