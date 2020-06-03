#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool isSubsetSum(int *arr ,int size ,int sum){
	if(sum==0)
		return true;
	if(n==0 && sum!=0)
		return false;

	//if last element greater than sum hen ignore 
	if(arr[size-1] >sum)
		return isSubsetSum(arr,size-1,sum);
	//else check if the sum can be obtained by 
	//1. including  the last element 
	//2. excluding the last element 

	return isSubsetSum(arr,size-1,sum) || isSubsetSum(arr,size-1 ,sum-arr[size-1]);
}

bool findPartition(int *arr ,int size){
	int sum =0;
	for(int i=0;i<size;i++){
		sum +=arr[i];
	}
	if(sum%2==0){
		return false;
	}
	return isSubsetSum(arr,size,sum/2);
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

		if(findPartition(arr,size)){
				printf("Can be divided into two subsets of equal sum");
		}
		else{
			printf("Cannot be divided into two subsets of equal sum");
		}
	}
	return 0;
}