#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *link;
};
struct node *head,*temp,*temp1,*newnode,*cur,*prev;
struct node * insert_at_beg(struct node *);
struct node * insert_at_end(struct node *);
struct node * delete_at_beg(struct node *);
struct node * delete_at_end(struct node *);
void display(struct node *);
int count_nodes(struct node *);
struct node * insert_at_pos(struct node*, int);
void search_node(struct node*,int);
struct node * delete_at_pos(struct node *head,int pos);
struct node *temp,*temp1,*newnode;

main()
{
  head=NULL;
  int ch,c,pos,d;
  while(1)
  {
  printf("1-insert at begining\n");
  printf("2--insert at end\n");
  printf("3--delete at begining\n");
  printf("4--delete at end\n");
  printf("5--display\n");
    printf("6--count of nodes\n");
     printf("7--insert a node at a pos\n");
     printf("8--search a node\n");
     printf("9--Delete a node at a pos\n");
          printf("10--exit\n");

  printf("enter the choice\n");
scanf("%d",&ch);
switch(ch)
{
  case 1: newnode=(struct node *)malloc(sizeof(struct node));
                 printf("enter the data\n");
                 scanf("%d",&newnode->data);
                 head=insert_at_beg(newnode);
                 break;
  case 2: newnode=(struct node *)malloc(sizeof(struct node));
                 printf("enter the data\n");
                 scanf("%d",&newnode->data);
                 head=insert_at_end(newnode);
                 break;
    case 3: head=delete_at_beg(head);
               break;
    case 4:head=delete_at_end(head);
               break;
    case 5: display(head);
              break;
    case 6: c=count_nodes(head);
                   printf("no of nodes=%d\n",c);
                   break;
    case 7: printf("enter position\n");
                   scanf("%d",&pos);
                    if(pos<1 ||pos>count_nodes(head)+1)
                        printf("invalid pos\n");
                    else
                    {
                        newnode=(struct node*)malloc(sizeof(struct node));
                       printf("enter data\n");
                       scanf("%d",&newnode->data);
                        head=insert_at_pos(newnode,pos);
                    }
                    break;
        case 8:printf("enter the data to search\n");
           scanf("%d",&d);
           search_node(head,d);
           break;
    case 9: printf("enter position\n");
                   scanf("%d",&pos);
                    if(pos<1 ||pos>count_nodes(head))
                        printf("invalid pos\n");
                    else
                        head=delete_at_pos(head,pos);
                    break;
  case 10: exit(0);break;
default:printf("invalid choice\n");break;
}
}
}
struct node * insert_at_beg(struct node *newnode)
{
   if(head==NULL)
     {
        head=newnode;
        newnode->link=head;
     }
    //  else
    //  {
    //     temp=head;
    //     while(cur->link!=head)
    //     {
    //        temp=temp->next;
    //     }
    //     temp->next=newnode;
    //     newnode->next=head;
    //     head=newnode;
    //  }
     else{
        cur=head;
        while (cur->link!=head)
        {
            cur=cur->link;
        }
        cur->link=newnode;
            newnode->link=head;
            head=newnode;

     }
     return(head);
}
struct node * insert_at_end(struct node *newnode)
{
   if(head==NULL)
     {
        head=newnode;
        newnode->link=head;
     }
    //  else
    //  {
    //     temp=head;
    //     while(temp->next!=head)
    //     {
    //        temp=temp->next;
    //     }
    //     temp->next=newnode;
    //     newnode->next=head;
    //  }
    else{
        cur=head;
        while (cur->link!=head)
        {
            cur=cur->link;
        }
            cur->link=newnode;
            newnode->link=head;
        
    }
     return(head);
}
struct node * delete_at_beg(struct node *head)
{
   if(head==NULL)
     {
        printf("CLL is empty--cant delete\n");
     }
     else
     {
         if(head->next==head)
         {
            printf("node deleted=%d\n",head->data);
            free(head);
            head=NULL;
         }
        //  else
        //  {
        //      temp=head;
        //      while(temp->next!=head)
        //      {
        //        temp=temp->next;
        //      }
        //       printf("node deleted=%d\n",head->data);
        //      prev=head->next;
        //       free(head);
        //       temp->next=prev;
        //       head=prev;
        //  }
        
     }
     return(head);
}
struct node * delete_at_end(struct node *head)
{
   if(head==NULL)
     {
        printf("CLL is empty--cant delete\n");
     }
     else
     {
         if(head->next==head)
         {
            printf("node deleted=%d\n",head->data);
            free(head);
            head=NULL;
         }
         else
         {
             cur=head;
             while(temp->link!=head)
             {
            //  temp1=temp;
            //    temp=temp->next;
               prev=cur;
               cur=cur->link;
             }
             prev->link=head;
              printf("node deleted=%d\n",temp->data);
             free(cur);
         }
     }
     return(head);
}
void display(struct node *head)
{
  if(head==NULL)
     {
        printf("CLL is empty\n");
     }
     else
     {
         temp=head;
         while(temp->next!=head)
         {
            printf("%d->",temp->data);
            temp=temp->next;
         }
         printf("%d->\n",temp->data);
     }
}
int count_nodes(struct node *head)
{
    int count=0;
    if(head==NULL)
       return(count);
    else
    {
           temp=head;
        while(temp->next!=head)
        {
            count++;
            temp=temp->next;
        }
        count++;
        return(count);
    }
}
struct node * insert_at_pos(struct node *newnode,int pos)
{
    
    if(pos==1)
        head=insert_at_beg(newnode);
    else
    {
        cur=head;
        
        while (cur->link!=head)
        {
            prev=cur;
            cur=cur->link;
        }
        
        cur->link=newnode;
        newnode->link=cur;
        
    }
    return(head);
}
struct node * delete_at_pos(struct node *head,int pos)
{
    
    if(pos==1)
        head=delete_at_beg(head);
    else
    {
        
        cur=head;
        for (int  i = 1; i < pos; i++)
        {
            prev =cur;
            cur=cur->link;
            
        }
        
            
        
        prev->link=cur->link;
        printf("Node deleted=%d\n",temp->data);
        free(cur);
           }
    return(head);
}
void search_node(struct node *head,int d)
{
    int found=0;
    if(head==NULL)
        printf(" Circular linked list is empty cant search\n");
    else
    {

        temp=head;
        while(temp->next!=head)
        {
            if(temp->data==d)
            {
                //printf("node found\n");
                found=1;
                break;
            }
            temp=temp->next;
        }
            if(temp->data==d)
        {
            printf("node found\n");
                found=1;
        }

        if(found==0)
            printf("node not found\n");
    }
}