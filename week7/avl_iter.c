#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct node {
	int data;
	int balance_factor;
	struct node *left;
	struct node *right;
	int height_of_node;	
};
bool search(struct node *root,int key)
{
	//key present in the root position
	if(root==NULL||root->data==key)
	{
		return true;
	}
	//if key is greater than root
	if(root->data < key)
	{
		return search(root->right , key);
	}
	//else  key leser than root
	else if(root->data >  key)
	{
	return search(root->left,key);
	}
	// if element not found then return false 
	return false; 	
}

struct node* newnode(int data)
{
	struct node * node =(struct node*)malloc(sizeof(struct node));
	node->data =data;
	node->left=NULL;
	node->right=NULL;
	node->height_of_node=1;
	node->balance_factor=0;
	return node;
}

struct node* insert(struct node* node,int data)
{
	if(node==NULL)
		return(newnode(data));

	if(data < node->data)
	{
		node->left=insert(node->left,data);
	}
	else if(data > node->data)
	{
		node->right=insert(node->right,data);
	}
	else 
		return node;

	//updating height of the present ancestor node 
	node->height_of_node=1+height(node);

	//the balance must be between -1,0,1
	int balance=balanceval(node);
	//else we have to deal with the four cases
	//1.left left case
	if(balance > 1 && data < node->left->data)
	{
		return rightRotate(node);
	}
	//2.right right case
	if(balance < -1 && data > node->right->data)
	{
		return leftRotate(node);
	}
	//3.left right case
	if(balance > 1 && data > node->left->data)
	{
		node->left=leftRotate(node->left);
		return rightRotate(node);
	}
	//4.right left case
	if(balance > 1 && data < node->left->data)
	{
		node->right=rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}

int max(int a ,int b);
{
	if(a>b)
		return a;
	return b;
}

int height(struct node* node)
{
	int heightleft=1;
	int heightright=1;
	if(node==NULL)
	{
		heightleft=1;
		heightright=1;
	}
	else 
	{
		if(node->left!=NULL)
		{
			heightleft+=height(node->left);
		}
		if(node->right!=NULL)
		{
			heightright+=height(node->right);
		}

	}
	return max(heightright,heightleft);
}

struct node* rightRotate(struct node* node)
{
	struct node *l1= node->left;
	struct node *l2 =l1->right;

	//performing rotation 
	l1->right=node;
	node->left=l2;

	node->height_of_node=height(node)+1;
	l1->height_of_node=height(node)+1;

	return l1;
}

struct node* leftRotate(struct node* node)
{
	struct node *l1=node->right;
	struct node *l2=l1->left;

	l1->left=node;
	node->right=l2;

	node->height_of_node = height(node)+1;
	l1->height_of_node=height(node)+1;

	return l1;
}

int balanceval(struct node* node)
{
	if(node==NULL)
		return 0;
	int p = (height(node->left)-height(node->right));
	node->balance_factor=p;
	return p;
}

void balance_factor_traversal(struct node* node)
{
	if(node!=NULL)
	{	
		printf("%d: %d\n",node->data,node->balance_factor);
		balance_factor_traversal(node->left);
		balance_factor_traversal(node->right);
	}	
}
void preOrder(struct node* root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}
void balance_assign(struct node* root)
{
	if(root!=NULL)
	{
		
		root->balance_factor= height(root->left)-height(root->right);
		balance_assign(root->left);
		balance_assign(root->right);
	}
}

int main()
{
	printf("Enter the number of iterations : \n");
	int t ;
	scanf("%d",&t);
	while(t-- >0)
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
		printf("The final tree then becomes,in inorder sense :\n");
		preOrder(new);
	}
	balance_assign(root);	
	printf("The order of the balance factor is \n");
	balance_factor_traversal(root);

	printf("\n The final ordering of the A.V.L tree is \n");
	preOrder(root);
	}	
	return 0;
}