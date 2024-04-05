#include <stdio.h>
#include "Queue.h"

int main()
{
  struct Queue *q = create_queue();

  enqueue(q, 12);
  enqueue(q, 13);
  enqueue(q, 14);

  printf("Front: %d\n", peek(q));


  dequeue(q);

  printf("Front: %d\n", peek(q));
}
