/*
to sort the elements using distribution 
counting method 
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define RNAGE 255 

void countsort(char *arr,int size){
	//the output characetr array that will have sorted arr 
	char output[size];

	//create a count array to srtore count of individual 
	// characters and initilaize count array as 0
	int count[RANGE+1];
	memset(count,0,sizeof(count));

	//store count of each character 
	int i;
	for(i=0;arr[i];++i)
		++count[arr[i]];

	//change count[i] so that count[i] now contians actual 
	//position of this character in output array 

	for(i=1;i<=RANGE;++i)
		count[i] +=count[i-1];

	for(i=0;arr[i];++i){
		output[count[arr[i]]-1] =arr[i];
		--count[arr[i]];
	}
	for(i=0;arr[i];++i)
		arr[i] =output[i];

}




int main(){
	int t;
	scanf("%d",&t);
	while(t-->0){
		int size;
		scanf("%d",&size);
		int *arr =(int*)malloc(sizeof(int)*size);
		for(int i=0;i<size;i++){
			scanf("%d",(arr+i));
		}

	}
	return 0;
}