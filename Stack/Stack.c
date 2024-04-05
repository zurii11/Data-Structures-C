#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"

struct Stack* create_empty_stack()
{
  struct Stack *newStack = (struct Stack*)malloc(sizeof(struct Stack));
  newStack->top = -1;
}

void push(struct Stack *stack, int item)
{
  if(is_full(stack)) {
    printf("stack if full\n");
  } else {
    stack->top++;
    stack->items[stack->top] = item;
  }
}

void pop(struct Stack *stack)
{
  if(is_empty(stack)) {
    printf("stack is empty\n");
  } else {
    stack->top--;
  }
}

int is_full(struct Stack *stack)
{
  if(stack->top == MAX - 1) {
    return 1;
  } else {
    return 0;
  }
}

int is_empty(struct Stack *stack)
{
  if(stack->top == -1) {
    return 1;
  } else {
    return 0;
  }
}

void print_stack(struct Stack *stack)
{
  if(is_empty(stack)) {
    printf("stack is empty\n");
  } else {
    for(int i = 0; i < stack->top+1; i++) {
      printf("Item: %d is at stack position %d\n", stack->items[i]);
    }
  }
}
