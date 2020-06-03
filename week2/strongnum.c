#include <stdio.h>
#include <stdlib.h>

int factorial(int n){
	if(n==0){
		return 1;
	}
	else if(n==1){
		return 1;
	}
	else{
		return n*factorial(n-1);
	}
}

int* deleteStrong(int* arr,int size){
	int *temp =(int*)malloc(sizeof(int)*size);
	for(int i=0;i<size;i++){
		//storing the factorial values 
		*(temp+i)= factorial(*(arr+i));
		
	}
	int *indices =(int*)malloc(sizeof(int)*size);
	for(int i=0;i<size;i++){
		int val=0;int p=0;
		while(*(temp+i)!=0){
			p= *(temp+i)%10;
			val=val+p;
			p=p/10; 
		}
		if(val==*(temp+i)){
			*(indices+i)=-1234567; //some random big neg number 
		}
	}

		//now all those elemnts that are to be deleted the indices are stored in the 
	//indices arr 

int*result =(int*)malloc(sizeof(int)*size);
for(int i=0;i<size;i++){
	if(*(temp+i)==-1234567){
		continue;
	}
	else{
		*(result+i)= *(temp+i);
	}
}
return result;


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