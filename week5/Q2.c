#include <stdio.h>
#include <stdlib.h>

typedef struct node* nodeptr;
typedef struct node
{
	int data;
	nodeptr left, right;
} node;

nodeptr newNode(int data)
{
	nodeptr nnode = (nodeptr) malloc(sizeof(node));
	nnode->data = data;
	nnode->left = NULL;
	nnode->right = NULL;

	return (nnode);
}

void insertTree(nodeptr *root, int data)
{
	if (*root == NULL)
	{
		*root = (newNode(data));
		return;
	}

	printf("\nEnter 1 to insert left of %d or 2 to insert right", (*root)->data);
	int n;
	scanf("%d", &n);
	
	if (n == 1)
		insertTree(&(*root)->left, data);
	else
		insertTree(&(*root)->right, data);
}

int max(int a, int b)
{
	return (a >= b) ? a : b;
}

int height(nodeptr root)
{
	if (root == NULL)
		return 0;
	
	return 1 + max(height(root->left), height(root->right));
}


/* Function to get diameter of a binary tree */
int diameter(nodeptr tree)
{
	if (tree == NULL)
		return 0;
	
	int lheight = height(tree->left);
	int rheight = height(tree->right);
	int ldiameter = diameter(tree->left);
	int rdiameter = diameter(tree->right);
	
	return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}

int main()
{
	nodeptr root = NULL;
	
	int n, m;
	printf("Enter number of nodes: ");
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		printf("Enter value:  ");
		scanf("%d", &m);
		insertTree(&root, m);
	}
	
	printf("\nThe diameter of the tree is: %d", diameter(root));
	return 0;
}