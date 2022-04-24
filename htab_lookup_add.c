// htab_lookup_add.c
// IJC-DU2, 20.04.2022
// Author: Aliaksei Klimau, FIT
// Compiled: gcc 7.5.0


#include "htab.h"
#include "htab_pr.h"
#include <stdio.h>
#include <strings.h>
#include <malloc.h>

htab_pair_t * htab_lookup_add(htab_t * table, htab_key_t key)
{
    size_t index = (htab_hash_function(key) % table->arr_size);
    struct htab_item *new_item;

    new_item = malloc(sizeof(struct htab_item));
    if (new_item == NULL)
    {
        fprintf(stderr, "Memory allocation error \n");
        free(new_item);
        return NULL;
    }
    new_item->next = NULL;
    new_item->pair = malloc(sizeof(htab_pair_t));

    if (new_item->pair == NULL)
    {
        fprintf(stderr, "Memory allocation error \n");
        free(new_item->pair);
        free(new_item);
        return NULL;
    }

    new_item->pair->key = malloc(strlen(key) + 1);
    strcpy((char *)new_item->pair->key, key);

    if (table->arr_ptr[index] == NULL)
    {
        table->arr_ptr[index] = new_item;
        table->size++;
        return new_item->pair;
    } else {
        struct htab_item *curr;
        struct htab_item *last;
        curr = table->arr_ptr[index];
        table->size++;

        while ( curr != NULL) {
            if (strcmp(curr->pair->key, key) == 0)
                return curr->pair;
            last = curr;
            curr = curr->next;
        }

        if ((table->size / table->arr_size) > AVG_LEN_MAX )
            htab_resize(table, table->arr_size*2);

        last->next = new_item;

        return new_item->pair;
    }
}