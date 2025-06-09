#include <stdio.h>
#include "HashTable.h"

HashTable* ht_create(size_t size)
{
	HashTable* ht = malloc(sizeof(HashTable));
	Entry** ht_elements = calloc(size, sizeof(Entry));
	size_t* ht_size = malloc(sizeof(size_t));

	ht->elements = ht_elements;
	ht->size = ht_size;
	ht->hf = hash;

	return ht;
}

uint64_t hash(void* key, size_t keylen);
Entry* ht_lookup(HashTable* ht, void* key, size_t keylen);
uint8_t ht_insert(HashTable* ht, void* key, size_t keylen, void* value, size_t valuelen);
uint8_t ht_remove(HashTable* ht, void* key, size_t keylen);
uint8_t ht_resize(HashTable* ht, size_t new_size);
uint8_t ht_free(HashTable* ht);


