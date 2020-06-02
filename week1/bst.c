/**
 * @Date:   2020-04-11T09:33:19+05:30
 * @Last modified time: 2020-05-03T14:09:54+05:30
 */



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
	int data;
	struct node *right;
	struct node *left;
};

//making an new connection
struct node *newnode(int item)
{
	struct node *root = (struct node*)malloc(sizeof(struct node));
	root->data =item;
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

//searching the binary tree for the element and if no duplicate entry is found then entering the value
//key is the element to be searched
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

int main()
{
	printf("Enter the number of testcases \n");
	int t;
	scanf("%d",&t);
	while(t-->0){

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

	//printing the inorder ,preorder , postorder

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
}
return 0;

}
