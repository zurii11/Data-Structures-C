#ifndef Queue_h
#define Queue_h
#define MAX 10

struct Queue {
  int items[MAX];
  int front;
  int rear;
};

struct Queue* create_queue();
void enqueue(struct Queue *q, int item);
int dequeue(struct Queue *q);
int is_empty(struct Queue *q);
int is_full(struct Queue *q);
int peek(struct Queue *q);

#endif
