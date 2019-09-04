
#include <stdio.h>
#include <stdlib.h>
struct node{
	int num;
	struct node *ptr;};
void main(){
  
   typedef struct node NODE;
   NODE *head, *last, *temp=0;
   int count = 0;
   int choice = 1;
   head = 0;
   while(choice){
		temp =(NODE*) malloc(sizeof(NODE));
		printf("Enter the data item\n");
		scanf("%d", &temp-> num);
		if(head != 0){
			last->ptr = temp;
			last = temp;}
		else{last = head = temp;}
 //fflush(stdin);
printf("Do you want to continue(Type 0 or 1)?\n");
scanf("%d", &choice);}
 
temp->ptr = 0;
temp = head;

printf("\nstatus of the linked list is\n");
while(temp!=0){
	printf("%d ", temp->num);
	count++;temp = temp -> ptr;}
printf("NULL\n");
printf("No. of nodes in the list = %d\n", count);
}// Main closed