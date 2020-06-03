#include <stdlib.h>
#include <stdio.h>

int nthfibo(int n){
	if(n==0){
		return 0;
	}
	else if(n==1){
		return 1;
	}
	else{
		return fib(n-1)+fib(n-2);
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t-->0){
		int n ;
		scanf("%d\n",&n);
		printf("%d\n",fibon(n));
	}
	return 0;
}