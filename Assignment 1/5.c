#include<stdio.h>
int main(){
int n;
int i,e=0,o=0;
printf("Enter the size of the array");
scanf("%d",&n);
int a[n];
printf("Enter the elements");
for(i=0;i<n;i++)
{	int temp;
	scanf("%d",&temp);
	a[i]=temp;
}
for(i=0;i<n;i++)
{	if(a[i]%2==0){
		e++;	
	}
	else{
		o++;	
	}
}
int even[e];
int odd[o];
e=0;
o=0;
for(i=0;i<n;i++)
{
	if(a[i]%2==0){
		even[e]=a[i];
		e++;
	}
	else{
		odd[o]=a[i];
		o++;
	}
}
printf("even elements are");
for(i=0;i<e;i++)
{	
	printf("%d",even[i]);
}
printf("odd elements are");
for(i=0;i<o;i++)
{	
	printf("%d",odd[i]);
}


}

