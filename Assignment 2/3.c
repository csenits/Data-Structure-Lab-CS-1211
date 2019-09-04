#include <stdio.h>
#include <stdlib.h>
#define size_of_stack 100

struct stack{
    int top;
    int items[size_of_stack];
};

int empty(struct stack *ps)
{
    return (ps->top==-1);

}

int pop(struct stack *ps)
{
    if(empty(ps)){
        printf("stack underflow");
    }
    return(ps->items[ps->top--]);
}

int popandtest(struct stack *ps, int *px, int *pund)
{
    if(empty(ps)){
        *pund = 1;
    }
    *pund = 0;
    *px = ps -> items[ps->top--];
    return 0;
}


int push(struct stack *ps, int *x)
{
    if(ps->top == size_of_stack - 1){
        printf("stack overflow");
        exit(1);
    }
    else{
        ps->items[++(ps->top)] = *x;
    }
    return 0;
}



int stacktop(struct stack *ps)
{
    if(empty(ps)){
        printf("\nstack overflow");
        return 0;
    }
    else{
        return(ps->items[ps->top]);
    }

}

int main(){
    struct stack s1, s2;
    s1.top=-1;
    s2.top=-1;
    int array_size, i, a, ind, popped_a, t, x;

    printf("\nEnter the number of elements of the array.\n");
    scanf("%d",&array_size);

    printf("\nEnter the elements of the array.\n");

    for (i = 0; i < array_size; i++) {
        scanf("%d",&a);
        push(&s1,&a);
    }

    printf("Enter the index of the element to be displayed");
    scanf("%d",&ind);


    for (i = 0; i < array_size - ind ; i++) {
        popped_a = stacktop(&s1);
        push(&s2, &popped_a);
        pop(&s1);
    }

    printf("%d",stacktop(&s2));



}
