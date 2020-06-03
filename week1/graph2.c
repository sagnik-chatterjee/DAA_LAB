#include <stdio.h>
#include <stdlib.h>

typedef struct node* nptr;
typedef struct node
{
	nptr next;
	int data;
} node;

nptr createNode(int x)
{
	nptr temp = (nptr)malloc(sizeof(node));
	temp -> data = x;
	temp -> next = NULL;
	return temp;
}

nptr insertRear(nptr head, int ele)
{
	if (head == NULL)
	{
		head = createNode(ele);
		return head;
	}

	nptr rear = head;

	while (rear -> next != NULL)
		rear = rear -> next;

	nptr temp = createNode(ele);
	rear -> next = temp;

	return head;
}

void display(nptr head)
{
	nptr temp = head;

	printf("%d : ", temp->data);
	temp = temp -> next;

	while (temp != NULL)
	{
		printf("%d --> ", temp -> data);
		temp = temp -> next;
	}

	printf("NULL\n");
}

int main()
{
	int e, v;

	printf("Insert no of vertex: ");
	scanf("%d", &v);

	nptr* header = malloc(v * sizeof(nptr));

	for(int i = 0 ; i < v ; i++)
		header[i] = insertRear(header[i], i);

	printf("Insert no of edges: ");
	scanf("%d", &e);

	for(int i = 0 ; i < e ; i++)
	{
		printf("Insert starting vertex, terminating vertex of edge %d: \n", i + 1);

		int a, b;
		scanf("%d %d", &a, &b);

		header[a] = insertRear(header[a], b);
	}

	printf("\nAdjacency Lists::\n");
	for(int i = 0 ; i < v ; i++)
	{
		display(header[i]);
		printf("\n");
	}

}