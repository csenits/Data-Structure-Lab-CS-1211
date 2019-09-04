#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void push(struct node **head)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nenter data :");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(*head==NULL)
        *head=temp;
    else{
        temp->next=*head;
        *head=temp;
    }
}
void Display(struct node **head)
{
    struct node *temp=*head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void interchange(struct node **head)
{
    struct node *max,*min,*temp;
    max=*head;
    min=(*head);
    temp=*head;
    while(temp!=NULL)
    {
        if(max->data<temp->data)
        {
            max=temp;
        }
        temp=temp->next;
    }
    temp=*head;
    while(temp!=NULL)
    {
        if(min->data>temp->data)
        {
            min=temp;
        }
        temp=temp->next;
    }
    min->data=min->data+max->data;
    max->data=min->data-max->data;
    min->data=min->data-max->data;
}
struct node *search(struct node **head,int x)
{
    struct node *temp=*head;
    int flag=0;
    while(temp!=NULL)
    {
        if(temp->data==x)
        {
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(flag==1)
        return temp;
    else
        return NULL;
}
struct node *srchinsrt(struct node **head,int x)
{
    struct node *temp=*head,*y;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    y=(struct node*)malloc(sizeof(struct node));
    y->data=x;
    temp->next=y;
    y->next=NULL;
    temp=y;
    return y;

}
int main()
{
    struct node *head=NULL,*s,*y;
    int n,z;
    printf("Choose from the following option.\n");
    printf("1->Add data\n2->Display linked list\n3->Swap\n4->Search");
    while(1){
        printf("\nEnter your choice :");
        scanf("%d",&n);
        if(n==1)
            push(&head);
        else if(n==2)
            Display(&head);
        else if(n==3)
            interchange(&head);
        else if(n==4)
        {
            printf("Enter the element to search :");
            scanf("%d",&z);
            s=search(&head,z);
            if(s==NULL)
            {
                y= srchinsrt(&head,z);
                printf("\nElement is %d added!",y->data);

            }
            else{
                printf("\nElement found %d",s->data);}
        }

        else
            break;
    }

}