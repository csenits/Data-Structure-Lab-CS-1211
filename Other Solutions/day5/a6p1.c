#include <stdio.h>
 
int main()
{
  int array[100], search, c, n;
 
  printf("number of elements in array = \n");
  scanf("%d", &n);
 
  printf("Enter numbers \n", n);
 
  for (c = 0; c < n; c++)
    scanf("%d", &array[c]);
 
  printf("search Element = \n");
  scanf("%d", &search);
 
  for (c = 0; c < n; c++)
  {
    if (array[c] == search)
    {
      printf("%d Found at location %d.\n", search, c+1);
      break;
    }
  }
  if (c == n)
    printf("%d Not Present!.\n", search);
 
  return 0;
}
