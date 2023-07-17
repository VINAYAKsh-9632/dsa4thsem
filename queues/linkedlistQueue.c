#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
int c=0;
int count=0;
struct Node *head=NULL,*tail=NULL;
struct Node * add(){
    struct Node * newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("enter the value");
    scanf("%d",&newnode->data);
    if(head==NULL){
        head=tail=newnode;
    }
    tail->next=newnode;
    tail=newnode;

}
void dequeue(int n){
    c++;
   
    if(head==n){
        printf("%d\n",head->data);
    // int r = head->data;
    }
    head=head->next;
    // return r;
}

int main()
{   
    for(int i=0; i<5;i++){
        add();
    }
    dequeue(2);
//    int n=dequeue(2);
//    printf("\n%d\n", n);
  
    return 0;
}