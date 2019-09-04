#include<stdio.h>
int main(){
int n;
int counter=0,min;
int i,index;
printf("Enter n");
scanf("%d",&n);
int a[n];
printf("Enter the numbers you want to compare");
for(i=0;i<n;i++)
{	int temp;
	scanf("%d",&temp);
	a[i]=temp;
}
min=a[0];
for(i=0;i<n-1;i++)
{	

	if(min>a[i+1])
	{
		min=a[i+1];
		index = i+1;
		counter++;
	}		
}
a[index]=1000000;
min=a[0];
for(i=0;i<n-1;i++)
{	

	if(min>a[i+1])
	{
		min=a[i+1];
		counter++;	
	}		
}
printf("The 2nd min is %d",min);
printf("The number of counts required is %d",counter);


}

