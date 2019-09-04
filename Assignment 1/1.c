#include<stdio.h>
int c=0;
 
int main(){
printf("Enter the two elements\n");
int n1,n2,x,n=0,c;
scanf("%d%d",&n1,&n2);
 
c=n1;

 while (c > 0)
    {
        c= c/2;
        n++;
    }
int a[n],b[n],sum[n+1],i=0, rem=0;
   while (n1>0) {
        a[n-i-1] = n1%2;
        n1=n1/2;
        i++;
	}
    i=0;
 while (n2>0) {
        b[n-i-1]=n2 % 2;
        n2=n2/2;
        i++;
    }
    i=n-1;
while (i>=0)
    {
 
        sum[i+1] =(a[i]+ b[i] + rem)%2;
 
        rem =(a[i] + b[i] + rem) / 2;
 
     i--;
    }
        sum[i+1] = rem;
 
for(i=0;i<=n;i++){
    printf("%d ",sum[i]);
}
}
