// C program to insert a node in AVL tree
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// An AVL tree node
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	int height;
};
FILE *fp,*pre;
// A utility function to get the height of the tree
int height(struct Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
	return (a > b)? a : b;
}

/* Helper function that allocates a new node with the given key and
	NULL left and right pointers. */
struct Node* newNode(int key)
{
	struct Node* node = (struct Node*)
						malloc(sizeof(struct Node));
	node->data = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially added at leaf
	return(node);
}


struct Node *rightRotate(struct Node *y)
{
	struct Node *x = y->left;
	struct Node *T2 = y->left->right;


	x->right = y;
	y->left = T2;


	y->height = max(height(y->left),
					height(y->right)) + 1;
	x->height = max(height(x->left),
					height(x->right)) + 1;

	
	return x;
}


struct Node *leftRotate(struct Node *x)
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;
         ///  0
		 //  /
		  //  0
		  ///  \0  
	
	y->left = x;
	x->right = T2;


	x->height = max(height(x->left),
					height(x->right)) + 1;
	y->height = max(height(y->left),
					height(y->right)) + 1;

	
	return y;
}


int getBalance(struct Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}


struct Node* insert(struct Node* root, int key)
{

	if (root == NULL)
		return(newNode(key));

	if (key < root->data)
		root->left = insert(root->left, key);
	else if (key > root->data)
		root->right = insert(root->right, key);
	else 
		return root;

	root->height = 1 + max(height(root->left),
						height(root->right));


	int balance = getBalance(root);


	// Left Left Case
	if (balance > 1 && key < root->left->data)
		return rightRotate(root);

	// Right Right Case
	if (balance < -1 && key > root->right->data)
		return leftRotate(root);

	// Left Right Case
	if (balance > 1 && key > root->left->data)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Left Case
	if (balance < -1 && key < root->right->data)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}


// void preOrder(struct Node *root)
// {
// 	if(root == NULL){
//         return ;
//     }
// 	else{
//         fprintf(pre,"%d\n",root->data);
// 		printf("%d->", root->data);
// 		preOrder(root->left);
// 		preOrder(root->right);
// 	}
// }



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
		  
             fprintf(pre,"%d\n",cur->data);
            if (cur->left != NULL) {
               
                queue[++rear] = cur->left;
            }
            if (cur->right != NULL) {
                
                queue[++rear] = cur->right;
            }
         
    
        }
       
       
    }
}
int main()
{
struct Node *root = NULL;
	pre=fopen("pre.txt","w+");
    
    srand(time(NULL));
    fp=fopen("insert.txt","w+");
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
        root=insert(root,val);
    }
// preOrder(root);
levelOrder(root);

return 0;
}
