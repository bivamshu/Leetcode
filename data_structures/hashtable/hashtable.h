#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>

// 1. Make sure this typedef exists
typedef struct HashTable HashTable;

// 2. Double-check the exact spelling of these function signatures
HashTable* ht_create(int capacity);
void ht_insert(HashTable* ht, int key, void* value);
void* ht_search(HashTable* ht, int key);
void ht_free(HashTable* ht);

#endif