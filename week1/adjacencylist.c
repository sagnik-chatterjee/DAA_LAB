/**
 * @Date:   2020-04-11T09:33:19+05:30
 * @Last modified time: 2020-05-03T14:11:55+05:30
 */



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//adjLists is not implemented.



//node is a singly linked list
struct node {
	int vertex;
	struct node *next;
};
//graph is a matrix of lists and node
struct Graph{

	int numVertices;
	struct node ** adjlists;
};
//for creating the nextnode
struct node* createnode(int v){
	struct node * newNode =(struct node*)malloc(sizeof(struct node));
	newNode->vertex =v;
	newNode->next =NULL;
	return newNode;
}


struct Graph* createGraph(int vertices){
	struct Graph* graph =(struct Graph*)malloc(sizeof(struct Graph));
	graph->numVertices =vertices;
	graph->adjlists =malloc(vertices * sizeof(struct node*));


	for(int i=0;i< vertices ;i++)
	{
		graph->adjlists[i]=NULL;
	}
	return graph;
}
void addEdge(struct Graph* graph,int src,int dst)
{
	//add edge from src to dest
	struct node* newNode =createNode(dst);
	newNode->next =graph->adjLists[dst];
	newNode->adjLists[src]=newNode;

}
void printgraph(struct Graph* graph){

	for(int v =0;v<graph->numVertices;v++)
	{
		struct node* temp =graph->adjLists[v];
		printf("\n Adjacency list of vertex %d\n",v);
		while(temp)
		{
			printf("%d -> ",temp->vertex);
			temp =temp->next;
		}
		printf("\n");
	}
}

int main()
{
	printf("Enter the number of testcases \n");
	int t;
	scanf("%d",&t);
	while(t-->0){


	printf("Enter the limit of the graph :\n");
	int limit;
	scanf("%d",&limit);
	struct Graph* graph =createGraph(limit);
	printf("Enter the number of edges to be made :\n");
	int edges;
	scanf("%d",&edges);

	printf("Now enter the vertices value for making the connection:\n");
	int *arr1=(int*)malloc(sizeof(int)*edges);
	int *arr2=(int*)malloc(sizeof(int)*edges);

	for(int i=0;i<edges;i++)
	{
		scanf("%d %d",arr1+i,arr2+i);

	}
	for(int i=0;i<edges;i++)
	{
		if(*(arr1+i)>6|| *(arr1+i)<0 || *(arr2+i)>6 || *(arr2+i)<0)
		{
			//set up the value of the arr1 and arr2 as 0
			*(arr1+i)=0;
			*(arr2+i)=0;
		}
	}
	//now putting into the function

	for(int i=0;i<edges;i++)
	{
		addedge(graph,*(arr1+i),*(arr2+i));
	}
		printgraph(graph);
	}

		return 0;
}
