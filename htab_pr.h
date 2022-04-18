//
// Created by aliakseiklimau on 4/18/22.
//

#ifndef UNTITLED2_HTAB_PR_H
#define UNTITLED2_HTAB_PR_H


#include "htab.h"

struct htab_item
{
    htab_pair_t pair;
    struct htab_item *next;

};

struct htab
{
    size_t size;
    size_t arr_size;
    size_t *arr_ptr[];
};

#endif //UNTITLED2_HTAB_PR_H
