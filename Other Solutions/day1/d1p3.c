#include <stdio.h>
int main()
{
	int i,n,min2,min1,t;
	printf("give the number of inputs\n");
	scanf("%d",&n);
	int list[n];
	printf("Give the number of inputs\n");
	for (i = 0; i < n; i++)
		scanf("%d",&list[i]);	
	min2=list[1];
	min1=list[0];
	if (min1>min2)
	{
		t=min1;
		min1=min2;
		min2=t;
	}
	for (i = 2; i < n; i++)
	{
			if(list[i]<min1){
				min2=min1;
				min1=list[i];
			}

			else if(list[i]<min2)
				min2=list[i];

	}

	printf("the minimum = %d \n the second minimum = %d \n",min1,min2);
	return 0;
}