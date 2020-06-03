//Implement binary search tree in which all keys are unique if duplicate key is there, inform else insert.
//Traverse the BST in preorder, postorder and inorder.

#include<stdio.h>
#include<stdlib.h> 

typedef struct node* nptr;
typedef struct node{
	int data;
	nptr left;
	nptr right;
}node;

nptr createNode(int x){
	nptr temp = malloc(sizeof(node));
	temp->left = temp -> right = NULL;
	temp->data = x;
	return temp;
}

nptr insertNode(nptr root, int x)
{
	if (root == NULL)
	{
		printf("Inserted in BST!\n");
		return createNode(x);
	}
	
	if (root->data == x)
		printf("Already exists in BST!\n");
	else if(root->data > x)
		root->left = insertNode(root->left, x);
	else if(root->data < x)
		root->right = insertNode(root->right, x);

	return root;
} 

void inorder(nptr root)
{
	if (root == NULL)
		return;

	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

void preorder(nptr root)
{
	if (root == NULL)
		return;

	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void postorder(nptr root)
{
	if (root == NULL)
		return;

	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->data);

}

int main()
{
	nptr root = NULL;

	int ch = 1;
	int ele;
	printf("1. Insert    2. Inorder    3. Preorder    4. Postorder    0. Exit\n");

	while(ch)
	{
		printf("\nCommand: ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1: printf("Enter element to insert: ");
					scanf("%d", &ele);
					root = insertNode(root, ele);
					break;

		
			case 2: printf("Inorder: "); 
					inorder(root);
					break;

			case 3: printf("Preorder: ");
					preorder(root);
					break;

			case 4: printf("Postorder: ");
					postorder(root);
					break;
		}
	}

	return 0;
}