/*
Using tsp by using permutation 
*/

#include <stdio.h>
#include <stdlib.h>
#include <limit.h>

#define v 4

int tsp(int graph[][v] ,int s){

//store all vertex apart from source vertex 
	int *vertex =(int*)malloc(sizeof(int)*v);
	for(int i=0;i<v;i++){
		if(i!=s){
			*(vertex+i)=i;
		}
	}

	int min_path =INT_MAX;

	do{
		//store current path weight -->cost 
		int currrent_pathweight =0;

		//compute current path weight 
		int k=s;
		for(int i=0;i<vertex.size();i++){
			currrent_pathweight +=graph[k][vertex[i]];
			k =vertex[i];
		}

		currrent_pathweight +=graph[k][s];

		//update minimum 
		min_path= min(min_path,currrent_pathweight);

	}

	while(next_permutation(vertex.begin(),vertex.end()));

	return min_path;
}


int main(){
	int t;
	scanf("%d",&t);
	while(t-->0){

		int graph[][v]={
			{0,10,15,20},
			{10,0,35,25},
			{15,35,0,30},
			{20,25,30,0}
		};

		int s=0;
		printf(tsp(graph,s));
	}
	return 0;
}