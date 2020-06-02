#include<stdio.h> 
#include<stdlib.h> 
#include <stdbool.h>
  

struct Node 
{ 
    int key; 
    struct Node *left; 
    struct Node *right; 
    int height;
    int balance_factor; 
}; 
  
int height(struct Node *root) 
{ 
    int heightright=1;
    int heightleft=1
    if (root == NULL) 
     {
          heightleft=1;
          heightright=1;
     }    
    else 
    {
        if(root->left!=NULL)
        {
             heightleft+=height(root->left);
        }
        if(root->right!=NULL)
        {
            heightright+=height(root->right);
        }
    }
    return max(heightleft,heightright); 
} 
  
int max(int a, int b) 
{ 
    if(a<b)
    {
        return b;
    }
    return a;
} 
void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\n",root->data);
		inorder(root->right);
	}
}

struct Node* newNode(int data) 
{ 
    struct Node* node = (struct Node*)malloc(sizeof(struct Node)); 
    node->key   = data; 
    node->left   = NULL; 
    node->right  = NULL; 
    node->height = 1;  
    node->balance_factor=0; 
    return(node); 
} 
  
struct Node *rightRotate(struct Node *y) 
{ 
    struct Node *x = y->left; 
    struct Node *T2 = x->right; 
  
    x->right = y; 
    y->left = T2; 
  
    y->height = height(y)+1; 
    x->height = height(x)+1; 
  
    return x; 
} 
   
struct Node *leftRotate(struct Node *x) 
{ 
    struct Node *y = x->right; 
    struct Node *T2 = y->left; 
  
    y->left = x; 
    x->right = T2; 
  
    x->height = height(x)+1; 
    y->height = height(y)1; 
  
    return y; 
} 
void balance_factor_traversal(struct node* root)
{
	if(root!=NULL)
	{
		balance_factor_traversal(root->left);
		printf("%d: %d \n",root->data,root->balance_factor);
		balance_factor_traversal(root->right);
	}
}
int getBalanceFactor(struct Node *node) 
{ 
    if (node == NULL) 
        return 0; 
    return height(node->left) - height(node->right); 
} 

bool search(struct node *root,int key)
{
	if(root==NULL||root->data==key)
	{
		return true;
	}
	if(root->data < key)
	{
		return search(root->right , key);
	}
	else if(root->data >  key)
	{
	return search(root->left,key);
	}
	return false; 	
}


void balance_assign(struct node* root)
{
	if(root!=NULL)
	{
		
		root->balance_factor= findHeight(root->left)-findHeight(root->right);
		balance_assign(root->left);
		balance_assign(root->right);

	}
}

struct Node* insert(struct Node* node, int key) 
{ 
    if (node == NULL) 
        return(newNode(key)); 
  
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key); 
    else // Equal keys are not allowed in BST 
        return node; 
  
    node->height = 1 + height(node);  
  
    int balance = getBalanceFactor(node); 
  
  
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
  
    return node; 
} 
  
void balance_order_traversal(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d : %d\n",root->data,root->balance_factor);
        balance_order_traversal(root->left);

    }
}  


void preOrder(struct Node *root) 
{ 
    if(root != NULL) 
    { 
        printf("%d ", root->data); 
        preOrder(root->left); 
        preOrder(root->right); 
    } 
} 
  
/* Drier program to test above function*/
int main() 
{ 
  printf("ENter the number of testcases: \n");
  int testcases;
  scanf("%d",&testcases);
  while(testcases-- >0)
  {
    printf("Enter the size of the array");
	int size;
	scanf("%d",&size);
	int* arr=(int*)malloc(sizeof(int)*size);

	printf("Enter now the values of the array :");
	for(int i=0;i<size;i++)
	{
		scanf("%d",arr+i);
	}
	struct node *root =NULL;
	root=insert(root,*(arr+0));
	for(int i=1;i<size;i++)
	{
		insert(root,*(arr+i));
	}
    printf("Enter the value to be checked \n");
	int key ;
	scanf("%d",&key);
	
	bool check = search(root,key);	

	if(!check)
	{
		printf("Element is already present inside the tree.");
	}
	else
	{
		printf("Adding element to the tree.");
		struct node* new=insert(root,key);
		printf("The final tree then becomes,in inoder sense :\n");
		inorder(new);
	}
	balance_assign(root);
	printf("The order of the balance factor traversal  is \n");
	balance_factor_traversal(root);


    printf("Preorder traversal of the constructed AVL"
         " tree is \n"); 
    preOrder(root); 
  }
  return 0; 
} 