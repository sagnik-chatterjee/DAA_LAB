#include<stdio.h>
#include<stdlib.h>
#define Max_q_Size 100

int opcount = 0;
int n;

typedef struct {
	int arr[Max_q_Size];
	int front, rear;
} Q;

void init(Q *c)
{
	c->front = -1;
	c->rear = -1;
}

int isEmpty(Q *c)
{
	if (c->front == c->rear)
		return 1;
	return 0;
}

void addq(Q *c, int item)
{
	if (c->rear == Max_q_Size - 1)
	{
		printf("Queue Overflow");
		exit(0);
	}

	c->arr[++c->rear] = item;
}

int deleteq(Q *c)
{
	if (c->front == c->rear) 
	{
		printf("Queue Underflow");
		exit(0);
	}

	return (c->arr[++c->front]);
}

void display(Q *c)
{
	printf("\n");
	
	for (int i = c->front + 1; i <= c->rear; i++)
		printf("%d\t", c->arr[i]);
}

void top_sort_sremoval(int indeg[], int visited[], int a[][n], Q *q)
{
	for (int i = 0; i < n; i++)
		if (indeg[i] == 0 && visited[i] == 0)
			addq(q, i);

	int v;
	if (!isEmpty(q))
		v = deleteq(q);
	else
		return;

	if (visited[v] == 0) 
	{
		visited[v] = 1;
	
		for (int j = 0; j < n; j++)
		{
			if (a[v][j] != 0)
			{
				indeg[j] = indeg[j] - 1;
				a[v][j] = 0;
			}
		}
	
		printf("%d\t", v);
	}
	
	top_sort_sremoval(indeg, visited, a, q);
}

int main()
{
	printf("Enter n: ");
	scanf("%d", &n);

	int a[n][n], visited[n];

	printf("Enter adjacency matrix: ");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//printf("\nEnter adjacency for vertex %d and vertex %d: ",i,j);
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
		visited[i] = 0;

	Q q;

	init(&q);
	int indeg[n];

	for (int i = 0; i < n; i++)
	{
		indeg[i] = 0;

		for (int j = 0; j < n; j++)
			indeg[i] += a[j][i];

		//printf("%d\n",indeg[i] );
	}

	top_sort_sremoval(indeg, visited, a, &q);

	for (int j = 0; j < n; j++)
	{
		if (visited[j] == 0)
			top_sort_sremoval(indeg, visited, a, &q);
	}

	printf("\nOperation Count=%d", opcount);
}