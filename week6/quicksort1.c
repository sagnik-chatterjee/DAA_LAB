#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(int arr[],int i,int j){
	int temp;
	temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
int partition(int arr[],int low,int high){
	int pivot,i,j;
	pivot=arr[low];
	i=low+1;
	for(j=low+1;j<=high;j++){
		if(arr[j]<pivot){
			swap(arr,i,j);
			i++;
		}
	}
	swap(arr,low,i-1);
	return i-1;
}
void Quick_sort(int arr[],int low,int high){
	int s;
	printf("\nlow:%d",low);
	printf("\nhigh:%d",high);
	if(low<high){
		s=partition(arr,low,high);
		printf("\ns=%d",s);
		Quick_sort(arr,low,s-1);
		Quick_sort(arr,s+1,high);
	}

}
int main(){
	int size,i;
	int *arr;
	printf("\n Enter the number of elements:\n");
	scanf("%d",&size);
	arr=(int *)calloc(size,sizeof(int));
	printf("\n Enter the array elements:\n");
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	printf("\n The array entered is:\n");
	for(i=0;i<size;i++){
		printf("%d\t",arr[i]);
	}
	Quick_sort(arr,0,size-1);
	printf("\n The sorted array is:\n");
	for(i=0;i<size;i++){
		printf("%d\t",arr[i]);
	}
}