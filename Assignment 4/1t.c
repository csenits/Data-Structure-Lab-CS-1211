#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char ch;
    struct node *next;
};
void push(struct node **head,char c[])
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    int i=strlen(c);
    while(i>=0)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->ch=c[i];
        temp->next=NULL;
        if(*head==NULL)
            *head=temp;
        else{
            temp->next=*head;
            *head=temp;
        }
        i--;
    }
}
int convert(struct node **head)
{
    int num=0,x;
    struct node *temp=*head;
    while(temp->next!=NULL)
    {
        x=(temp->ch);

        num=num*10+(x-48);
        temp=temp->next;
    }
    return num;
}
void add(int a,int b)
{
    printf("\ntheir sum is :%d",a+b);
}
void multiply(int a,int b)
{
    printf("\ntheir multiplication is: %d\n",a*b);
}
int main()
{
    struct node *head=NULL,*head1=NULL;
    char m[10],n[10];
    printf("enter 2 integers :");
    scanf("%s",m);
    scanf("%s",n);
    push(&head,m);
    push(&head1,n);
    int a,b;
    a=convert(&head);
    b=convert(&head1);
   add(a,b);
   multiply(a,b);
}

