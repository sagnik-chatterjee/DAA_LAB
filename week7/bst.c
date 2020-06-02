#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct node{
	int data;
	int balance_factor;
	struct node *right;
	struct node *left;
};

//making an new connection
struct node *newnode(int item)
{
	struct node *root = (struct node*)malloc(sizeof(struct node));
	root->data =item;
	root->balance_factor=0;
	root->left=NULL;
	root->right =NULL;
	return root;
} 

//making the traversals
void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\n",root->data);
		inorder(root->right);
	}
}

void preorder(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d\n",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\n",root->data);
	}
}

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

struct node* insert(struct node *node ,int key)
{
	//in the main when element not found then we will insert into the tree from the main 
	//if tree is null
	if (node==NULL)
		return newnode(key);
	//else recur down the tree
	if (key < node->data )
	{
		node->left = insert(node->left,key);
	}
	else if(key > node->data)
	{
		node->right =insert(node->right,key);
	}
	return node;
}

int max(int n1 ,int n2)
{
	if(n1 > n2)
	{
		return n1;
	}
	return n2;
}



int findHeight(struct node* root){
	//finding height of tree to beused in balance factor 
	int count_nodes1=1;
	int count_nodes2=1;
	
	if(root==NULL){
		
		return 0;
	}
	else{
		if(root->left!=NULL){
			count_nodes1+=findHeight(root->left);
			
		}
		if(root->right!=NULL){
			count_nodes2+=findHeight(root->right);
		}
	}
	return max(count_nodes1,count_nodes2);

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

void balance_factor_traversal(struct node* root)
{
	if(root!=NULL)
	{
		balance_factor_traversal(root->left);
		printf("%d: %d \n",root->data,root->balance_factor);
		balance_factor_traversal(root->right);
	}
	
}


int main()
{
	printf("Enter the number of testcases \n");
	int t;
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

	
	printf("Inorder sequence :\n");
	inorder(root);
	printf("Preorder sequence :\n");
	preorder(root);
	printf("Postorder sequence : \n");
	postorder(root);

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

}
return 0;

}