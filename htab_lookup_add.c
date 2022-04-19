//
// Created by aliakseiklimau on 4/18/22.
//



#include "htab.h"
#include "htab_pr.h"
#include <stdio.h>
#include <strings.h>
#include <malloc.h>
#define AVG_LEN_MAX 5
htab_pair_t * htab_lookup_add(htab_t * table, htab_key_t key)
{
    int counter = 0;
    size_t index = (htab_hash_function(key) % table->arr_size);
    struct htab_item *new_item;

    new_item = malloc(sizeof(struct htab_item));
    if (new_item == NULL)
    {
        fprintf(stderr, "Memory allocation error \n");
        return NULL;
    }
    new_item->next = NULL;
    new_item->pair.key = malloc(sizeof(char) * (strlen(key) + 1));

    if (table->arr_ptr[index] == NULL)
    {
        table->arr_ptr[index] = new_item;
        table->size++;
        return &new_item->pair;
    } else
    {
        struct htab_item *tmp;
        tmp = table->arr_ptr[index];
        while ( tmp->next != NULL)
        {
            if (tmp->pair.key == key)
            {
                tmp->pair.value++;
                return &tmp->pair;
            }

            tmp = tmp->next;
            counter++;
            if (counter > AVG_LEN_MAX)
                htab_resize(table, table->size*2);
        }

        if (tmp->pair.key != key)
        {
            counter++;
            tmp->next = new_item;
            return &new_item->pair;
        }
    }
}