#include <stdio.h>
#include "LinkedList.h"

int main()
{
  struct LinkedList* linked_list = create_linked_list();

  for(int i = 0; i < 10; i++) {
    insert_node(linked_list, i*10, i);
  }

  remove_node(linked_list, 0);
  remove_node(linked_list, 3);

  for(int i = 0; i < linked_list->length; i++) {
    int data = retrieve_node(linked_list, i);
    printf("data %d at index %d\n", data, i);
  }

  destroy_linked_list(linked_list);
}
