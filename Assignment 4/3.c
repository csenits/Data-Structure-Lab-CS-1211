#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char ch;
    struct node *next;
};
struct node *strcnvcl(char c[])
{
   int i;
   struct node *head=NULL,*temp;
   for(i=strlen(c)-1;i>=0;--i)
   {
       temp=(struct node*)malloc(sizeof(struct node));
       temp->ch=c[i];
       temp->next=NULL;
       if(head==NULL)
        head=temp;
       else{
        temp->next=head;
        head=temp;
       }
   }
   return head;
}
int strvrfyl(struct node **l1,struct node **l2)
{
    struct node *h1=*l1;
    struct node *h2=*l2;
    int cnt=0,temp=0;
    while((h1!=NULL)&&(h2!=NULL))
    {
        if(h1->ch==h2->ch){
            cnt++;
            h1=h1->next;
            h2=h2->next;
        }
        else
            return cnt;
    }
    return -1;
}
void strsbstr(struct node *l1,int i,int j)
{
    struct node *h1=l1;
    int cnt=i;
    while(i!=0)
     {
         h1=h1->next;
         --i;
     }

     while(cnt!=j+1)
     {
         printf("%c",h1->ch);
          h1=h1->next;
          cnt++;
     }
}
int strcmpl(struct node *l1,struct node *l2)
{
    int cnt1=0;int cnt2=0;
    while(l1!=NULL)
    {
        cnt1++;
        l1=l1->next;
    }
    while(l2!=NULL)
    {
        cnt2++;
        l2=l2->next;
    }
    if(cnt1>cnt2)
        return 1;
    else
        if(cnt1<cnt2)
        return -1;
    else
        return 0;
}
int main(){
    struct node *l1,*l2;
    int a,m,n;
    char d[10],e[10];
    printf("enter string 1 :");
    scanf("%s",d);
    printf("\nenter string 2 :");
    scanf("%s",e);
    l1=strcnvcl(d);
    printf("\nstring 1 is converted into link list with head pointing to %c",l1->ch);
    l2=strcnvcl(e);
    printf("\nstring 2 is converted into link list with head pointing to %c",l2->ch);
    printf("\ntwo string are compaired\nresult:");
    printf("%d",strcmpl(l1,l2));

    a=strvrfyl(&l1,&l2);
    printf("\n first non recorrence character in string 1 is :");
    printf("%d",a);
    printf("\nenter 2 integers :");
    scanf("%d%d",&m,&n);
    if((m<=n)&&(n<strlen(d))&&m>=0)
        strsbstr(l1,m,n);
    else
        printf("enter the valid integers!");
}

