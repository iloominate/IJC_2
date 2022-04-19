//
// Created by aliakseiklimau on 4/18/22.
//

#ifndef UNTITLED2_HTAB_PR_H
#define UNTITLED2_HTAB_PR_H


#include "htab.h"
#define AVG_LEN_MAX 4
#define AVG_LEN_MIN 1

struct htab_item
{
    htab_pair_t pair;
    struct htab_item *next;

};

struct htab
{
    size_t size;
    size_t arr_size;
    struct htab_item *arr_ptr[];
};

#endif //UNTITLED2_HTAB_PR_H
