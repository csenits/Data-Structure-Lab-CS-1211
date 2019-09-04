#include<stdio.h>
int main(){
int n,i;
int max,min;
printf("Enter n");
scanf("%d",&n);
int a[n];
printf("Enter the numbes you want to compare \n");
for(i=0;i<n;i++)
{	int temp;
	scanf("%d",&temp);
	a[i]=temp;
}
max=a[0];
min=a[0];
for(i=0;i<n-1;i++)
{	
	if(max<a[i+1])
	{
		max=a[i+1];

	}

	if(min>a[i+1])
	{
		min=a[i+1];
	}
			
}
printf("The max is %d and min is %d \n",max,min);
printf("The total number of comparisons is %d \n",i);

}

