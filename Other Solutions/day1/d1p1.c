#include <stdio.h>

int main()
{
	int a,b,sum;
	printf("enter the numbers\n");
	scanf("%d%d",&a,&b);
	sum=a+b;
	binary(a);
	binary(b);
	//printf("the sum is %d\n",a+b);
	binary(sum);
}
void binary(int a)
{
	int i=0,j,k,list[100];
	int y=a;
	while(a>0)
	{
		k=a%2;
		a=a/2;
		list[i]=k;
		i++;
	}
	printf("binary of %d is\n",y );
	for(j=0;j<i;j++)
	{
		printf("%d",list[i-j-1]);
	}
	printf("\n");
}