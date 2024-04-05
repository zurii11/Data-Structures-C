#ifndef LinkedList_h
#define LinkedList_h

struct Node {
  int data;
  struct Node* next;
};

struct LinkedList {
  struct Node* head;
  int length;
};

struct Node* create_node(int data);
void destroy_node(struct Node* node);
struct Node* iterate(struct LinkedList* linked_list, int index);
void insert_node(struct LinkedList* linked_list, int data, int index);
void remove_node(struct LinkedList* linked_list, int index);
int retrieve_node(struct LinkedList* linked_list, int index);
struct LinkedList* create_linked_list();
void destroy_linked_list(struct LinkedList* linked_list);

#endif // !DEBUG
