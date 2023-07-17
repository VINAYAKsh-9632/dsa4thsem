#include<stdio.h>
#include<stdlib.h>
#define x 5
struct stack
{
    int data[x];
    int top;
};

void push(struct stack *s,int num)
{
   if(s->top==x-1)
   {
       printf("Stack overflow\n");
   }
   else
   {
       s->top=s->top+1;
       s->data[s->top]=num;

   }
}

void pop(struct stack *s)
{
    int num;
    if(s->top==-1)
    {
        printf("Stack underflow\n");
    }
    else
    {
       num=s->data[s->top];
       s->top=s->top-1;
    }


}

int peek(struct stack *s)
{
    if(s->top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        return s->data[s->top];
         printf("Peek element is %d\n",s->data[s->top]);
    }
}

void display(struct stack *s)
{
    int i;
    if(s->top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        for(i=s->top;i>=0;i--)
        {
            if(s->top == i)
                printf("| %d | <- TOP\n",s->data[i]);
            else
                printf("| %d |\n",s->data[i]);
        }
    }
}

int  main()
{
    struct stack a,s1_var,s2_var,s5_var,s10_var;
    struct stack *s,*s1,*s2,*s5,*s10;
    s=&a;
    s2=&s2_var;
    s5=&s5_var;
    s10=&s10_var;

    int num,num1,n,top1;
    s->top=-1;



    

    printf("Enter the number of cooions:");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        printf("Enter a coin to push\n");
                   scanf("%d",&num);
                   push(s,num);
    }

    for(int i=0; i<n; i++)
    {
        top1 = peek(s);

    if(top1 == 1)
    {
        pop(s);
        num = 1;
        push(s1,num);
    }
    else if(top1 == 2)
    {
        pop(s);
        num = 2;
        push(s2,num);
    }
    else if(top1 == 5)
    {
        pop(s);
        num = 5;
        push(s5,num);
    }
    else if(top1 == 10)
    {
        pop(s);
        num = 10;
        push(s10,num);
    }
    else{
        printf("Invalid coin\n");
    }
    }

    display(s1);
    display(s2);
    display(s5);
    display(s10);




    return 0;

}