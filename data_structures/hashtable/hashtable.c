#include<stdlib.h>
#include<stdbool.h>
#include "hashtable.h"

typedef struct{
    int key;
    void* value; 
    bool occupied;
} HashEntry;

struct HashTable{
    HashEntry* buckets;
    int capacity;
};

static int hash(int key, int capacity){
    return abs(key) % capacity;
}

HashTable* ht_create(int capacity){
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->capacity = capacity * 2; //Pad size to redice collisions
    ht->buckets = (HashEntry*)calloc(ht->capacity, sizeof(HashEntry));
    return ht;
}

void ht_insert(HashTable* ht, int key, void* value){
    int h = hash(key, ht->capacity);
    while(ht->buckets[h].occupied){
        if(ht->buckets[h].key == key){
            ht->buckets[h].value = value;
            return;
        }
        h = (h + 1) % ht->capacity;
    }
    ht->buckets[h].key = key;
    ht->buckets[h].value = value;
    ht->buckets[h].occupied = true;
}

void* ht_search(HashTable* ht, int key){
    int h = hash(key, ht->capacity);
    while(ht->buckets[h].key == key){
        if(ht->buckets[h].key == key){
            return ht->buckets[h].value;
        }
        h = (h + 1) % ht->capacity;
    }
    return NULL;
}

void ht_free(HashTable* ht){
    free(ht->buckets);
    free(ht);
}
