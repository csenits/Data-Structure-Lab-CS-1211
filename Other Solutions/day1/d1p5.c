#include <stdio.h>
int main()
{
	int i,j=0,k=0,n,l=0;
	printf("Give the number  of inputs\n");
	scanf("%d",&n);
	int list[n];
	printf("Give the inputs\n");
	for (i = 0; i < n; ++i)
		scanf("%d",&list[i]);
	for (i = 0; i < n; ++i)
		if (list[i]%2==0)
			l++;

	int even[l],odd[n-l];
	for (i = 0; i < n; ++i)
		{
			if(list[i]%2==0){
				even[j]=list[i];
				j++;
			}
			else{
				odd[k]=list[i];
				k++;

			}	
		}

	printf("Printing the odd and even array\n");
	printf("this is the even array\n");
	for (i = 0; i < l; ++i)
		printf("%d\n",even[i]);
	printf("this is the odd array\n");
	for (i = 0; i < n-l; ++i)
		printf("%d\n",odd[i]);
	return 0;
}