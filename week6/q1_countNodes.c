#include <stdio.h>
#include <stdlib.h>

int opcount = 0;
int max(int a, int b) { return (a > b) ? a : b; }

typedef struct node* nodeptr;
typedef struct node {
	int data;
	nodeptr left, right;
} node;

nodeptr newNode(int data) {
	nodeptr temp = (nodeptr) malloc(sizeof(node));
	temp -> data = data;
	temp -> left = NULL;
	temp -> right = NULL;
	return temp;
}

void insertTree(nodeptr *root, int data)
{
	if (*root == NULL) {
		*root = newNode(data);
		return;
	}

	printf("\nEnter 1 to insert left of %d or 2 to insert right: ", (*root)->data);
	int n;
	scanf("%d", &n);

	if (n == 1)
		insertTree(&(*root)->left, data);
	else
		insertTree(&(*root)->right, data);
}

int countNodes(nodeptr root)
{
	opcount++;

	if (root == NULL)
		return 0;

	return 1 + countNodes(root->left) + countNodes(root->right);
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

	printf("\nThe no. of nodes of the tree is: %d", countNodes(root));
	printf("\nOpcount is: %d", opcount);

	return 0;
}