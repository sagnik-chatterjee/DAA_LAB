/*
Bipartite using BFS
*/
#include <stdio.h>
#include <stdlib.h>
#include 'queue.h'
#define v 5
#include <stdbool.h>

bool Bipartite(int G[][v],int s){
	 int colorA[V];
   for (int i = 0; i < V; ++i)
   colorA[i] = -1;
   colorA[s] = 1; //Assign a color to the source vertex
   //use queue //Create a queue of vertex numbers and enqueue source vertex for BFS traversal
   q.push(s);
   while (!q.empty()) {
      int w = q.front(); //dequeue a vertex
      q.pop();
      for (int v = 0; v < V; ++v) //Find all non-colored adjacent vertices {
         if (G[w][v] && colorA[v] == -1) //An edge from w to v exists and destination v is not colored {
            colorA[v] = 1 - colorA[w]; //Assign alternate color to this adjacent v of w
            q.push(v);
         } else if (G[w][v] && colorA[v] == colorA[w]) //An edge from w to v exists and destination
            //v is colored with same color as u
            return false;
 	  return true; //if all adjacent vertices can be colored with alternate color

}

int main(){
	int t;
	scanf("%d",&t);
	while(t-->0){
		int g[][v]={
			{0,1,0,0},
			{1,0,0,0},
			{0,0,0,1},
			{1,0,1,0}	
		};
		if(Bipartite(G,0)){
			printf("Grpah is Bipartite \n");
		}
		else{
			printf("Graph is not bipartite \n");
		}

	}
	return 0;
}