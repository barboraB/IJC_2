#ifndef HTAB_H
#define HTAB_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * A structure representing an item in the hash table.
 */
struct htab_listitem{
	const char* key; /**< word */
	unsigned long data; /**< Number of appearances of the word. */
	struct htab_listitem* next; /**< Pointer to the next item of the list. */
};
 /**
  * A structure representing a hash table.
  *
  */
struct htab_t{
	size_t arr_size; /**< Size of an array of linked list */
	size_t n; /**< Number of all items it the table */
	struct htab_listitem * array[]; /**<Array of linked lists of items. */
};

/**
 * Function will allocate a new hash table and set the values of it accordingly. 
 * @param size Size of an array of linked lists.
 * @return Returns pointer to the new hash table.
 */
struct htab_t * htab_init(size_t size);

/**
 * Function will allocate new table of the size newsize and move the table t2 onto the new one.
 * It will leave the old table completely clear, but still allocated.
 * @param newsize Size of the new table.
 * @param t2 Table to be moved.
 */
struct htab_t * htab_move(unsigned long newsize, struct htab_t* t2);

/**
 * Function will return the number of all items in hash table.
 * @param t Hash table.
 * @return Number of all items in hash table. 
 */
size_t htab_size(struct htab_t* t);

/**
 * Function will return size of an array.
 * @param t Hash table. 
 * @return Size of allocated array.
 */
size_t htab_bucket_count(struct htab_t* t);

/**
 * Function will lookup an item in hash table. If the item does not exist yet, it
 * will make a new item and add it to the end of the linked list.
 * @param t Hash table.
 * @param key Find or add item with this key.
 * @return Returns pointer to the item which was found or pointer to the new item.
 * @see htab_find
 */
struct htab_listitem * htab_lookup_add(struct htab_t* t, const char* key);

/**
 * Function will find and item in the hash table according to its key value.
 * @param t Hash table.
 * @param key Item with a key to be found.
 * @return Returns NULL if the item was not found, otherwise pointer to the found item.
 */
struct htab_listitem * htab_find(struct htab_t *t, const char *key);

/**
 * Function will remove item from the linked list in hash table
 * @param t Hash table.
 * @param key Delete item with this key.
 * @return Returns false if the item does not exist, otherwise true.
 */
bool htab_remove(struct htab_t* t, const char* key);

/**
 * Function will clear the table, leaving the bare structure and allocated empty array.
 * @param t Hash table.
 * @see htab_remove
 */
void htab_clear(struct htab_t* t);

/**
 * Function will free an empty hash table.
 * @param t Hash table. 
 */
void htab_free(struct htab_t* t);

/**
 * Function will calculate a hash out of string.
 * @param str String to be hashed.
 * @return Hash. 
 */
unsigned int hash_function(const char *str);

/**
 * Function will print one item of a linked list. 
 * @param item Item of the list.
 * @return Returns 1 if something went wrong, otherwise 0.
 */
int htab_print_item(const char* key, struct htab_listitem* item);

/**
 * Function will call for every item in hash table a particular function.
 * @param t Hash table.
 * @param func Function to be called for an item.
 */
void htab_foreach(struct htab_t* t, int (*func)(const char* key, struct htab_listitem*));

#endif