#include <stdio.h>
#include <stdlib.h>

void hanoi(int n ,char from ,char to ,char aux){
	if(n==1){
		printf("Move disk 1 from rod %c to rod %c",from,to);
		return ;
	}
	hanoi(n-1,from,aux,to);

	printf("Move disk %d from rod %c to rod %c", n ,from , to);
	hanoi(n-1,aux,to,from);
}



int main(){
	int t;
	scanf("%d",&t);
	while(t-->0){
		int n;
		scanf("%d",&n);
		hanoi(n,'A','B','C');
		
	}
	return 0;
}