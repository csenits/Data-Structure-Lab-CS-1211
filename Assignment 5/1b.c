#include <stdio.h>

struct stack {
    int data;
    struct stack *next;
    struct stack *prev;

};
typedef struct stack *S;
void push(S *stack)
{
    int e;
    S temp;
    temp=malloc(sizeof(struct stack));
    if(!temp){
        printf("Can't allocate memory\n");
        return;
    }
    printf("Enter element to push\n");
    scanf("%d", &e);

    temp->data=e;
    if(*stack == NULL){
        temp->next = temp->prev = NULL;
        *stack=temp;
    } else {
        temp->next = *stack;
        (*stack)->prev = temp;
        temp->prev = NULL;
        *stack=temp;
    }

}

void display(S s){
    S temp;
    temp=s;
    printf("Elements are ...\n");
    while(temp) {
        printf("%d\n", temp->data);
        temp=temp->next;
    }

}

void pop(S *stack)
{
    S del;
    if(*stack == NULL){
        printf("Stack is Empty ..\n");
        return;
    }
    printf("Deleted .. %d\n", (*stack)->data);
    del = *stack;
    *stack = (*stack)->next;
    free(del);
    if((*stack)){
        (*stack)->prev = NULL;
    }

}
int main()
{

    int ch;
    S s=NULL;
    while(1){
        system("clear");
        printf("1 Push\n2 Pop\n3 Display\n4 exit\n");
        printf("Enter you choice\n");
        scanf("%d", &ch);

        switch(ch) {
            case 1: push(&s); break;
            case 2: pop(&s); break;
            case 3: display(s); break;
            case 4: exit(0);
            default: printf("invalid\n");
        }
        getchar();
        getchar();
    }
    return 0;
}