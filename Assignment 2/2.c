#include <stdio.h>
#include <stdlib.h>
#define size_of_stack 100

struct stack {
    int top;
    int *items[size_of_stack];
    int size[size_of_stack];
};

int empty(struct stack *ps)
{
    return (ps->top==-1);

}

int* pop(struct stack *ps)
{
    if(empty(ps)){
        printf("stack underflow");
    }
    return(ps->items[ps->top--]);
}

int* push(struct stack *ps, int *x)
{
    ps->items[++(ps->top)] = x;
    return 0;
}


int stacktop(struct stack *ps, int *topaddr)
{
    if(empty(ps)){
        printf("\nstack overflow");
    }
    else{
        topaddr  = ps->items[ps->top];
    }
    return 0;
}

int main(){

    int x, i, put, option, size;
    int *addr;
    int *s_top;
    struct stack s;
    s.top = -1;


    while(option!=4){
        printf("\nEnter the following options, \n1. Pop\n2. Push\n3. Stack Top\n4. Exit\nOption:\t");
        scanf("%d",&option);
        if(option == 1){
            pop(&s);
        }
        else if(option == 2){
            printf("\nEnter the number of elements to be pushed:\t");
            scanf("%d",&x);


            addr = (int *)malloc(x * sizeof(int));


            for (i = 0; i < x; i++) {
                printf("\nEnter the numbers to be pushed in this section\n");
                scanf("%d", &addr[i]);
            }

            push(&s, &addr[0]);
            s.size[s.top] = x;


        }

        else if(option == 3){




            s_top = s.items[s.top];
            printf("\nThe top elements are \n");

            for (i = 0; i < s.size[s.top]; i++) {
                printf("\t%d\t",*s_top);
                s_top = s_top + 1;

            }


        }
    }

}
