#include<stdio.h>
int main(){
int r,c,flag;
int i,j,k,sr,sc,s,er,ec;
printf("Enter the number of rows and columns respectively");
scanf("%d%d",&r,&c);
int a[r][c];
printf("Enter the elements");
for(i=0;i<r;i++)
{	for(j=0;j<c;j++)
		{	int temp;
			scanf("%d",&temp);
			a[i][j]=temp;
		}

}
printf("Enter the element you want to search");
scanf("%d",&k);
for(i=0;i<r;i++)
{	for(j=0;j<c;j++)
		{	if(k==a[i][j]){
				flag=1;
				break;
			}
			else{
				flag=0;
			}
		}

}
if(flag==1){
	printf("found");
}
else{
	printf("not found");
}

printf("Enter the row and column number where you want to store the element");
scanf("%d%d",&sr,&sc);
printf("Enter the element you want to store the element");
scanf("%d",&s);
a[sr][sc]=s;
printf("Enter the row and column number from where you want to extract the element");
scanf("%d%d",&er,&ec);
printf("The element is %d",a[er][ec]);
}
