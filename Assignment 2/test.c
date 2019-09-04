#include<stdio.h>
int top=-1;

int main(){


int stacksize,choice,num,op;
printf("\nEnter the stack size\n");
scanf("%d",&stacksize);
int s[stacksize];
printf("\nHow many times do you want to run the operation");
scanf("%d",&op);


while(op>0)
{	
	printf("\nPress 1 to push and 2 for pop and 3 to display topmost element\n");
	scanf("%d",&choice);	
	if(choice==1)
	{
		printf("\nEnter the number you want to push\n");
		scanf("%d",&num);
		top++;
		s[top]=num;
		printf("%d",s[top]);

	}
	else if(choice==2)
	{
		s[top]=0;
		top--;	
		printf("%d",s[top]);
	}
	else if(choice==3)
	{
		printf("%d",s[top]);	
	}
op--;
}
}
