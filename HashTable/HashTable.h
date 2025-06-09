#ifndef HASH_TABLE_IMP
#define HASH_TABLE_IMP

#include <stdlib.h>
#include <stdint.h>

typedef void (*hash_function)(const char*, size_t);

typedef struct Entry
{
	void* key;
	size_t keylen;
	void* value;
	size_t valuelen;
	struct Entry* next;
} Entry;

typedef struct HashTable
{
	uint32_t size;
	hash_function* hf;
	Entry** elements;
} HashTable;

HashTable* ht_create(size_t size);
uint64_t hash(void* key, size_t keylen);
Entry* ht_lookup(HashTable* ht, void* key, size_t keylen);
uint8_t ht_insert(HashTable* ht, void* key, size_t keylen, void* value, size_t valuelen);
uint8_t ht_remove(HashTable* ht, void* key, size_t keylen);
uint8_t ht_resize(HashTable* ht, size_t new_size);
uint8_t ht_free(HashTable* ht);

#endif
