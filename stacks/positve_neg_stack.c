#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define size 100
struct stack{
    int top;int data[size];
};
void push(struct stack * sptr,int num){
    if (sptr->top==size-1){
        printf("overflow");

    }
    else
    {
            sptr->top++;
            sptr->data[sptr->top]=num;
    }
    
}
void display(struct stack*sptr){
    if (sptr->top==-1)
    {
        printf("empty");
    }
    else{
        for (int i = sptr->top; i >=0; i--)
        {
            /* code */
        printf("%d",sptr->data[i]);
        }
    }
        
}


int main()
{
    struct stack *sptr1,*sptr2;
    struct stack a,b;
    sptr1=&a;sptr2=&b;
    sptr1->top=-1;
    sptr2->top=-1;

    int r,c,num;
    printf("enter the  size of array");
    scanf("%d%d",&r,&c);
    for (int i = 0; i < r; i++)
    {   scanf("%d",&num);
        if (num<=0)
        {
            push(sptr1,num);
            
        }
        
    }
    display(sptr1);
    for (int i = 0; i < c; i++)
    {   scanf("%d",&num);
        if (num<=0)
        {
            push(sptr2,num);
            
        }
        
    }
    display(sptr2);
    

    return 0;
}