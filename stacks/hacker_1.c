#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct queue{
 
        char name[100];
    int age;
    char from[100];
    char to[100];
    struct queue*link;
};
struct queue*create(){
    struct queue*newnode=(struct queue*)malloc(sizeof(struct queue));
    scanf("%s%d%s%s",newnode->name,&newnode->age,newnode->from,newnode->to);
    newnode->link=NULL;
    return newnode;
}
struct queue*enqueue(struct queue*head){
    struct queue*newnode=create();
    struct queue*cur=head;
    while(cur->link!=NULL){
        cur=cur->link;
    }
    cur->link=newnode;
    newnode->link=NULL;
    return head;
}
void operation(struct queue*head){
    int count=0;
    struct queue*cur;
        cur=head;
    while(cur!=NULL){
        
        if(cur->age>=60){
            printf("%s %d %s %s\n",cur->name,cur->age,cur->from,cur->to);
            count++;
        }
        cur=cur->link;
    }
    int c=count*200;
    printf("%d\n",c);
}
int main() {

    struct queue*head=NULL;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        head=enqueue(head);
    }
    operation(head);
    return 0;
}
