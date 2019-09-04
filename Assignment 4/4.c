#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
int insert()
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    printf("enter data :");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else{
        temp->next=head;
        head=temp;
    }
}
void Display()
{
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void reverse()
{
    Display();
    struct node *temp,*temp2,*x;
    temp2=NULL;
    temp=head;
    while(temp!=NULL)
    {
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
    head=temp2;
    printf("\nreversed number is :\n");
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}

int main()
{
    printf("**************MENU*******************\n");
    printf("1->INSERT\n2->REVERSE");
    int n;
    while(1){
    printf("\nenter choice :");
    scanf("%d",&n);
    if(n==1)
        insert();
    else if(n==2)
        reverse();
        else
            break;}
}
