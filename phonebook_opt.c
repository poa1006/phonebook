#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "phonebook_opt.h"
entry *hash_table[TABLE_SIZE];

void impl_initialize()
{

    for(int i=0; i<TABLE_SIZE; i++)
        hash_table[i]=NULL;

    return ;
}

int GetHashKey(char *lastName,int size)
{

    if (!lastName) return 0;
    int  i, val;
    for ( i = 0, val = 0; *lastName != '\0'; i++, lastName++) {
        val +=val*i+*lastName;
    }
    return abs(val % size);
}



/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry *e)
{

    entry *tmp_entry;
    int index = GetHashKey(lastName, TABLE_SIZE);

    tmp_entry=hash_table[index];

    while(tmp_entry) {
        if(strcmp(lastName,tmp_entry->lastName)==0)
            return tmp_entry;
        tmp_entry=tmp_entry->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    int index = GetHashKey(lastName,TABLE_SIZE);

    entry *newEntry;
    entry *curEntry;

    // Append
    if(hash_table[index]) {
        newEntry = hash_table[index];

        while(newEntry) {
            curEntry = newEntry;
            newEntry = newEntry ->pNext;
        }
        newEntry = (entry *) malloc(sizeof(entry));
        strcpy(newEntry->lastName, lastName);
        curEntry->pNext = newEntry;
        newEntry->pNext = NULL;
        return newEntry;
    } else {
        newEntry = (entry *) malloc(sizeof(entry));
        strcpy(newEntry->lastName, lastName);
        newEntry->pNext = NULL;
        hash_table[index] = newEntry;
        return newEntry;
    }
}
