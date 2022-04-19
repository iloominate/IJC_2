//
// Created by aliakseiklimau on 4/16/22.
//

#include "htab.h"
#include "htab_pr.h"
#include "stdio.h"
#include "stdlib.h"
#include <stdint.h>

#ifdef HASHTEST

// djb2 by Dan Bernstein
size_t htab_hash_function (const char *str)
{
    uint32_t hash = 5381;
    int c;
    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash;
}
#endif
// min length 100 + null byte
#define MIN_SIZE_WRD 101

// Prime number for max length
#define MAX_SIZE_WRD 16651

int main (void)
{


}