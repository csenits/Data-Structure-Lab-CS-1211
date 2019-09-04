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
struct tree *findmax(struct tree *root)
{
    if(root==NULL)
        return NULL;
    else if(root->right==NULL)
    return root;
    else return findmax(root->right);
}
struct tree *Delete(struct tree *root,int data)
{
    struct tree *temp;
    if(root==NULL)
        printf("element is not there in the tree\n");
    else if(data<root->data)
        root->left=Delete(root->left,data);
    else if(data>root->data)
        root->right=Delete(root->right,data);
    else
    {
        if((root->left)&&(root->right))
        {
            temp=findmax(root->left);
            root->data=temp->data;
            root->left=Delete(root->left,root->data);
        }
        else
        {
            temp=root;
            if(root->left==NULL)
                root=root->right;
            else
                root=root->left;
            free(temp);
        }
    }
    return root;
}
int main()
{
    struct tree *root=NULL;
    printf("1>INSERT\n2>DISLAY\n3>DELETE");
    int n;
    while(1){
        printf("\nenter choice :");
    scanf("%d",&n);
    if(n==1)
         Insert(&root);
    else if(n==2)
        Display(root);
    else if(n==3)
    {
        printf("enter data to delete:");
        scanf("%d",&n);
        root=Delete(root,n);
    }
    else
        break;
}
}
