#include<stdio.h>
#include<stdlib.h>
struct LinkedList{
    int data;
    struct LinkedList *next;
 };

typedef struct LinkedList *node; //Define node as pointer of data type struct LinkedList

node createNode(){
    node temp; // declare a node
    temp = (node)malloc(sizeof(struct LinkedList)); // allocate memory using malloc()
    temp->next = NULL;// make next point to NULL
    return temp;//return the new node
}

node addNode(node head, int value){
    node temp,p;// declare two nodes temp and p
    temp = createNode();//createNode will return a new node with data = value and next pointing to NULL.
    temp->data = value; // add element's value to data part of node
    if(head == NULL){
        head = temp;     //when linked list is empty
    }
    else{
        p  = head;//assign head to p 
        while(p->next != NULL){
            p = p->next;//traverse the list until p is the last node.The last node always points to NULL.
        }
        p->next = temp;//Point the previous last node to the new node created.
    }
    return head;
}
void printfNode(node head){
node p;
p=head;
while(p->next!=NULL){
printf("%d",p->data);
p=p->next;
printf("%d",p->data);
}
}
int main(){
int n,t;
t=4;
 node head = NULL;
while(t){
printf("Enter 1 to add value and 2 to display list and end\n");
scanf("%d",&t);
if(t==1){
scanf("%d",&n);
head=addNode(head,n);
}
else printfNode(head);
}

}
