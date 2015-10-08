#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "phonebook_opt.h"

hashtable *CreateTable(int size)
{

    hashtable *hasht= NULL;
    int i ;
    if(size<1)
        return NULL;
    if((hasht = malloc(sizeof(hashtable)))==NULL)
        return NULL;
    if((hasht -> table = malloc(sizeof(entry*)*size))==NULL)
        return NULL;

    for(i=0; i<size; i++)
        hasht ->table[i]=NULL;

    hasht ->size = size;

    return hasht;
}

int GetHashKey(char *lastName,int size)
{

    if (!lastName) return 0;
    int hash, i, val;
    for (hash = 0, i = 0, val = 1; *lastName != '\0'; i++, lastName++) {
        hash = (hash<<4) ^ (hash>>28) ^ *lastName;
        val = val * 31 + (*lastName - 'a');
    }
    return abs(val % size);
}


/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], hashtable *hasht)
{

    entry *tmp_entry;
    int index = GetHashKey(lastName, hasht->size);

    tmp_entry=hasht->table[index];
    while(tmp_entry) {
        if(strcmp(lastName,tmp_entry->lastName)==0)
            return tmp_entry;
        tmp_entry=tmp_entry->pNext;
    }
    return NULL;
}

entry *append(char lastName[], hashtable *hasht)
{
    int index = GetHashKey(lastName,hasht->size);

    entry *newEntry;
    entry *curEntry;

    // Append
    if(hasht->table[index]) {
        newEntry = hasht->table[index];

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
        hasht->table[index] = newEntry;
        return newEntry;
    }
}
