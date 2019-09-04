#include<stdio.h> 
#include<stdlib.h> 
struct node 
{ 
    int key; 
    struct node *left, *right; };


struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 



struct node* insert(struct node* node, int key) 
{ 
    if (node == NULL) return newNode(key); 
  
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else
        node->right = insert(node->right, key); 
  
    return node; 
} 


struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
    while (current->left != NULL) 
        current = current->left; 
    return current; 
} 

struct node * maxValueNode(struct node* node) 
{ 
    struct node* current = node; 
    while (current->right != NULL) 
        current = current->right; 
    return current; 
}
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d ", root->key); 
        inorder(root->right); 
    }
}

int main() 
{ 
   int n,i,data;
   struct node *root = NULL; 
   printf("Write the number of element's");
   scanf("%d",&n);
   printf("Enter the element's of the array\n");
   for(i=0;i<n;i++)
   {
    scanf("%d",&data);
    root=insert(root, data);
   }
    printf("Inorder traversal of the given Binary Search Tree is \n"); 
    inorder(root);
    printf("\nThe Maximum and Minimum element of the Binary Search Tree is:");
    printf("\nmax is %d\n", maxValueNode(root)->key);
    printf("min is %d\n", minValueNode(root)->key);
 }