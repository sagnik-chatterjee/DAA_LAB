#include<stdio.h> 
#include<stdlib.h> 
  

struct Node 
{ 
    int key; 
    struct Node *left; 
    struct Node *right; 
    int height; 
}; 
  
int max(int a, int b); 
  
int height(struct Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return N->height; 
} 
  
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 
  
struct Node* newNode(int key) 
{ 
    struct Node* node = (struct Node*) 
                        malloc(sizeof(struct Node)); 
    node->key   = key; 
    node->left   = NULL; 
    node->right  = NULL; 
    node->height = 1;  // new node is initially added at leaf 
    return(node); 
} 
  
struct Node *rightRotate(struct Node *y) 
{ 
    struct Node *x = y->left; 
    struct Node *T2 = x->right; 
  
    // Perform rotation 
    x->right = y; 
    y->left = T2; 
  
    // Update heights 
    y->height = max(height(y->left), height(y->right))+1; 
    x->height = max(height(x->left), height(x->right))+1; 
  
    // Return new root 
    return x; 
} 
  
struct Node *leftRotate(struct Node *x) 
{ 
    struct Node *y = x->right; 
    struct Node *T2 = y->left; 
  
    // Perform rotation 
    y->left = x; 
    x->right = T2; 
  
    //  Update heights 
    x->height = max(height(x->left), height(x->right))+1; 
    y->height = max(height(y->left), height(y->right))+1; 
  
    // Return new root 
    return y; 
} 
  
// Get Balance factor of node N 
int getBalance(struct Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right); 
} 
  
struct Node* insert(struct Node* node, int key) 
{ 
    /* 1.  Perform the normal BST insertion */
    if (node == NULL) 
        return(newNode(key)); 
  
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key); 
    else // Equal keys are not allowed in BST 
        return node; 
  
    node->height = 1 + max(height(node->left), 
                           height(node->right)); 
  
 
    int balance = getBalance(node); 
  
    // Left Left Case 
    if (balance > 1 && key < node->left->key) 
        return rightRotate(node); 
  
    // Right Right Case 
    if (balance < -1 && key > node->right->key) 
        return leftRotate(node); 
  
    // Left Right Case 
    if (balance > 1 && key > node->left->key) 
    { 
        node->left =  leftRotate(node->left); 
        return rightRotate(node); 
    } 
  
    // Right Left Case 
    if (balance < -1 && key < node->right->key) 
    { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 
  
    /* return the (unchanged) node pointer */
    return node; 
} 
  
void preOrder(struct Node *root) 
{ 
    if(root != NULL) 
    { 
        printf("%d ", root->key); 
        preOrder(root->left); 
        preOrder(root->right); 
    } 
} 
  
int main() 
{ 
    printf("Enter the numbr of iterations \n");
    int t;
    scanf("%d",&t);
    while(t-- >0)
    {
        printf("Enter the size off the array \n");
        int size;
        scanf("%d",&size);
        int *arr =(int*)malloc(sizeof(int)*size);
        printf("Now enter the elements of the array \n");     
        for(int i=0;i<size;i++)
        {
            scanf("%d",arr+i);
        }
        struct Node *root = NULL; 
  
        //inserting the first eleemnt of the array as root
        root=insert(root,*(arr+0));
        //entering the other elelmnts of the array as leaves for the tree
        for(int i=1;i<size;i++)
        {
            root=insert(root,*(arr+i));
        }  
 
  
         printf("Preorder traversal of the constructed AVL"
         " tree is \n"); 
         preOrder(root); 
         printf("\n");               
    }
  return 0; 
} 
