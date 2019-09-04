#include<stdio.h>
int main()
{
	int work;
	printf("enter x and y order of array\n");
	int x,y,i,j,t,nu,x2,y2;
	scanf("%d%d",&x,&y);
	int arr[x][y];
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			scanf("%d",&arr[i][j]);
		}
		printf("\n");
    }
    int k=0;

	printf("1 for find elememt \n");
	printf("2 for insert element\n");
	printf("3 for extract element\n");
	do
	{
	
	scanf("%d",&work);
	switch(work)
	{
		case 1:
			printf("what to find\n");
			int a;
			
			scanf("%d",&a);
				for(i=0;i<x;i++)
                 	{
		              for(j=0;j<y;j++)
		                {
		                	if(arr[i][j]==a)
		                	{
		                		printf("yes\n");
		                		k=0;
							}
							else
							k++;
						}
					}
					if(k>0)
					{
						printf("no\n");
					}
				break;		
		case 2:
			
			printf("what to insert\n");
			scanf("%d",&nu);
			printf("enter x and y address\n");
			int x1,y1;
			scanf("%d%d",&x1,&y1);
			arr[x1][y1]=nu;
				for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			printf("%d ",arr[i][j]);
	    }
	    printf("\n");
	}
	break;
	case 3:	

		printf("enter x and y address\n");
		scanf("%d%d",&x2,&y2);
		int k=arr[x2][y2];
		printf("%d\n",k);
		break;
		
		
}

printf("press 0 to terminate");
scanf("%d",&t);
}while(t!=0);
return 0;
}
