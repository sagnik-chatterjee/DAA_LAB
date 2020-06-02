#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
 
void patternmatch(char *pat,char *txt)
{
    int m = strlen(pat);
    int n = strlen(txt);
    int opcount=0;

    for(int i=0;i<=n-m;i++)
    {
        opcount++;
        for(int j=0;j<m;j++)
        {
            if(*(txt+i+j)!=*(pat+j))
            {
                opcount++;
                break;
            }
            if(j==m)
            {
                opcount++;
                printf("Pattern found at index %d\n",i);
            }
        }
        
    }
printf("the final opcount is %d",opcount);
}


int main()
{
    printf("Enter the no of iterations for the program ");
    int t;
    scanf("%d",&t);
    while(t-- >0)
    {
        printf("Enter the limit for the string \n");
        int limit;
        scanf("%d",&limit);
        char * arr1 =(char*)malloc(sizeof(char)*limit);
        printf("Now enter the main string (from where it is to be searched from )")
        for(int i=0;i<limit;i++)
        {
            scanf("%c",arr1+i);
        }    
        char * arr2 =(char*)malloc(sizeof(char)*limit);
        printf("Now enter the substring (the required pattern) ");
        for(int i=0;i<limit;i++)
        {   
            scanf("%c",arr2+i);

        }
        patternmatch(arr2,arr1);
     }
    return 0;
}

