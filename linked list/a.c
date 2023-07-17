#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* link;
};
typedef struct node *NODE;
NODE create_node();
NODE insert_front(NODE head);
int max_age(NODE head);
NODE delete_max_pos(int max,NODE head);
void display(NODE head);
int main()
{
    int n,i,max;
    NODE head=NULL;
    scanf("%d",&n);
    
    if(n>=1 && n<=100)
    {
        for(i=0;i<n;i++)
        {
            head=insert_front(head);
        }
        max=max_age(head);
        printf("Allowed for worship: %d\n",max);
        head=delete_max_pos(max,head);
        display(head);
    }
    return 0;
}
NODE insert_front(NODE head)
{
  NODE newnode;
    newnode=create_node();
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->link=head;
        head=newnode;
    }
    return head;
}
NODE create_node()
{
    NODE newnode;
    newnode=(NODE) malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    if(newnode->data<1 && newnode->data>200)
    {
        exit(0);
    }
    newnode->link=NULL;
    return newnode;
}
int max_age(NODE head)
{
    NODE cur=head;
    int max=0;
    while(cur!=NULL)
    {
        if(cur->data>max)
        {
            max=cur->data;
        }
        cur=cur->link;
    }
    return max;
}
NODE delete_max_pos(int max,NODE head)
{
    NODE cur=head,prev=NULL,temp;
    if(head->data==max)
    {
        temp=head;
        head=head->link;
        free(temp);
    }
    else
    {
     while(cur!=NULL)
    {
        if(cur->data==max)
        {
           prev->link=cur->link;
            free(cur);
        }
        prev=cur;
        cur=cur->link;
    }   
    }
    
    return head;
}
void display(NODE head)
{
    NODE cur;
    cur=head;
    if(head==NULL)
    {
        printf("No devotees to worship.");
    }
    else
    {
        printf("Remaining devotees: ");
      while(cur!=NULL)
    {
        printf("%d ",cur->data);
          cur=cur->link;
    }   
    }
   
}