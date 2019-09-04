#include<stdio.h>
int calcSum(int* array, int start, int len)
{
    int    sum = 0;
    printf("[%d:%d]: {", start, start+len);
    for(int ndx = 0; ndx < len; ndx++)
    {
        printf("%d,", array[start+ndx]);
        sum = sum + array[start+ndx];
    }

    printf("} the sum is %d\n", sum);
    return sum;
}
int main(void)
{
    int i;
    int max = -1;// will hold largest sum
    int len;  
    printf("Enter the size of array");
    scanf("%d",&len);
    int arr[len];
    printf("Enter the elements of array");
    for(i=0;i<len;i++)
    {	int temp;
	scanf("%d",&temp);
	arr[i]=temp;
     }

    for(int sub = (len-1); sub > 1; sub--)           // loop for length of sub-arrays
    {
        for(int jdx = 0; jdx+sub <= len; jdx++)   // looping over elements in original array
        {
             int temp = calcSum(arr, jdx, sub);
             if(temp > max)
                 max = temp;

        }
    }
    printf("maximum sum of sub-array is: %d\n", max);
}
