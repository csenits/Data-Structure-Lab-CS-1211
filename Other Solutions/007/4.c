#include <stdio.h>
int array[100], n=0;
void display()
{
    int i;
    if (n == 0)
    {
        printf("Heap is empty \n");
        return;
    }
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void insert(int num, int location)
{
    int parentnode;
    while (location > 0)
    {
        parentnode =(location - 1)/2;
        if (num <= array[parentnode])
        {
            array[location] = num;
            return;
        }
        array[location] = array[parentnode];
        location = parentnode;
    }
    array[0] = num;
}
void delete(int num)
{
    int left, right, i, temp, parentnode;
 
    for (i = 0; i < num; i++) 
    {
        if (num == array[i])
            break;
    }
    array[i] = array[n - 1];
    n = n - 1;
    parentnode =(i - 1) / 2;
    if (array[i] > array[parentnode])
    {
        insert(array[i], i);
        return;
    }
    left = 2 * i + 1; 
    right = 2 * i + 2;
    while (right < n)
    {
        if (array[i] >= array[left] && array[i] >= array[right])
            return;
        if (array[right] <= array[left])
        {
            temp = array[i];
            array[i] = array[left];
            array[left] = temp;
            i = left;
        }
        else
        {
            temp = array[i];
            array[i] = array[right];
            array[right] = temp;
            i = right;
        }
        left = 2 * i + 1;
        right = 2 * i + 2;
    }
    if (left == n - 1 && array[i])    {
        temp = array[i];
        array[i] = array[left];
        array[left] = temp;
    }
}
int main()
{
   int t,i,data;
   struct node *root = NULL; 
   printf("Enter the number of element's of the array\n");
   scanf("%d",&t);
   printf("Enter the element's of the array\n");
   for(i=0;i<t;i++)
   {
    scanf("%d",&data);
    insert(data,n);
    n=n+1;
   }
   printf("the heap is\n");
   display();
   printf("what to delete\n");
   scanf("%d",&data);
   delete(data);
   printf("the heap is\n");
   display();
}