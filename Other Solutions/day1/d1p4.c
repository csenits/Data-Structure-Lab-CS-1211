#include<stdio.h>
#include<stdlib.h>
int max(int a,int b);
int max(int a,int b)
{
	if(a>b)
	return a;
	return b;
}
int main()
{

int ele,i,j,k;
scanf("%d",&ele);
        int a[ele];
        
        for(j=0;j<ele;j++)
        {
            scanf("%d",&a[j]);
        }
        int ans=a[0];
        for(j=0;j<ele;j++)
        {
            int sum =0;
            for(k=1;k<=ele;k++)
            {
                if(k+j>ele)
                break;
                sum=sum+a[k+j-1];
                ans=max(sum,ans);
            }
        }
        ans=max(ans,a[ele-1]);
        printf("Ans= %d",ans);
    }
