#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int data;
    struct tree *l;
    struct tree *r;
};
void Insert(struct tree **root)
{
    struct tree *temp=malloc(sizeof(struct tree));
    printf("enter data :");
    scanf("%d",&temp->data);
    temp->l=temp->r=NULL;
    if(*root==NULL)
    {
        *root=temp;
        return;
    }
    else
    {
        struct tree *x;
        x=*root;
        while(1){
        if((x)->l==NULL)
        {
            (x)->l=temp;
            break;
        }
        else if((x)->r==NULL)
        {
            (x)->r=temp;
            break;
        }
        else
            x=x->l;
    }
}
}
void Display(struct tree *root)
{
    if(root)
    {
        Display((root)->l);
        printf("%d",(root)->data);
        Display((root)->r);
    }
}
int main()
{
    struct tree *root=NULL;
    printf("1>INSERT\n2>DISLAY\n");
    int n;
    while(1){
        printf("\nenter choice :");
    scanf("%d",&n);
    if(n==1)
         Insert(&root);
    else if(n==2)
        Display(root);
    else
        break;
}
}
