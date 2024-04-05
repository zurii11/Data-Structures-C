#include "Stack.h"

int main() {
  struct Stack *stack = create_empty_stack(); 

  print_stack(stack);

  push(stack, 12);
  push(stack, 83);
  push(stack, 163);
  push(stack, 2);
  push(stack, 55);

  print_stack(stack);

  pop(stack);
  pop(stack);

  print_stack(stack);
}
