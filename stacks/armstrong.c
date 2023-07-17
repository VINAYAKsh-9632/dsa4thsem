#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define size 100
struct stack{
    int top;int data[size];
};
void push(struct stack * sptr,int num){
    if(sptr->top==size-1){
        printf("overflow");
        
    }
    else{
        sptr->top++;
        sptr->data[sptr->top]=num;
    }
}
int pop(struct stack* sptr){
    int num;
    if(sptr->top==-1){
        printf("underflow");
    }
    else{
        num=sptr->data[sptr->top];
        sptr->top--;
    }
    return num;
}
int main()
{
    struct stack *sptr;
    struct stack a;
    sptr=&a;
    int num;
    scanf("%d",&num);
    int copy = num;
    int rem,sum=0;
    while(num>0){
        rem=num%10;
        sum=sum+(rem*rem*rem);
        push(sptr,rem);
        num=num/10;
    }
    int t= copy;
    int status=0;
    copy=sum;
    printf("%d",sptr->data[sptr->top]);
    while (copy>0)
    {
        rem=copy%10;
        
        int p=pop(sptr);
        if (sum==p)
        {
            status=1;
            break;
        }
        sum=sum+(rem*rem*rem);
        copy=copy/10;
    }
    printf("%d",sptr->data[sptr->top]);
    if (status==1)
    {
       printf("%d is  armstrong num",t);
    }
    else{
        printf("%d is  not a armstrong num",t);
    }

    return 0;
}