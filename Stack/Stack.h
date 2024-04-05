#ifndef Stack_h
#define Stack_h
#define MAX 10

struct Stack {
  int items[MAX];
  int top;
};

struct Stack* create_empty_stack();
int is_full(struct Stack *stack);
int is_empty(struct Stack *stack);
void push(struct Stack *stack, int item);
void pop(struct Stack *stack);
void print_stack(struct Stack *stack);

#endif
