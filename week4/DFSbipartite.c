/*
To check if  a graph is bipartitie using coloring mechanism
and DFS 
*/
/*Algorithm 

   1. Use a color[] array which stores 0 or 1 for every node which denotes opposite colors.
   2. Call the function DFS from any node.
   3. If the node u has not been visited previously, then assign !color[v] to color[u] and call DFS again to visit nodes connected to u.
   4. If at any point, color[u] is equal to !color[v], then the node is bipartite.
   5. Modify the DFS function such that it returns a boolean value at the end.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void addEdge(int *adj ,int u,int v){
	//add u to the last postiion of adj matrix --> adj[u].pb(v)

	// add v to the vector --> adj[v].pb(u)
}

bool isBipartite(int* adj ,int v, bool* visited ,int *color ){
	for(int u=0;u<adj[v];u++){
		if(visited[u]==false){
			visited[u]=true;

			color[u]!=color[v];

			if(!isBipartite(adj,u,visited,color)){
				return false;
			}
			else if(color[u]==color[v]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t-->0){
		int n ;
		scanf("%d",&n);
	
		//to maintian the adjacecny list of graph
		int *adj=(int*)malloc(sizeof(int)*(n+1));

		//to keep a check on whether a node is discovered or not 
		bool *visited=  (bool*)malloc(sizeof(bool)*(n+1));

		//to color the vertices of graph using 2 colors 

		int* color =(int*)malloc(sizeof(int)*(n+1));

		//adding edges to the graph 


		addEdge(adj,1,2);

		addEdge(adj,2,3);
		addEdge(adj,3,4);
		addEdge(adj,4,5);
		addEdge(adj,5,6);
		addEdge(adj,6,1);

		//making the source node as visited 
		visited[1]=true;

		//marking the source node with a color 
		color[1]=0;

		//function to check if the graph 
		//is bipartitie or not 
		if(isBipartite(adj,1,visited,color)){
			printf("Bipartite graph");
		}
		else{
			printf("Not a bipartite");
		}

	}
	return 0;
}