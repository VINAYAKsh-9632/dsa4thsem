#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
struct node {
  int data;
  struct node *left, *right;
};
FILE *fp,*in;
  struct node *findIs(struct node*root){
        while(root!=NULL&&root->left!=NULL){
            root=root->left;
        }
        return root;
    }
struct node *createNode(int item) {
  struct node* newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = item;
  newNode->left = newNode->right = NULL;
  return newNode;
}
struct node *buildtree(struct node *root,int val){
    if(root==NULL){
        return createNode(val);
    }
    
        if(root->data >val){
            root->left = buildtree(root->left,val);
        }else if(root->data < val){
            root->right = buildtree(root->right,val);
        }
    return root;
    
}
  struct node *delete(struct node *root, int key) {
        if (root == NULL) {
            return NULL;
        }
        if (root->data > key) {
            root->left = delete(root->left, key);
        } else if (root->data < key) {
            root->right = delete(root->right, key);
        } else {
            if (root->left == NULL && root->right == NULL) {
                return NULL;
            } else if (root->left == NULL) {
                return root->right;
            } else if (root->right == NULL) {
                return root->left;
            } else { // equal
                struct node * inorderSuccssor = findIs(root->right);
                root->data = inorderSuccssor->data;
                root->right = delete(root->right, inorderSuccssor->data);
            }
        }
        return root;
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
    void inorder1(struct node *root){
    if(root==NULL) {
        return;
    }
    inorder(root->left);
    printf("%d->",root->data);
       fprintf(in,"%d\n",root->data);
    inorder(root->right);

}

int main()
{
     int val,n;
     in=fopen("deleteinorder.txt","w+");
    struct node *root=NULL;
     srand(time(NULL));
    fp=fopen("delete.txt","w+");
    
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
        root=buildtree(root,val);
    }
    int key;
    inorder1(root);
    printf("enter the key\n");
    scanf("%d",&key);

    root=delete(root,key);
    inorder(root);
    return 0;
}