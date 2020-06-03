/*
to find the gcd of two numbers using euclid's 
algorithm employing 
the decrease and conquer strategy 
*/
#include <stdio.h>
#include <Stdlib.h>

int gcdExtended(int a ,int b ,int *x,int *y){
	if(a==0){
		*x=0;
		*y=1;
		return b;
	}
	int x1,y1; //to store results of recursive call 
	int gcd =gcdExtended(b%a,a,&x1,&y1);

	//update x and y using results of recursive 
	//call
	*x =y1 -(b/a)*x1;
	*y =x1;

	return gcd;

}




int main(){
	int t;
	scanf("%d",&t);
	while(t-->0){

		int x ,y;
		int a =35,b=15;
		int g =gcdExtended(a,b,&x,&y);
		printf("gcd (%d ,%d) =%d",a,b,g);	

	}
	return 0;
}