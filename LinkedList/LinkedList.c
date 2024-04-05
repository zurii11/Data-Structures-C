#include <stdlib.h>
#include <stddef.h>
#include "LinkedList.h"

struct Node* create_node(int data)
{
  struct Node* new_node_address = (struct Node*)malloc(sizeof(struct Node));
  struct Node new_node;
  new_node.data = data;
  *new_node_address = new_node;

  return new_node_address;
}

void destroy_node(struct Node* node)
{
  free(node);
}

struct Node* iterate(struct LinkedList* linked_list, int index)
{
  if(index < 0 || index > linked_list->length)
    return NULL;

  struct Node* cursor = linked_list->head;

  for(int i = 0; i < index; i++) {
    cursor = cursor->next;
  }

  return cursor;
}

void insert_node(struct LinkedList* linked_list, int data, int index)
{
  struct Node* node_to_insert = create_node(data);

  if(index == 0) {
    node_to_insert->next = linked_list->head;
    linked_list->head = node_to_insert;
  } else {
    struct Node* prev_node = iterate(linked_list, index-1);
    node_to_insert->next = prev_node->next; 
    prev_node->next = node_to_insert;
  }

  linked_list->length += 1;
}

void remove_node(struct LinkedList* linked_list, int index)
{
  struct Node* node_to_destroy = iterate(linked_list, index);

  if(index == 0) {
    linked_list->head = node_to_destroy->next;
  } else {
    struct Node* prev_node = iterate(linked_list, index-1);
    prev_node->next = node_to_destroy->next;
  }

  destroy_node(node_to_destroy);
  linked_list->length -= 1;
}

int retrieve_node(struct LinkedList* linked_list, int index)
{
  struct Node* node_to_retrieve = iterate(linked_list, index);

  return node_to_retrieve->data;
}

struct LinkedList* create_linked_list()
{
  struct LinkedList* linked_list_address = (struct LinkedList*)malloc(sizeof(struct LinkedList));
  struct LinkedList new_linked_list;
  new_linked_list.head = NULL;
  new_linked_list.length = 0;
  *linked_list_address = new_linked_list;

  return linked_list_address;
}

void destroy_linked_list(struct LinkedList* linked_list)
{
  if(linked_list->length > 0) {
    for(int i = 0; i < linked_list->length; i++) {
      remove_node(linked_list, i);
    }
  }

  free(linked_list);
}
