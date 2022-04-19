//
// Created by aliakseiklimau on 4/19/22.
//

#include "htab.h"
#include "htab_pr.h"
#include "malloc.h"

bool htab_erase(htab_t * table, htab_key_t key)
{

    size_t index = htab_hash_function(key) % table->arr_size;
    struct htab_item *item = table->arr_ptr[index];
    struct htab_item *item_tmp = item;

    if (item == NULL)
        return false;

    if (strcmp(item->pair.key, key) == 0)
    {
        table->arr_ptr[index] = item->next;
        table->size--;
        free((char *) item->pair.key);
        free(item);
        return true;
    } else
    {
        item = item->next;
        while (item != NULL)
        {
            if (strcmp(item->pair.key, key) == 0)
            {
                item_tmp->next = item->next;
                table->size--;
                free((char *) item->pair.key);
                free(item);
                return true;
            }
            item_tmp = item;
            item = item->next;
        }
    }
    return false;


}