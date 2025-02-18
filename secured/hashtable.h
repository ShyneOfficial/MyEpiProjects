/*
** EPITECH PROJECT, 2025
** B-CPE-110-RUN-1-1-secured-brandon-jean-samuel.begue
** File description:
** hashtable_h
*/
#ifndef HASHTABLE_H
    #define HASHTABLE_H
    #include "my.h"

typedef struct data_list_s {
    int key;
    char *value;
    struct data_list_s *next;
} data_list_t;

typedef struct hashtable_s {
    int (*hash_func)(char *, int);
    int len;
    data_list_t **data_list;
} hashtable_t;

int hash(char *key, int len);
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);
#endif /* HASHTABLE_H */
