#include<stdio.h>

int main()
{
    int n,a;
    printf("enter the size of array\n");
    scanf("%d",&n);
    a=n/3;
    int s[n],top1=-1,top2=n+1,j,m,i;
    printf("enter first %d element of stack1\n",a);
    for(i=0;i<a;i++)
    {
        scanf("%d",&s[i]);
        top1++;
    }
    printf("enter first %d element of stack2\n",a);
    for(i=0;i<a;i++)
    {
        scanf("%d",&s[n-i]);
        top2--;
    }



     do
  {
      printf("\npress 1 for push1\n,2 for pop1\n , 3 for push2\n and 4 for pop2\n  \n");
  scanf("%d",&m);
  switch(m)
  {
  case 1:
       if(top1==top2-2)
  {
    printf("stackoverflow");
  }
  else{
        top1++;
         printf("what element to insert \n");
        scanf("%d",&s[top1]);
        printf("%d is now topmost element of stack1  \n",s[top1]);
  }

  break;
  case 2:
            if(top1==-1)
                printf("stack is empty cant pop and can not pop further\n");
            else
              {
                  printf("%d is poped from stack1 \n ",s[top1]);
                top1--;
              }
              break;
  case 3 :
       if(top2==top1+2)
  {
    printf("stackoverflow");
  }
  else{
        printf("what to insert \n");
        top2--;
        scanf("%d",&s[top2]);
        printf("%d is now topmost element of stack2  \n",s[top2]);
  }

  break;
  case 4:
            if(top2==n+1)
                printf("stack 2 is empty cant pop and can not pop further\n");
            else
              {

                printf("%d is poped \n ",s[top2]);
                top2++;
              }
              break;
  default:
    printf("wrong input.. nothing to do..");
  }
printf("press 0 to terminate");

scanf("%d",&j);
  }
while(j!=0);
for(i=0;i<n;i++)
{
    printf("%d\t",s[i]);
}
return 0;
}
