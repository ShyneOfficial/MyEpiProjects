/*
** EPITECH PROJECT, 2025
** B-CPE-110-RUN-1-1-secured-brandon-jean-samuel.begue
** File description:
** Delete the entire hashtable
*/
#include "hashtable.h"
#include <stddef.h>
#include <stdlib.h>

void delete_elem(data_list_t *current, data_list_t *last)
{
    while (current != NULL) {
        last = current;
        current = current->next;
        if (last->value != NULL) {
            free(last->value);
        }
        free(last);
    }
}

void delete_hashtable(hashtable_t *ht)
{
    data_list_t **data = NULL;
    data_list_t *current = NULL;
    data_list_t *last = NULL;

    if (!ht)
        return;
    data = ht->data_list;
    if (!data)
        return;
    for (int i = 0; i < ht->len; i++) {
        current = data[i];
        delete_elem(current, last);
    }
    free(data);
    free(ht);
}
