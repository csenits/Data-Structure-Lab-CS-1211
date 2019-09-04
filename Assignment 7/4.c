#include<stdio.h>
#include<stdlib.h>
struct heap
{
    int *ar;
    int cnt;
    int capacity;
};
struct heap *cH(int n)
{
    struct heap *h=malloc(sizeof(struct heap));
    h->cnt=0;
    h->capacity=n;
    h->ar=(int*)malloc(sizeof(int)*h->capacity);
    return h;
}
int leftchild(struct heap *h,int i)
{
    int left=2*i+1;
    if(left>=h->cnt)
        return -1;
    return left;
}
int rightchild(struct heap *h,int i)
{
    int right=2*i+2;
    if(right>=h->cnt)
        return -1;
    return right;
}
void heapify(struct heap *h,int i)
{
    int l,r,max,temp;
    l=leftchild(h,i);
    r=rightchild(h,i);

    if((l!=-1)&&(h->ar[l]>h->ar[i]))
        max=l;
    else
        max=i;
    if((r!=-1)&&(h->ar[r]>h->ar[max]))
        max=r;
    if(max!=i)
    {
        temp=h->ar[i];
        h->ar[i]=h->ar[max];
        h->ar[max]=temp;
        heapify(h,max);
    }
}
struct heap *Insert(struct heap *h,int data)
{
    if(h->cnt==h->capacity)
        {
            h->capacity*=2;
            h->ar=realloc(h->ar,h->capacity*sizeof(int));
        }
    int temp,i;
    h->cnt++;
    i=h->cnt-1;
    h->ar[i]=data;
   for(i=0;i<h->cnt;++i)
    heapify(h,i);
    return h;
}
int Delt(struct heap *h)
{
    int data;
    if(h->cnt==0)
        return -1;
    data=h->ar[0];
    h->ar[0]=h->ar[h->cnt-1];
    h->cnt--;
    heapify(h,0);
    return data;
}
int main()
{
    struct heap *h=cH(10);
    int n;
    printf("1->INSERT\n2->DELETE");
    while(1)
    {
        printf("\nenter choice :");
        scanf("%d",&n);
        if(n==1)
        {
            printf("\nenter data :");
            scanf("%d",&n);
            h=Insert(h,n);
            heapify(h,0);
        }
        else if(n==2)
        {
            printf("%d ",Delt(h));
        }
        else
            break;
    }
}
