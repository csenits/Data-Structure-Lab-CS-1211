#include <stdio.h>
int main()
{
	int i,n,max,min;
	printf("give the number of inputs\n");
	scanf("%d",&n);
	int list[n];
	printf("Give the number of inputs\n");
	for (i = 0; i < n; i++)
		scanf("%d",&list[i]);	
	max=list[0];
	min=list[0];
	for (i = 1; i < n; i++)
	{
			if (list[i]>max)
				max=list[i];
			if (list[i]<min)
				min=list[i];
	}

	printf("the maximum = %d \n the minimum = %d \n",max,min);
	return 0;
}