#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
 
struct node
{
    int num;
    struct node *next;
};
 
typedef struct Node node;


int feednumber(struct node **);
void release(struct node **);
void display(struct node *);
// Multiply contents of two linked lists
long multiplyTwoLists (struct node* first, struct node* second)
{
    int num1 = 0, num2 = 0;
     
    // Generate numbers from linked lists
    while (first || second)
    {
        if (first)
        {
            num1 = num1*10 + first->num;
            first = first->next;
        }
        if (second)
        {
            num2 = num2*10 + second->num;
            second = second->next;
        }
    }
 
    // Return multiplication of 
    // two numbers
    return num1*num2;
}

node* addSameSize(Node* head1, Node* head2, int* carry)
{
    // Since the function assumes linked lists are of same size,
    // check any of the two head pointers
    if (head1 == NULL)
        return NULL;
 
    int sum;
 
    // Allocate memory for sum node of current two nodes
    Node* result = (Node *)malloc(sizeof(Node));
 
    // Recursively add remaining nodes and get the carry
    result->next = addSameSize(head1->next, head2->next, carry);
 
    // add digits of current nodes and propagated carry
    sum = head1->num + head2->num + *carry;
    *carry = sum / 10;
    sum = sum % 10;
 
    // Assigne the sum to current node of resultant list
    result->num = sum;
 
    return result;
}
 
int main()
{
    struct node *p1 = NULL;
    int p1count = 0, q1count = 0;
    struct node *p2 = NULL;
    int p2count = 0, q2count = 0;
 
    printf("Enter number of any length\n");
    p1count = feednumber(&p1);
    printf("Enter the second number of any length\n");
    p2count = feednumber(&p2);
    printf("Number of integers entered are: %d\n", p2count);
    printf("Result is: ");
    printf("%ld", multiplyTwoLists(p1, p2));
    return 0;
}
 
/*Function to create nodes of numbers*/
int feednumber(struct node **head)
{
    char ch, dig;
    int count = 0;
    struct node *temp, *rear = NULL;
 
    ch = getchar();
    while (ch != '\n')
    {
        dig = atoi(&ch);
        temp = (struct node *)malloc(sizeof(struct node));
        temp->num = dig;
        temp->next = NULL;
        count++;
        if ((*head) == NULL)
        {
            *head = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = rear->next;
        }
        ch = getchar();
    }
 
    return count;
}
 
/*Function to display the list of numbers*/
void display (struct node *head)
{
    while (head != NULL)
    {
        printf("%d", head->num);
        head = head->next;
    }
    printf("\n");
}
 
/*Function to free the allocated list of numbers*/
void release (struct node **head)
{
    struct node *temp = *head;
 
    while ((*head) != NULL)
    {
        (*head) = (*head)->next;
        free(temp);
        temp = *head;
    }
}
