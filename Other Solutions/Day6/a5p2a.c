#include <stdio.h>

#define MAX 50





int queue_array[MAX];
int rear = - 1;
int front = - 1;



void insert()
{
    int add_item;
    if (rear == MAX - 1)
        printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
            
            front = 0;
        printf("Insert the item of queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
} 
int delete()
{
    if (front == - 1 || front > rear)
        {
        printf("Queue Underflow or empty \n");
        return 0;
        }
    else
        {
        printf("last deleted element is: %d\n", queue_array[front]);
        front = front + 1;
        return 1;
        }

} 


void empty()
{

    while(delete()){}
    printf("Queue Empty operation successful");
}



void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
} 



int main()
{
    int choice;
    while (1)
    {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Empty queue \n");
        printf("5.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                empty();
                break;
            case 5:
                exit(1);
            default:
                printf("Wrong choice \n");
        } 
    }
} 