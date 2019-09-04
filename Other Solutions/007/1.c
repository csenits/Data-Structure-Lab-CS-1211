#include<stdio.h>

int count=1;

typedef struct node
{
 int data;
 struct node*left;
 struct node*right;
}node;

void insert(node**bt,int n)
{
     if(*bt==NULL)
        {
         *bt=(node*)malloc(sizeof(node));
          (*bt)->data=n;
          (*bt)->left=NULL;
          (*bt)->right=NULL;
          count++;
         }
     else
         {
         if(count%2==0)
         insert(&((*bt)->left),n);
         else
         insert(&((*bt)->right),n);
         }
        }

void inorder(node*bt)
{
 if(bt!=NULL)
 {
  inorder(bt->left);
  printf("%d\t",bt->data);
  inorder(bt->right);
 }
}


void preorder(node*bt)
{
 if(bt!=NULL)
 {
  printf("%d\t",bt->data);
  preorder(bt->left);
  preorder(bt->right);
 }
}

void postorder(node*bt)
{
 if(bt!=NULL)
 {
  postorder(bt->left);
  postorder(bt->right);
  printf("%d\t",bt->data);
  
 }
}

void main()
{
  int i;

 node*bt=NULL;
 int n;
  printf("Enter the number of elements for tree:\n");
 scanf("%d",&n);
 printf("Enter elements for tree:\n");
 int arr[n];
 for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  for(i=0;i<n;i++)
    {
      insert(&bt,arr[i]);
    } 
  printf("Tree In-Order is\n");
 inorder(bt);
 printf("\n");
 printf("Tree In Pre-Order is\n");
 preorder(bt);
 printf("\n");
 printf("Tree in Post-Order is\n");
 postorder(bt);
}