#include "stack.h"
#define STACK_SIZE 3

// Backing store
int StackStore[STACK_SIZE];

// Pointer to stack elements for adding and retrieving
int* ptr;

// LIFO Stack is Empty if ptr==0;
// LIFO Stack is Full if putPtr+1 > Address of last element in the stack;

// Initialize internals of the stack
void Init(void)
{
    ptr = 0;
    for(int i=0; i<STACK_SIZE; i++)
    {
        StackStore[i] = '\0';
    }
}

int IsEmpty()
{
    if (ptr == 0)
      return 1;
    return 0;
}

int IsFull()
{
    if (ptr == &StackStore[STACK_SIZE - 1])
      return 1;
    return 0;
}

// Add data to stack
// If stack is full return error
// Otherwise return success
int Push(int data)
{
    if (IsFull())
      return -1;
    
    if (IsEmpty())
      ptr = &StackStore[0];
    else
      ptr++;
    
    *ptr = data;
    
    return 0;
}

// Pop data from stack
// If stack is empty return error
// Otherwise return success
int Pop(int* data)
{   
    if (IsEmpty())
      return -1;
    
    *data = *ptr;
    
    *ptr = '\0';
    if (ptr == &StackStore[0])
      ptr = 0;
    else
      ptr--;
    
    return 0;
}
