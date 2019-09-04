#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
 
struct Node* newNode(int data)
{
    struct Node* new_node =
        (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
 
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = newNode(new_data);
 
    new_node->next = (*head_ref);
 
    (*head_ref) = new_node;
}
int reverse(struct Node** head_ref)
{
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next;
    int len = 0;
    while (current != NULL) {
        len++;
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
    return len;
}
struct Node* make_empty_list(int size)
{
    struct Node* head = NULL;
    while (size--)
        push(&head, 0);
    return head;
}
struct Node* multiplyTwoLists(struct Node* first,
                           struct Node* second)
{
    int m = reverse(&first), n = reverse(&second);

    struct Node* result = make_empty_list(m + n + 1);

    struct Node *second_ptr = second,
          *result_ptr1 = result, *result_ptr2, *first_ptr;

    while (second_ptr) {
 
        int carry = 0;
        
        result_ptr2 = result_ptr1;
 
        first_ptr = first;
 
        while (first_ptr) {

            int mul = first_ptr->data * second_ptr->data
                      + carry;
 
            result_ptr2->data += mul % 10;

            carry = mul / 10 + result_ptr2->data / 10;
            result_ptr2->data = result_ptr2->data % 10;
 
            first_ptr = first_ptr->next;
            result_ptr2 = result_ptr2->next;
        }

        if (carry > 0) {
            result_ptr2->data += carry;
        }
 
        result_ptr1 = result_ptr1->next;
        second_ptr = second_ptr->next;
    }
    
    reverse(&result);
    reverse(&first);
    reverse(&second);

    while (result->data == 0) {
        struct Node* temp = result;
        result = result->next;
        free(temp);
    }

    return result;
}

void printList(struct Node* Node)
{
    while (Node != NULL) {
        printf("%d", Node->data);
        if (Node->next)
            printf("->");
        Node = Node->next;
    }
    printf("\n");
}

int main(void)
{
    struct Node* first = NULL;
    struct Node* second = NULL;
 
    int x;
    int n;
    printf("Enter the number of elements of linked list1:\n");
    scanf("%d",&n);
    printf("Enter the elements of the linked list 1:\n");
    while(n--)
    {
    	scanf("%d",&x);
    	push(&first, x);
    }
    printf("First List is: ");
    printList(first);


    printf("Enter the number of elements of linked list2:\n");
    scanf("%d",&n);
    printf("Enter the elements of the linked list 2:\n");
    while(n--)
    {
    	scanf("%d",&x);
    	push(&second, x);
    }
    printf("Second List is: ");
    printList(second);	
    
    
    struct Node* result = multiplyTwoLists(first, second);
    printf("Resultant list is: ");
    printList(result);
 
    return 0;
}
