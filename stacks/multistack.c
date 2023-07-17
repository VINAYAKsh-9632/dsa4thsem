#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define size 100
struct stack{
    int top;
    int data[size];

};
void push(struct stack*sptr,int num){
    if (sptr->top==size-1)
    {
        /* code */printf("stack overflow");
    }
    else{
        sptr->top++;
        sptr->data[sptr->top] = num;
    }
    
}
int pop(struct stack*sptr){
    int num;
    if (sptr->top==-1)
    {
        printf("stack underflow");
    }
    else{
        num=sptr->data[sptr->top];
        sptr->top--;
    }
    return num;
}

int main()
{
    struct stack *sptr1,*sptr2;
    struct stack a,b;
    sptr1=&a;
    sptr2=&b;

    sptr1->top=-1;
    sptr2->top=-1;
    int p=0,n=0;
    int num;
    int m,c;

    printf("enter");
    scanf("%d%d",&m,&c);
    for (int i = 0; i < m; i++)
    {
        scanf("%d",&num);
        push(sptr1,num);
    }
    for (int i = 0; i < c; i++)
    {
        scanf("%d",&num);
        push(sptr2,num);
    }
    
    while (sptr1->top!=-1)

    {
        int num1=pop(sptr1);
        if (num1<=0)
        {
           n++;
        }
        else if (num1>0)
        {
            p++;
        }
        
    }
    printf("the positive number are %d\n",p);
    printf("the negative number are %d\n",n);
    int n1=0,p1=0;
    while (sptr2->top!=-1)
    {
        int num2=pop(sptr2);
        if (num2<0)
        {
            /* code */
            n1++;
        
        }
        else if (num2>0){
            p1++;
        }
        
        /* code */
    }
    printf("the positive number are %d\n",p1);
    printf("the negative number are %d\n",n1);
    

    
    return 0;
}