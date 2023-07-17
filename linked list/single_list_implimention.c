#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *create_node(int n){
    struct node *newnode,*cur,*head=NULL;

    for (int i = 0; i < n; i++)
    {
        // create_node
    newnode=(struct node*)malloc(sizeof(struct node));

        printf("enter the data%d\n",i+1);
        scanf("%d",&newnode->data);
         newnode->link=NULL;
		
                                     // insert end
                                                                
                                                                    if(head==NULL){
                                                                        head=newnode;
                                                                    }else{
                                                                    
                                                                        cur=head;
                                                                        while(cur->link!=NULL){
                                                                            cur=cur->link;
                                                                        }
                                                                        cur->link=newnode;
                                                                    }
                             // // insert front node
                      
                                                                            // if (head==NULL){
                                                                            //     head=newnode;
                                                                            // }
                                                                            // else
                                                                            // {
                                                                            //     newnode->link=head;
                                                                            //     head=newnode;
                                                                            // }
                                                                            

       
    
        
    }
    return head;
}

// insert at count and specfic position
void count_insert_pos(struct node*head ,int n){
    int c=0;
    
        
    
    
    struct node*cur,*prev,*newnode;
   
    if (head==NULL)
    {
        printf("empty");

    }
    else{
        cur= head;
        while (cur!=NULL)
        {
            c++;
            cur=cur->link;
        }
        
    }
    
   

    printf("the number of nodes are %d\n",c);
}

void revrese(struct node*head,int n){
                                                                int i,j;
                                                                i=0;
                                                                j=n-1;
                                                                struct node*p,*q,*cur;
                                                                p=q=head;
                                                                while(i<j){
                                                                    int k=0;
                    //revrese                                               
                                                                                while(k<j){
                                                                            q=q->link;
                                                                            k++;
                                                                    }
                     // or inseert front opertion                                               
                                                                    cur=p->data;
                                                                    p->data=q->data;
                                                                    q->data=cur;

                                                                    i++;
                                                                    j--;
                                                                    p=p->link;
                                                                    q=head;
                                            // insert front;
    // struct node*newnode;
    // if (head==NULL)
    // {
    //     head =newnode;
    // }
    // else
    // {
    //     newnode->link=head;
    //     head=newnode;
    // }
}}
int maxage(struct node*head,int n)
{		int max=0;
        struct node*cur=head;
        while(cur!=NULL){
            
                                                        if (max<cur->data)
                                                             {
                                                                max=cur->data;
                                                            }
                                                           
          
                                                           
            cur=cur->link;
        }
    return max;
}



struct node* search_del(struct node*head,int max){
    
    struct node* cur=head,*prev=NULL,*temp;
    if(head->data == max)
      {
          temp = head;    //backup to free the memory
          head = head->link;
          free(temp);
      }
      

      else
      {
          struct node *current  = head;
          while(current->link != NULL)
          {
              //if yes, we need to delete the current->next node
              if(current->link->data == max)
              {
                  temp = current->link;
                  //node will be disconnected from the linked list.
                  current->link = current->link->link;
                  free(temp);
                  break;
              }
              //Otherwise, move the current node and proceed
              else
                  current = current->link;
          }
      }
    
}

void sort(struct node *head,int n){
    int s=0;
    struct node*cur1,*cur2,*cur;
    for ( cur1=head;cur1!=NULL;cur1=cur1->link)
    {
        for (cur2=cur1->link;cur2!=NULL;cur2=cur2->link)

        {
            if (cur2->data < cur1->data)
            {
                /* code */
            
            
            s=cur1->data;
            cur1->data=cur2->data;
            cur2->data=s;
            }
            
        }
        
    
    }

    
}
void  dispalyLinkedList(struct node *head){
    
     if(head==NULL){
        printf("The Linked List is empty");
    }else{
		
        struct node*cur=head;
        while(cur!=NULL){
            printf("%d->",cur->data);
                                             
            cur=cur->link;
        }

}
}
void deletefront(struct node *head){
        struct node*cur;
        if (head==NULL)
        {
            /* code */
            printf("empty");

        }
        else if(head->link==NULL){
            printf("the deleted the fristnode is %d",head->data);
            free(head);
            head=NULL;
        }
        else{
            cur=head;
           head=head->link;
           printf("the deleted the fristnode is %d",cur->data);
           cur->link=NULL;
           free(cur);
            
        }
    
}
void deleteend(struct node *head){
    struct node*cur,*prev;
    if (head==NULL)
    {
        printf("empty");
    }

    else if(head->link==NULL){
        printf("the deleted the lastnode is %d",head->data);
            free(head);
            head=NULL;
        
    }
    else{
        cur=head;
        prev=NULL;
        while(cur->link!=NULL){
            prev=cur;
            cur=cur->link;
        }
        prev->link=NULL;
        printf("the deleted the lastnode is %d",cur->data);
        free(cur);
    }
}
int main()
{   
    struct node *head;
    int n,max;
    printf("enter the elments u wat printd");
    scanf("%d",&n);
    head=create_node(n);
    count_insert_pos(head,n);
    max=maxage(head,n);
    printf("the max is %d\n",max);
    
    dispalyLinkedList(head);
    search_del(head,n);
    printf("\n");
    dispalyLinkedList(head);

    sort(head,n);
    printf("\n");
    
    dispalyLinkedList(head);
    deletefront(head);
    

    printf("\n");
    deleteend(head);
    
    return 0;
}
