/**
Implementing an horspool_algorithm in C
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 500

char t[size];

void shiftTable(char* subString){
    int m =strlen(subString);
    for(int i=0;i<size;i++){
        t[i]=m;
    }
    for(int j=0;j<m-1;j++){
        t[subString[j]]=m-1-j;
    }

}
int horspool(char* mainString ,char* subString){
    int n = strlen(mainString);
    int m = strlen(subString);

    printf("Length of text = %d\n",n);
    printf("Length of pattern =%d\n ",m);

    int i=m-1;
    while(i<n){
        int k=0;
        while((k<m)&&(subString[m-1-k]==mainString[i-k])){
            k++;
        }
        if(k==m){
            return (i-m+1);
        }
        else{
            i+=t[mainString[i]];
        }
    }
return -1;//if not found return -1
}



int main(){
    int t;
    scanf("%d",&t);
    while(t-->0){
       
        int p;
        scanf("%d",&p);
        printf("Now enter the main string \n");
        char* mainString =(char*)malloc(sizeof(char)*p);
        for(int i=0;i<p;i++){
            scanf("%c",mainString+i);
        }
        int q;
        scanf("%d",&q);
        printf("Now enter the substring \n");
        char* subString=(char*)malloc(sizeof(char)*q);
        for(int i=0;i<q;i++){
            scanf("%c",subString+i);
        }
        shiftTable(subString);
        int pos =horspool(mainString,subString);
        if(pos>=0){
            printf("\n The desired pattern was found starting from the position %d",pos+1);
        }
        else {
            printf("\n The pattern was not found in the given string . ");
        }
    }
    return 0;
}