#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
struct node {
  int data;
  struct node *left, *right;
};
FILE *fp,*in,*pre,*post;

struct node *createNode(int item) {
  struct node* newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = item;
  newNode->left = newNode->right = NULL;
  return newNode;
}

struct node*insert(struct node*root,int val){
    if(root==NULL) {
        root=createNode(val);
        return root;
    }
    if(root->data>val){
        root->left=insert(root->left,val);
    }else{
        root->right=insert(root->right,val);
    }
    return root;
}

void preorder(struct node *root){
    if(root==NULL) {
        return;
    }
    printf("%d->",root->data);
    fprintf(pre,"%d\n",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node *root){
    if(root==NULL) {
        return;
    }
    inorder(root->left);
    printf("%d->",root->data);
       fprintf(in,"%d\n",root->data);
    inorder(root->right);

}
void postorder(struct node *root){
    if(root==NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d->",root->data);
       fprintf(post,"%d\n",root->data);
}
int main()
{   int val,n;
    struct node *root=NULL;
   pre=fopen("preorder.txt","w+");
   in=fopen("inorder.txt","w+");
   post=fopen("postorder.txt","w+");
     srand(time(NULL));
    fp=fopen("bst.txt","w+");
    
    printf("Enter the number of random numbers\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        val=(rand()%100)+1;
        fprintf(fp,"%d\n",val);
    }
    rewind(fp);
    for(int i=0;i<n;i++)
    {
        fscanf(fp,"%d",&val);
        root=insert(root,val);
    }
    printf("Preorder traversal\n");
    preorder(root);
    printf("\ninorder traversal\n");
    inorder(root);
    printf("\npostorder traversal \n");
    postorder(root);


    
    return 0;
}