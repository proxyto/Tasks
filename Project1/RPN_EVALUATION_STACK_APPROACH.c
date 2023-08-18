#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

// Define a stack structure
struct Stack 
{
 int data[STACK_SIZE];
 int top;
};

// Function to initialize the stack
void init(struct Stack* stack) 
{
 stack->top = -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) 
{
 if (stack->top < STACK_SIZE - 1) 
 {
  stack->top++;
  stack->data[stack->top] = value;
 }
}

// Function to pop an element from the stack
int pop(struct Stack* stack) 
{
 if(stack->top >= 0) 
 {
  int value = stack->data[stack->top];
  stack->top--;
  return value;
 }
 return -1; // Error value indicating an empty stack
}

// Function to evaluate an expression in Reverse Polish Notation
int RPN(char* expression[], int size) 
{
 struct Stack stack;
 init(&stack);

 for(int i = 0; i < size; i++) 
 {
  char token = expression[i][0];
  if(token >= '0' && token <= '9') 
  {
   int value = atoi(expression[i]);
   push(&stack, value);
  }
  else 
  if(token == '+' || token == '-' || token == '*' || token == '/') 
  {
   int b = pop(&stack);
   int a = pop(&stack);
   int result;
   switch (token) 
   {
    case '+': 
     result = a + b; 
     break;
    case '-': 
     result = a - b; 
     break;
    case '*': 
     result = a * b; 
     break;
    case '/': 
     result = a / b; 
     break;
   }
   push(&stack, result);
  }
 }

 return pop(&stack);
}

int main() 
{
 char* expression[] = { "15", "7", "1", "1", "+", "-", "/", "3", "*", "2", "1", "1", "+", "+", "-" };
 int size = sizeof(expression) / sizeof(expression[0]);
 int result = RPN(expression, size);
 printf("Result: %d\n", result);

 return 0;
}
