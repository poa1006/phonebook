#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define TABLE_SIZE 42737

// change the struct
typedef struct __LAST_NAME_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    struct __LAST_NAME_DETAIL *pDetail;
    struct __LAST_NAME_ENTRY *pNext;
}entry;

typedef struct __LAST_NAME_DETAIL {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} details;

void impl_initialize();
int GetHashKey(char *lastName,int size);
entry *findName(char lastname[], entry *e);
entry *append(char lastName[], entry *e);

#endif
