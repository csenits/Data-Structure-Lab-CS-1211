#include<stdio.h>
 
int stack[100],choice,n,top,x,i;
void push(void);
void pop(void);
void display(void);
void stacktop(void);
void isfull(int);
void isempty();
int main()
{
    
    top=-1;
    printf("\n Enter the size of STACK[MAX=100]:");
    scanf("%d",&n);
    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.stacktop\n\t 5.isFull \n\t 6.isEmpty \n\t 7.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
	    case 4:
            {
                stacktop();
                break;
            }
	    case 5:
            {
                isfull(n);
                break;
            }
	    case 6:
            {
                isempty();
                break;
            }
            case 7:
            {
                printf("\n\t EXIT POINT ");
                break;
            }
            default:
            {
                printf ("\n\t Please Enter a Valid Choice");
            }
                 
        }
    }
    while(choice!=7);
    return 0;
}
void push()
{
    if(top>=n-1)
    {
        printf("\n\tSTACK is over flow");
         
    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\n\t Stack is under flow");
    }
    else
    {
        printf("\n\t The popped elements is %d",stack[top]);
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        printf("\n The elements in STACK \n");
        for(i=top; i>=0; i--)
            printf("\n%d",stack[i]);
        printf("\n Press Next Choice");
    }
    else
    {
        printf("\n The STACK is empty");
    }
    
}


void stacktop() {
   printf("\n\t Top most element is %d",stack[top]);
}


void isfull(int n) {
   if(top == n-1)
      printf("\n\t True ");
   else
      printf("\n\t False ");
}


void isempty() {
   if(top == -1)
      printf("\n\t True ");
   else
      printf("\n\t False ");
}
