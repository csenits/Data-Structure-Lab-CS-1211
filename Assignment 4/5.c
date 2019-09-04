#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int insert(struct node **head)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    printf("enter data :");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(*head==NULL)
    {
        *head=temp;
    }
    else{
        temp->next=*head;
        *head=temp;
    }
}
void Display(struct node **head)
{
    struct node *temp=*head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void reverse(struct node **head)
{

    struct node *temp,*temp2,*x=NULL;
    temp2=NULL;
    temp=*head;
    while(temp!=NULL)
    {
        x=NULL;
        x=(struct node*)malloc(sizeof(struct node));
        x->data=temp->data;
        x->next=NULL;
        if(temp2==NULL)
            temp2=x;
        else{
            x->next=temp2;
            temp2=x;
        }
        temp=temp->next;
    }
    *head=temp2;

    while(*head!=NULL){
        printf("%d ",(*head)->data);
        (*head)=(*head)->next;
    }
}
void merge(struct node **head,struct node **head2)
{
    struct node *x,*head3=NULL;
    while(*head!=NULL&&*head2!=NULL)
    {
        x=(struct node*)malloc(sizeof(struct node));
        if((*head)->data<(*head2)->data)
        {
            x->data=(*head)->data;
            x->next=NULL;
            (*head)=(*head)->next;
        }
        else
        {
            x->data=(*head2)->data;
            x->next=NULL;
            (*head2)=(*head2)->next;
        }
        if(head3==NULL)
        {
            head3=x;
        }
        else
        {
            x->next=head3;
            head3=x;
        }

    }
    while(*head!=NULL)
    {
        x=(struct node*)malloc(sizeof(struct node));
            x->data=(*head)->data;
            x->next=NULL;
            (*head)=(*head)->next;

            if(head3==NULL)
        {
            head3=x;
        }
        else
        {
            x->next=head3;
            head3=x;
        }
    }
    while(*head2!=NULL)
    {
            x->data=(*head2)->data;
            x->next=NULL;
            (*head2)=(*head2)->next;

        if(head3==NULL)
        {
            head3=x;
        }
        else
        {
            x->next=head3;
            head3=x;
        }
    }
    reverse(&head3);
}
int main()
{
    struct node *head=NULL;
struct node *head2=NULL;
struct node *head3=NULL;
printf("****************MENU*******************");
printf("\ninsert in :-\n1->list1 \n2->list 2\n 3->merge");
int n;
while(1){
printf("\nenter choice :");

scanf("%d",&n);
    if(n==1)
    insert(&head);
    else if(n==2)
    insert(&head2);
    else if(n==3)
    merge(&head,&head2);
    else
        break;
}
}

