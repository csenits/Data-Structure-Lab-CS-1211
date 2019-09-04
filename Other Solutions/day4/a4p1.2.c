#include<stdio.h>
#include<stdlib.h>

struct Node {
    long long int data;
    struct Node *next;
};

struct Node *reverse(struct Node * head)
{
    struct Node *current = head;
    struct Node *p = NULL;
    struct Node *n = NULL;
 
        while (current != NULL)
        {
            n = current->next;
            current->next = p;
            p = current;
            current = n;
        }
        head = p;
        return head;
}

struct Node* addList(struct Node * head1 ,struct Node *head2)
{
    int carry=0;
    struct Node * t = head1;
    struct Node * u = head2;
    struct Node * g = (struct Node*)malloc((sizeof(struct Node)));
    struct Node *h = g;
    
    while(1)
    {
        int p;
        if(t==NULL && u==NULL)
        {
            break;
        }
        if(t==NULL)
        {
            p = u->data + carry;
        }
        else if(u==NULL)
        {
            p = t->data + carry;
        }
        else
        {
            p = t->data + u->data + carry;
        }
        struct Node *s = (struct Node*)malloc((sizeof(struct Node)));
        if(p>=10)
        {
            carry=1;
            s->data=p%10;
        }
        else
        {
            carry=0;
            s->data=p;
        }
        g->next=s;
        g=s;
        if(t!=NULL)
        {
            t=t->next;
        }   
        if(u!=NULL)
        {
            u=u->next;
        }
    }
    if(carry==1)
    {
        struct Node *s = (struct Node*)malloc((sizeof(struct Node)));
        s->data=1;
        g->next=s;
        g=s;
    }
    g->next =NULL;
    g=h;
    return (g->next);
}


int main()
{
    long long x;
    printf("Enter the number to be stored in node:\n");
    scanf("%lli",&x);
    struct Node * p = (struct Node*)malloc((sizeof(struct Node)));
    p->data=x%10;
    x=x/10;
    struct Node *start1 = p;
    while(x!=0)
    {
        struct Node * n1 = (struct Node*)malloc((sizeof(struct Node)));
        n1->data = x%10;
        x=x/10;
        p->next =n1;
        p=n1;
    }
    p->next = NULL;
    p=start1;
    
    
    
    long long y;
    printf("Enter the second number to be stored in node:\n");
    scanf("%lli",&y);
    struct Node * q = (struct Node*)malloc((sizeof(struct Node)));
    q->data=y%10;
    y=y/10;
    struct Node * start2 = q;
    while(y!=0)
    {
        struct Node * n2 = (struct Node*)malloc((sizeof(struct Node)));
        n2->data = y%10;
        y=y/10;
        q->next = n2;
        q=n2;
    }
    q->next=NULL;
    q = start2;
    struct Node * add = addList(start1, start2);
    
    struct Node *sum = reverse(add);
    printf("The sum of two integers is:\n");
    while(sum!=NULL)
    {
        printf("%d",sum->data);
        sum=sum->next;
    }
    free(p);
    free(q);
    free(add);
}