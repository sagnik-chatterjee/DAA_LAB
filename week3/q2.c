#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool bruteForceMatch(char *string1 ,char *string2 ,int size1 ,int size2){
//returns true if the two strings match 
	//else returns false
	bool flag=false;
	for(int i=0;i<size1;i++){
		for(int j=0;j<size2;j++){
			//this will mismatch the first instant there is 
			//a mismatch in character 
			if(*(string1+i)==*(string2+j)){
				flag=true;
			}
			else{
				break;
			}
		}
	}
	return flag;
}



int main(){
	int t;
	scanf("%d",&t);
	while(t-->0){
		int size1;
		scanf("%d",&size1);
		char *string1 =(char*)malloc(sizeof(char)*size1);
		for(int i=0;i<size1;i++){
			scanf("%c",(string1+i));
		}
		int size2;
		scanf("%d",&size2);
		char *string2 =(char*)malloc(sizeof(char)*size2);
		for(int i=0;i<size2;i++){
			scanf("%c",(string2+i));
		}
		if(bruteForceMatch(string1,string2,size1,size2)){
			printf("Matches. \n");
		}
		else{
			printf("Doesn't match. \n");
		}

	}
	return 0;
}