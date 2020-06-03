//sort using bubble sort 

#include <stdio.h>
#include <stdlib.h>


void swap(int *x,int *y){

	int temp = *x;
	*x =*y;
	*y=temp;
}

void bubbleSort(int *arr ,int size){
	for(int i=0;i<size-1;i++){
		for (int j=0;j <size-i-1;j++){
			if(arr[j] > arr[j+1]){
				swap(&arr[j], & arr[j+1]);
			}
		}
	}

}

void printArr(int *arr ,int size){
	for(int i=0;i<size;i++){
		printf("%d",*arr+i);
	}
}




int main(){
	int t;
	scanf("%d",&t);
	while(t-->0){
		int size ;
		scanf("%d",&size);
		int *arr =(int*)malloc(sizeof(int)*size);
		for(int i=0;i<size;i++){
			scanf("%d",(arr+i));
		}
		bubbleSort(arr,size);
		printf("Sorted array");
		printArr(arr,size);
	}
	return 0;
}