#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 101
struct stack
{
    int data[SIZE];
    int top;
};
void push(struct stack *sptr,int num);
int pop(struct stack *sptr);
int peek(struct stack *sptr);
void check(struct stack *jptr,struct stack *dptr);

int main() {
    struct stack *jptr,*dptr,j,d;
    jptr=&j;
    dptr=&d;
    jptr->top=-1;
    dptr->top=-1;
    int n,i,num;
    scanf("%d",&n);
    if(n>=1&&n<=100)
    {  
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        push(jptr,num);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        push(dptr,num);
    }
    check(jptr,dptr);
    }
    else
    {
        printf("Invalid input.");
        exit(0);
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
void push(struct stack *sptr,int num)
{
    if(sptr->top==SIZE-1)
    {
        printf("stack is overflow");
    }
    else
    {
        sptr->top++;
        sptr->data[sptr->top]=num;
    }
}
int pop(struct stack *sptr)
{
    int num=0;
    if(sptr->top==-1)
    {
        printf("stack is underflow");
    }
    else
    {
        num=sptr->data[sptr->top];
        sptr->top--;
    }
    return num;
}
int peek(struct stack *sptr)
{
    int num=0;
    if(sptr->top==-1)
    {
        printf("stack is empty");
    }
    else
    {
        num=sptr->data[sptr->top];
    }
    return num;
   
}

void check(struct stack *jptr,struct stack *dptr)
{
    int num;
    while(jptr->top!=-1&&dptr->top!=-1)
    {
        if(peek(jptr)>peek(dptr))
        {
            printf("1 ");
            num=pop(dptr);
        }
        else if(peek(jptr)<peek(dptr))
        {
            printf("2 ");
            num=pop(jptr);
            c1++;
        }
        else if(peek(jptr)==peek(dptr))
        {
            printf("0 ");
            num=pop(jptr);
            num=pop(dptr);
            c2++;
        }
    }
    printf("\n");
    if(jptr->top!=-1)
    {
        printf("Jim\n");
    }
    else if(dptr->top!=-1)
    {
        printf("David\n");
    }
  else if(jptr->top==-1&&dptr->top==-1)
    {
        printf("Tie");
    }
}