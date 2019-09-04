#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};
void Insert(struct tree **root)
{
    struct tree *temp=malloc(sizeof(struct tree));
    printf("enter data :");
    scanf("%d",&temp->data);
    temp->left=temp->right=NULL;
    if(*root==NULL){
        *root=temp;
    }
    else{
    struct tree *x=*root;
    while(((temp->data)<(x->data))&&(x->left!=NULL))
    {
        x=x->left;
    }
    if((x->left==NULL)&&((temp->data)<(x->data))){
        x->left=temp;

    }
    while(((temp->data)>=(x->data))&&(x->right!=NULL))
    {
        x=x->right;
    }
    if((x->right==NULL)&&((temp->data)>=(x->data))){
        x->right=temp;
        }
    }
}
void Display(struct tree *root)
{
    if(root)
    {
        Display((root)->left);
        printf("%d",root->data);
        Display(root->right);
    }
}
void smallest(struct tree *root)
{
    while(root->left)
        root=root->left;
    printf("\n%d\n",root->data);
}
void largest(struct tree *root)
{
    while(root->right)
        root=root->right;
    printf("\n%d\n",root->data);
}
int main()
{
    struct tree *root=NULL;
    printf("1>INSERT\n2>DISLAY\n3>smallest\n4>largest");
    int n;
    while(1){
        printf("\nenter choice :");
    scanf("%d",&n);
    if(n==1)
         Insert(&root);
    else if(n==2)
        Display(root);
    else if(n==3)
        smallest(root);
    else if(n==4)
        largest(root);
    else
        break;

}
}
