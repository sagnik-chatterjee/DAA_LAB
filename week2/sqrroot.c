#include <stdio.h>
#include <stdlib.h>

int floorSqrt(int x){
	if(x==0 ||x ==1){
		return x;
	}
	else{
		int i=1,result=1;
		while(result <=x){
			i++;
			result = i*i;
		}
		return i-1;
	}
}



int main(){
	int t;
	scanf("%d",&t);
	while(t-->0){
		int x;
		scanf("%d",&x);
		printf("%d\n",floorSqrt(x));
	}
	return 0;
}