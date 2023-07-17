#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define size 100
struct stack{
    int data[size];
    int top;
};


void push(struct stack * sptr,int num){
    if (sptr->top==size-1)
    {
        printf("overflow");
    }
    else{
        sptr->top++;
        sptr->data[sptr->top]=num;
    }

}
int pop(struct stack * sptr){
    int num;
    if (sptr->top==-1)
    {
        printf("underflow");
    }
    else{
        num=sptr->data[sptr->top];
        sptr->top--;
    }
    return num;
}
int evaluate(struct stack * sptr,char postfix[size]){
    int op1,op2,i=0;
    char ch;
    while(ch=postfix[i]!='\0'){
        if (isdigit(ch))
        {
           push(sptr,ch - '0');
        }
        else{
            op2=pop(sptr);
            op1=pop(sptr);
        }
    
    }
    return (pop(sptr));
}
int main()
{
    int ch;
      
        int num,op1,op2;
        struct stack a;
        struct stack *sptr;
        sptr=&a;
        
        sptr->top=-1;

        switch(ch){
            case'+':push(sptr,op1+op2);
            break;
            case'-':push(sptr,op1-op2);
            break;
            case'*':push(sptr,op1*op2);
            break;
            case'/'
        }
    return 0;
}
