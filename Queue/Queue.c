#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

struct Queue* create_queue() {
  struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));

  q->front = -1;
  q->rear = -1;
} 

void enqueue(struct Queue *q, int item)
{
  if(is_full(q)) {
    printf("queue is full\n");
  } else {
    if(q->front == -1)
      q->front = 0;

    q->rear++;
    q->items[q->rear] = item;
  }
}

int dequeue(struct Queue *q)
{
  if(is_empty(q)) {
    printf("queue is empty");
  } else {
    int dqedItem = q->items[q->front];
    printf("Dequeued: %d\n", dqedItem);
    q->front++;
    if(q->front > q->rear)
      q->front = -1;
      q->rear = -1;

    printf("Front ind: %d\n", q->front);
    return dqedItem;
  }
}

int is_full(struct Queue *q)
{
  if(q->rear == MAX - 1) {
    printf("queue is full\n");
    return 1;
  }
  return 0;
}

int is_empty(struct Queue *q)
{
  if(q->front == -1) {
    printf("queue is empty\n");
    return 1;
  } 
  return 0;
}

int peek(struct Queue *q)
{
  if(is_empty(q))
    return -1;
  printf("front ind: %d\n", q->front);
  printf("front : %d\n", q->items[q->front]);
  return q->items[q->front];
}
