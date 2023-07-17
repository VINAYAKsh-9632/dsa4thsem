#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
FILE *fp,*level;
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void levelOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    struct Node* queue[1000];
    int front = -1, rear = -1;
    queue[++rear] = root;
    queue[++rear] = NULL;
    while (front != rear) {
        int c=0;
        struct Node* cur = queue[++front];
        if (cur == NULL) {
            printf("\n");
           
            if (front == rear) {
                break;
            } else {
               
                queue[++rear] = NULL;
            }
        } else {
        
            printf("%d ",cur->data);
            
             fprintf(level,"%d\n",cur->data);
            if (cur->left != NULL) {
               
                queue[++rear] = cur->left;
            }
            if (cur->right != NULL) {
                
                queue[++rear] = cur->right;
            }
         
    
        }
       
       
    }
}

int main() {
    struct Node *root = NULL;
   level=fopen("output.txt","w+");
    
     srand(time(NULL));
    fp=fopen("input.txt","w+");
    int n,val;
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
        root=insertNode(root,val);
    }
   
    levelOrder(root);

    return 0;
}
e