#include <stdio.h>
#include <math.h>
void swap(float *xp, float *yp)
{
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int partition (float arr[], int low, int high) 
{ 
    float pivot = arr[high];  
    int i = (low - 1); 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++;    
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
void quickSort(float arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
void selectionSort(float arr[], int n)
{
    int i, j, min_idx;
 
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}
void bubbleSort(float arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)      
 
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}
void merge(float arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    float L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
    i = 0; 
    j = 0;
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(float arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
 
 void insertionSort(float arr[], int n)
{
   int i, j;
   float key;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
        while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}
void printArray(float arr[], int n)
{
   int i;
   for (i=n-1; i >= 0; i--)
       printf("%f ", arr[i]);
   printf("\n");
}
int main()
{
    int n,i,c;
    printf("enter no of element in array\n");
    scanf("%d",&n);
    float arr[n];
    for(i=0;i<n;i++)
    {
      scanf("%f",&arr[i]);
    }
    printf("\n1->insertion sort\n2->selection sort \n3->bubblesort \n4->mergesort \n5->quicksort\n");
    scanf("%d",&c);
    if(c==1)
    {
    insertionSort(arr, n);
    printArray(arr, n);
    }
    if(c==2)
    {
      selectionSort(arr,n);
      printArray(arr,n);
    }
    if(c==3)
    {
      bubbleSort(arr,n);
      printArray(arr,n);
    }
    if(c==4)
    {
      mergeSort(arr,0,n-1);
      printArray(arr,n);
    }
    if(c==5)
    {
      quickSort(arr,0,n-1);
      printArray(arr,n);
    }
    return 0;
}
