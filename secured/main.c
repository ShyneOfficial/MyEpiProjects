/*
** EPITECH PROJECT, 2025
** B-CPE-110-RUN-1-1-secured-brandon-jean-samuel.begue
** File description:
** main
*/
#include "hashtable.h"
#include <stdio.h>

int main(void)
{
    hashtable_t *ht = new_hashtable(&hash, 0);

    ht_insert(ht, "rayan", NULL);
    ht_insert(ht, "rayan", "tata");
    ht_insert(ht, "rayan", "tutu");
    ht_dump(ht);
    delete_hashtable(ht);
    return 0;
}
