#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define size 100
struct queue{
    int data[size];
    int front,rear;
};
void enqueue(struct queue*qptr,int num){
    if(qptr->rear==-1 && qptr->front==-1){
        qptr->rear=qptr->front=0;
        qptr->data[qptr->rear]=num;
    }
    else if(qptr->rear+1%size==qptr->front){
        printf("overflow");

    }
    else{
        qptr->rear=qptr->rear+1%size;
        qptr->data[qptr->rear]=num;
    }
}
int dequeue(struct queue*qptr){
    int num;
    if (qptr->rear==-1 && qptr->front)
    {
        printf("overflow");
    }
    else if (qptr->front==qptr->rear){
        num=qptr->data[qptr->front];
        qptr->rear=qptr->front=-1;

    }
    else{
        num=qptr->data[qptr->front];
        qptr->front=qptr->rear+1%size;
    }
    return num;
}
int main()
{
    
    return 0;
}