#include <string.h>
#include<stdio.h>
char s[20][20];
int top=-1;
void push1(char w)
{
    s[++top][0]=w;s[top][1]='\0';

}
void push(char a[])
{

    strcpy(s[++top],a);


}
char *pop()
{
    return s[top--];
}
int main()
{
    char ch[20],x[20],y[20],z[20];
    printf("enter the postfix string of numbers :");
    scanf("%s",ch);
    int i;
    for(i=0;ch[i]!='\0';++i)
    {
        if((ch[i]>=48)&&(ch[i]<=57)){
            push1(ch[i]);}
        else {
         strcpy(x,pop());
         strcpy(y,pop());
            strcpy(z,"(");
            strcat(z,y);
            if(ch[i]=='+')
                strcat(z,"+");
            else if(ch[i]=='-')
                strcat(z,"-");
            else if(ch[i]=='*')
                strcat(z,"*");
            else if(ch[i]=='/')
                strcat(z,"/");
            strcat(z,x);
            strcat(z,")");
            push(z);
        }

    }
    printf("required infix expression :\n");
    printf("%s",pop());
}
