#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "phonebook_opt.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
last_name_entry *findName_v1(char lastName[], last_name_entry *pHead)
{
    while(pHead!=NULL) {
        if (strcasecmp(lastName, pHead->lastName) == 0) {
            printf(" %12s  is found!\n", lastName);
            return pHead;
        }
        pHead = pHead -> pNext;
    }
    printf("%12s is found\n", lastName);
    return NULL;
}

last_name_entry *append_v1(char lastName[], last_name_entry *e)
{
    e->pNext = (last_name_entry *) malloc(sizeof(last_name_entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;

    return e;
}
