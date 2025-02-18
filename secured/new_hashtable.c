/*
** EPITECH PROJECT, 2025
** B-CPE-110-RUN-1-1-secured-brandon-jean-samuel.begue
** File description:
** Create a new hashtable given a function pointer and a length
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "hashtable.h"

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *ht = malloc(sizeof(hashtable_t));

    if (!ht || len < 1)
        return NULL;
    ht->len = len;
    ht->hash_func = hash;
    ht->data_list = malloc(sizeof(data_list_t *) * (len + 1));
    if (!ht->data_list)
        return NULL;
    for (int i = 0; i < len; i++) {
        ht->data_list[i] = NULL;
    }
    ht->data_list[len] = NULL;
    return ht;
}
