#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    
};




struct Node *create_node(int n){
    struct Node *newnode,*cur,*head=NULL;

    for (int i = 0; i < n; i++)
    {
        // create_node
    newnode=(struct Node*)malloc(sizeof(struct Node));

        printf("enter the data%d\n",i+1);
        scanf("%d",&newnode->data);
         newnode->next=NULL;
		
                                 
                                                                
                                                                    if(head==NULL){
                                                                        head=newnode;
                                                                    }else{
                                                                    
                                                                        cur=head;
                                                                        while(cur->next!=NULL){
                                                                            cur=cur->next;
                                                                        }
                                                                        cur->next=newnode;
 }
 
        
    }
    return head;
}
    struct Node* findMid(struct Node *head) {
        struct Node* slow = head;
        struct Node* fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;

    }

  

 struct Node* merge(struct Node* left, struct Node* right) {
   struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
        struct Node* mergell = newnode;
        struct Node* temp = mergell;
        while (left != NULL && right != NULL) {
            if (left->data <= right->data) {
                temp->next = left;
                left = left->next;
                temp = temp->next;
            } else {
                temp->next = right;
                right = right->next;
                temp = temp->next;
            }
           
        }
        while (left != NULL) {
            temp->next = left;
            left = left->next;
            temp = temp->next;
        }
        while (right != NULL) {
            temp->next = right;
            right = right->next;
            temp = temp->next;

        }
        return mergell->next;

    }

    void print(struct Node* head) {
        if (head == NULL) {
            printf("empty");
            return;
        }
        struct Node* cur = head;
        while (cur != NULL) {

            printf("%d->",cur->data);
            cur = cur->next;
        }
        printf("\n");

    }
  struct Node* mergeSort(struct Node* head) {
        if (head == NULL|| head->next == NULL) {
            return head;
        }
        struct Node* mid = findMid(head);

        struct Node* left = mergeSort(head);// left

        struct Node* right = mergeSort(mid->next);// right
         struct Node* result=merge(left, right);
         return result;
       
        
    }

int main()
{    struct Node *head;
int n;
    printf("enter the number of elements");
    scanf("%d",&n);


   head=create_node(n);
   print(head);

      mergeSort(head);
   print(head);
    
    return 0;
}


