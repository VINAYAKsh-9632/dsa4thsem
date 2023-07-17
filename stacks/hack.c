#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define size 100
struct stack{
    int top;
    int data[size];
};
void push(struct stack *sptr,int num){
   
    
    
        
        sptr->top++;
        sptr->data[sptr->top]=num;
   
    
}
int pop(struct stack *sptr)
{
    int num;
    
       num=sptr->data[sptr->top];
       sptr->top--;
    
   return num;

}
void operation(int e){
    struct stack *sptr1,*sptr2;
    struct stack a,b;
    sptr1=&a;
    sptr2=&b;
    int num;
    for (int i = 0; i < e; i++)
    {
        scanf("%d",&num);
        if (num>=1 && num<=100)
        {
            push(sptr1,num);
        }
        
    }
    for (int i = 0; i < e; i++)
    {
        scanf("%d",&num);
        if (num>=1 && num<=100)
        {
            push(sptr2,num);
        }
        
    }
    int max1=0;
    for (int i = sptr1->top; i >=0; i--)
    {
        int h=pop(sptr1);
        if (h>max1)
        {
            max1=h;
        }
        
    }
        printf("max1  is %d\n ",max1);
        
        
    int max2=0;
    for (int i=sptr2->top; i >=0; i--)
    {
        int g=pop(sptr2);
        if (g>max2)
        {
            max2=g;
        }
        
        
    }
    printf("the max1 is %d",max1);
    printf("the max2 is %d",max2);

    if (max1>max2)
    {
        for (int i = 0; i < e; i++)
        {
            printf("1 ");
        }
        printf("\nJim");
    }
    else if (max2>max1)

    {
        printf("1 ");
        for (int i = 0; i < e; i++)
        {
            printf("2 ");
        }
        printf("\nDavid");
    }
    else if (max1==max2)
    {
        for (int i = 0; i < e; i++)
        {
            printf("0 ");
        }
        printf("\nTie");
    }
    
    
}
int main()
{
    int e;
    scanf("%d",&e);
    operation(e);
    return 0;
}