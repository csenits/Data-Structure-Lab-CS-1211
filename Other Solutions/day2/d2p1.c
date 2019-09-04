
#include<stdio.h>
void main()
{
    int n;
    int j;
    printf("enter size of array\n");
    scanf("%d",&n);
    int s[n];
  int top=0;

  printf("enter elements of the stack  \n");
  int i=1;
  for(i=1;i<6;i++)
  {
      scanf("%d",&s[i]);
      top=top+1;
  }
  int m;
  s[0]=top;

  do
  {
      printf("press 1 for push,2 for pop, 3 empty,4 popandtest,5 stacktop  \n");
  scanf("%d",&m);
  switch(m)
  {
  case 1: printf("what to insert \n");
       if(top==n)
  {
    printf("stackoverflow");
  }
  else{
        top++;
        scanf("%d",&s[top]);
        s[0]=top;
  }
  printf("%d is now topmost element  \n",s[top]);
  break;
  case 2:
            if(top==0)
                printf("stack is empty cant pop and can not pop further\n");
            else
              {

                printf("%d is poped \n ",s[top]);
                top--;
                s[0]==top;
              }
              break;
  case 3 : while(top!=0)
        {
        printf("%d is poped and top is %d\n",s[top],top);
                top--;
                s[0]==top;

        }
        printf("stack is empty\n");
        break;
  case 4: 
          if(top==0)
                printf("stack is empty cant pop and can not pop further\n");
            else
              {

                printf("%d is poped \n ",s[top]);
                top--;
                s[0]==top;
              }
              if(top==0)
                printf("Stalk underflow\n");



              break;

  case 5:

          printf("top element is %d\n",top);
          break;
  default:
    printf("wrong input");
    break;
    
   }
printf("press 0 to terminate");

scanf("%d",&j);
  }
while(j!=0);
return 0;
}
