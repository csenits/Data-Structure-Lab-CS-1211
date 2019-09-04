#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// A structure to represent a stack
struct Stack
{
    int top;
    int size;
    int* arr;
};
 
 
struct Stack* stackSize(int size)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (int*) malloc(stack->size * sizeof(int));
    return stack;
}
 
// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{   return stack->top == stack->size - 1;
}
 
// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{   return stack->top == -1; 
}
 
// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->arr[++stack->top] = item;
    printf("%d inserted to stack\n", item);
}
 
// Function to remove an item from stack.  It decreases top by 1
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->arr[stack->top--];
}
 
int main()
{ int i,t,n,element;
    struct Stack* s = stackSize(100);
 
 
	t=0;
 while(t==0){
 	 printf("Enter 1 to insert an element to stack or  2 to remove an element from stack or 3 to print stack \n");
 	  scanf("%d",&n);
 	 if(n==1){
 	 	printf("Enter the element to insert in the stack\n");
 	 	 scanf("%d",&element);
    push(s,element);
    
   }
   if(n==2){
	
    printf("%d popped from stack\n", pop(s));
}
if(n==3)
for(i=0;i<s->top+1;i++){
   printf("%d ",s->arr[i]);
}
 
printf("press 0 to continue\n");
    scanf("%d",&t);
 
}
 
    return 0;
}

