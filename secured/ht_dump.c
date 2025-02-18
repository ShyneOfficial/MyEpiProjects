/*
** EPITECH PROJECT, 2025
** B-CPE-110-RUN-1-1-secured-brandon-jean-samuel.begue
** File description:
** Display the entire hashtable
*/
#include "hashtable.h"
#include <stddef.h>

void revsort_list(data_list_t **begin)
{
    data_list_t *current = *begin;
    data_list_t *previous = NULL;
    data_list_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *begin = previous;
}

void display_elem(data_list_t *data)
{
    data_list_t *ref = data;

    revsort_list(&data);
    while (data != NULL) {
        if (data->value)
            my_printf("> %d - %s\n", data->key, data->value);
        else
            my_printf("> %d - \n", data->key);
        data = data->next;
    }
    data = ref;
}

void ht_dump(hashtable_t *ht)
{
    data_list_t *data = NULL;

    if (!ht)
        return;
    for (int i = 0; i < ht->len; i++) {
        my_printf("[%d]:\n", i);
        data = ht->data_list[i];
        display_elem(data);
    }
}
