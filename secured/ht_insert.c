/*
** EPITECH PROJECT, 2025
** B-CPE-110-RUN-1-1-secured-brandon-jean-samuel.begue
** File description:
** Add an element in the hashtable given a key and a value
*/
#include "my.h"
#include "hashtable.h"
#include <string.h>

void set_data(hashtable_t *ht, data_list_t *data, int id)
{
    data_list_t *current = ht->data_list[id];
    data_list_t *last = NULL;

    if (current == NULL) {
        ht->data_list[id] = data;
        return;
    }
    while (current != NULL) {
        if (current->key == data->key) {
            free(current->value);
            current->value = data->value;
            free(data);
            return;
        }
        last = current;
        current = current->next;
    }
    last->next = data;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    data_list_t *data = NULL;
    int hashed = 0;
    int id = 0;

    if (!ht || !key)
        return 84;
    data = malloc(sizeof(data_list_t));
    if (!data)
        return 84;
    hashed = ht->hash_func(key, ht->len);
    id = hashed % ht->len;
    data->key = hashed;
    data->value = NULL;
    if (value != NULL)
        data->value = my_strdup(value);
    data->next = NULL;
    set_data(ht, data, id);
    return 0;
}
