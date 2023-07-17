#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node*head=NULL;
bool isEmpty(){
    return head==NULL;
}
void push(int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    // scanf("%d", &newnode->data);
    newnode->data=data;
    if(isEmpty()){
        head=newnode;
        return;
    }
    newnode->next=head;
    head=newnode;

}
int pop(){
    if(isEmpty()){
        printf("Empty");
        return -1;
    }
    int top = head->data;
    head=head->next;
    // printf("%d\n", top);
    return top;
}
int peek(){
    // printf("Peek is %d\n", head->data);
    return head->data;
}
void getNextGreater(int arr[],int n){
    
        int nxtGreater[n];
    
        for (int i = n - 1; i >= 0; i--) {
            while (!isEmpty() && arr[peek()] <= arr[i]) {
                pop();
                printf("pop");
            }
            if (isEmpty()) {
                nxtGreater[i] = -1;
                printf("Empty");
            } else {
                nxtGreater[i] = arr[peek()];
                printf("peek");
            }
            push(i);
    printf("push");
        }
        int m = sizeof(nxtGreater)/sizeof(nxtGreater[0]);
        for (int i = 0; i < m; i++) {
            // System.out.print(nxtGreater[i] + " ");
            printf("%d\n",nxtGreater[i]);
        }
        // System.out.println();

    }
int main(){
    
      int arr[] ={4, 2, 1, 5, 3};
      int n = sizeof(arr)/sizeof(arr[0]);
    //   printf("%d",n);

      
    getNextGreater(arr,n);
   
   
    
    return 0;
}