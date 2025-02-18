/*
** EPITECH PROJECT, 2025
** B-CPE-110-RUN-1-1-secured-brandon-jean-samuel.begue
** File description:
** Search through the hashtable for an element given its key
*/
#include "hashtable.h"
#include <stddef.h>

char *return_value(hashtable_t *ht, data_list_t *tmp, int id, int hashed)
{
    char *get_value = NULL;

    while (ht->data_list[id] != NULL) {
        if (ht->data_list[id]->key == hashed) {
            get_value = ht->data_list[id]->value;
            ht->data_list[id] = tmp;
            return get_value;
        }
        ht->data_list[id] = ht->data_list[id]->next;
    }
    ht->data_list[id] = tmp;
    return NULL;
}

char *ht_search(hashtable_t *ht, char *key)
{
    int len = 0;
    int hashed = 0;
    int id = 0;
    data_list_t *tmp = NULL;
    char *get_value = NULL;

    if (!ht)
        return NULL;
    len = ht->len;
    hashed = ht->hash_func(key, len);
    id = hashed % len;
    if (!ht->data_list[id])
        return NULL;
    tmp = ht->data_list[id];
    get_value = return_value(ht, tmp, id, hashed);
    if (get_value != NULL)
        return get_value;
    return NULL;
}
