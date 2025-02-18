/*
** EPITECH PROJECT, 2025
** B-CPE-110-RUN-1-1-secured-brandon-jean-samuel.begue
** File description:
** Delete a node in tha hastable given its key
*/
#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>

void free_value(data_list_t *data)
{
    if (data->value != NULL)
        free(data->value);
    free(data);
}

void delete_key(hashtable_t *ht, int id, int key)
{
    data_list_t *current = ht->data_list[id];
    data_list_t *next = NULL;

    while (current->next != NULL) {
        if (current->next->key == key) {
            next = current->next;
            current->next = current->next->next;
            free_value(next);
        } else
            current = current->next;
    }
}

int ht_delete(hashtable_t *ht, char *key)
{
    int hashed = 0;
    int id = 0;
    data_list_t **data = NULL;
    data_list_t *tmp = NULL;

    if (!ht || !key)
        return 84;
    hashed = ht->hash_func(key, ht->len);
    id = hashed % ht->len;
    data = ht->data_list;
    if (!data || !data[id])
        return 84;
    tmp = data[id];
    if (data[id]->key == hashed) {
        data[id] = data[id]->next;
        free_value(tmp);
    } else
        delete_key(ht, id, hashed);
    return 0;
}
