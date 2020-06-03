//Given a graph G convert that graph into adjacency matrix and adjacency list.

#include<stdio.h>
#include<stdlib.h> 

int main()
{
	int e, v;

	printf("Insert no of vertex: ");
	scanf("%d", &v);

	int **mat = malloc(v * sizeof(int*));
	for(int  i = 0 ; i < v ; i++)
		mat[i] = malloc(v * sizeof(int));

	for(int i = 0 ; i < v ; i++)
		for(int j = 0 ; j < v ; j++)
			mat[i][j] = 0;

	printf("Insert no of edges: ");
	scanf("%d", &e);

	for(int i = 0 ; i < e ; i++)
	{
		printf("Insert starting vertex, terminating vertex of edge %d: \n", i + 1);

		int a, b;
		scanf("%d %d", &a, &b);

		mat[a][b] = 1; 
	}

	printf("\n\nAdjacency Matrix:\n");
	for(int i = 0 ; i < v ; i++)
	{
		for(int j = 0 ; j < v ; j++)
			printf("%d\t", mat[i][j]);

		printf("\n");
	}

}