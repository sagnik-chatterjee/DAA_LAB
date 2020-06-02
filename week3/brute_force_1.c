<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

void patternmatch(char *pat,char *txt)
{
    int m = strlen(pat);
    int n = strlen(txt);
    int opcount=0;

    for(int i=0;i<=n-m;i++)
    {
        
        for(int j=0;j<m;j++)
        {
            if(*(txt+i+j)!=*(pat+j))
            {
                opcount++;
            }
            if(j==m)
            {
                
                printf("Pattern found at index %d\n",i);
            }
        }
        
    }
printf("the final opcount is %d\n",opcount);
}


int main()
{
    printf("Enter the no of iteraztions for the program \n");
    int t;
    scanf("%d",&t);
    while(t-- >0)
    {
        printf("Enter the limit for the string \n");
        int limit;
        scanf("%d",&limit);
        char * arr =(char*)malloc(sizeof(char)*limit);
        printf("Now enter the main string (from where it is to be searched from )\n");
        for(int i=0;i<limit;i++)
        {
            scanf("%c",arr+i);
        }    
        char * arr2 =(char*)malloc(sizeof(char)*limit);
        printf("Now enter the substring (the required pattern)\n ");
        for(int i=0;i<limit;i++)
        {   
            scanf("%c",arr2+i);

        }
        patternmatch(arr2,arr);
     }
    return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

void patternmatch(char *pat,char *txt)
{
    int m = strlen(pat);
    int n = strlen(txt);
    int opcount=0;

    for(int i=0;i<=n-m;i++)
    {
        
        for(int j=0;j<m;j++)
        {  
            if(*(txt+i+j)!=*(pat+j))
            {
                opcount++;
             break;
            }
            if(j==m)
            {
                   
                printf("Pattern found at index %d\n",i);
            }
        }
        
    }
printf("the final opcount is %d\n",opcount);
}


int main()
{
    printf("Enter the no of iteraztions for the program \n");
    int t;
    scanf("%d",&t);
    while(t-- >0)
    {
        printf("Enter the limit for the string \n");
        int limit;
        scanf("%d",&limit);
        char * arr =(char*)malloc(sizeof(char)*limit);
        printf("Now enter the main string (from where it is to be searched from )\n");
        for(int i=0;i<limit;i++)
        {
            scanf("%c",arr+i);
        }    
        char * arr2 =(char*)malloc(sizeof(char)*limit);
        printf("Now enter the substring (the required pattern)\n ");
        for(int i=0;i<limit;i++)
        {   
            scanf("%c",arr2+i);

        }
        patternmatch(arr2,arr);
     }
    return 0;
}
>>>>>>> 21f53057af87e5525be185888267a11aa297548e
