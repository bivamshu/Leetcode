#ifndef HASHTABLE_H //this is called a header guard. It ensures that the same code doesn't get read or copied into your program twice.
//#ifndef means "if not defined" HASH_TABLE is a uniqiue name

#define HASHTABLE_H
//#define means define it right now 

//How this works
//hashtable.h defines the struch HashTable
//If two files import the header and the main file compiles, the compiler will see the HashTable declared twice and throw an error. 
//When the compilers reads the header file for the first time, HASHTABLE_H doesn't exist yet. When the compiler reads the file for the second time, it remembers that the struct has already been defined so it skips directly to the #endif line. 

#include <stdbool.h>

typedef struct HashTable HashTable;

HashTable* htcreate(int captacity);
void ht_insert(HashTable* ht, int key, void* value);
void* ht_search(HashTable* ht, int key);
void ht_free(HashTable* ht);

#endif //end of the conditional block. 