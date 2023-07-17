#include<stdio.h>
#define x 1000
struct stack
{
    char letter[x];
    int top;
};
int validate(char exp[x]);
void push(struct stack *s,char a);
char pop(struct stack *s);
void main()
{
    char exp[x];
    printf("Enter the expression\n");
    scanf("%s",exp);
    int v=validate(exp);
    if(v==1)
    {
        printf("Expression is valid\n");
    }
    else
    {
        printf("Expression is invalid\n");
    }
}
int validate(char exp[x])
{
    struct stack s_var;
    struct stack *s;
    s=&s_var;
    s->top=-1;
    int i=0;
    char a,b;
    while(exp[i]!='\0')
    {
        a=exp[i];
        if(a=='(' || a=='['  || a=='{')
        {
           push(s,a);
        }

        else if(a==')')
        {
            if(s->top==-1)
            {
                return 0;
            }
         b=pop(s);
         if(b!='(')
         {
             return 0;
         }
        }
        else if(a==']')
        {
            if(s->top==-1)
            {
                return 0;
            }
            b=pop(s);
            if(b!='[')
            {
                return 0;
            }
        }
       else if(a=='}')
        {
            if(s->top==-1)
            {
                return 0;
            }
            b=pop(s);
            if(b!='{')
            {
                return 0;
            }
        }
     i++;
    }
    if(s->top==-1)
    {
        return 1;
    }
    else
    {

        return 0;
    }
}
void push(struct stack *s,char a)
{
    if(s->top==x-1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        s->top=s->top+1;
        s->letter[s->top]=a;
    }
}
char pop(struct stack *s)
{
    char a;
    if(s->top==-1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        a=s->letter[s->top];
        s->top=s->top-1;
    }
    return a;
}