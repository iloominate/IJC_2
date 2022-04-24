// htab_clear.c
// IJC-DU2, 20.04.2022
// Author: Aliaksei Klimau, FIT
// Compiled: gcc 7.5.0

#include "htab.h"
#include "htab_pr.h"
#include <malloc.h>
void htab_clear(htab_t * table){

    for (int i = 0; i < table->arr_size; i++)
    {
        struct htab_item *curr_item = table->arr_ptr[i];
        struct htab_item *clear_item;

        while (curr_item != NULL)
        {
            clear_item = curr_item;
            curr_item = curr_item->next;
            free((char*)clear_item->pair->key);
            free(clear_item->pair);
            free(clear_item);
        }
        table->arr_ptr[i] = NULL;
    }
    table->size = 0;
}