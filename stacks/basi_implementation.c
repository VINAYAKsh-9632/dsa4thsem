#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define size 1000
struct stack{
    int data[size];
    int top;
};
void push(struct stack *sptr,int num){
   
    
    if (sptr->top==size-1)
    {
        printf("stack overflow\n");
    }
    else{
        
        sptr->top++;;
        sptr->data[sptr->top]=num;
    }
    
}
void pop(struct stack *sptr){
    int num;
    if (sptr->top==-1)
    {
        printf("underflow\n");
    }
    else{
        printf("Popped element:  %d\n",sptr->data[sptr->top]);

        
        sptr->top--;
    }
}
                            //  or 
// int pop(struct stack *sptr)
// {
//     int num;
//     if(sptr->top==-1)
//     {
//         printf("Stack underflow\n");
//     }
//     else
//     {
//        num=sptr->data[sptr->top];
//        sptr->top--;
//     }
//    return num;

// }
void peek(struct stack *sptr){
    if (sptr->top==-1)
    {
        
        printf("empty\n");
    }
    else{
        printf("peek elemnet is %d\n",sptr->data[sptr->top]);
    }
    
}
void display(struct stack *sptr){
    if (sptr->top==-1)
    {
        
        printf("empty\n");
    }
    else{
        for (int i =  sptr->top; i>=0;i--)
        {
            printf("%d->",sptr->data[i]);
        }
        
    }
}
int main()
{   int choice;
      
        int num;
        struct stack a;
        struct stack *sptr;
        sptr=&a;
        
        sptr->top=-1;


    while (1){
        
		printf("\nOperations performed by Stack");
		printf("\n1.Push the element\t2.Pop the element\t3.display\t4.End");
		printf("\n\nEnter the choice:");
		scanf("%d",&choice);
        switch(choice)
		{
			case 1:printf("enter the number of items in the stack\n");
                    scanf("%d",&num); 
                   push(sptr,num); 
					break;
			case 2: pop(sptr);
					break;
			case 3: display(sptr);
					break;
            case 5:peek(sptr);
                    break;
			case 4: exit(0);
            
			
			default: printf("\nInvalid choice!!");
		}
    }
    
    return 0;
}

