#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define size 100
struct stack{
    int top;
    int data[size];

};
void push(struct stack *sptr,int num){
    if (sptr->top==size-1)
    {
        printf("stack overflow");
    }
    else{
        sptr->top++;
        sptr->data[sptr->top]=num;

    }
}
int pop(struct stack *sptr){
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
void max(struct stack *sptr,int num){
   int m=0;
   
   for (int  i = sptr->top; i >=0; i--)
   {
    int n=pop(sptr);
    if (n>m)
    {
        m=n;
    }
   }
    printf("the max is %d\n",m);

}
int main()
{    
    struct stack *sptr;
    struct stack a;
    sptr=&a;
    sptr->top=-1;
    int num,r;
    scanf("%d",&r);
    for (int i = 0; i < r; i++)
    {
        /* code */
        scanf("%d",&num);
        push(sptr,num);
    }
    max(sptr,num);
    
    return 0;
}