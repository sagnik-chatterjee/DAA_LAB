#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void swap( int *a ,int *b)
{
    int temp =*a;
    *a =*b;
    *b =temp;
}


void  bubblesort(int *arr,int n)
{int opcount=0;
        for(int i=0;i<n-1;i++)
        {
            
            for(int j=0;j<n-i-1;j++)
            {
                opcount++;  
                if(arr[j] > arr[j+1])
                {
                      
                    swap(&arr[j],&arr[j+1]);
                }
            }
        }
        printf("opcount value is %d \n",opcount);
}

void printarr(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",*arr+i);
    }
    printf("\n");
}
int main()
{
    
    printf("Enter the number of iterations ");
    int iter;
    scanf("%d",&iter);
    while(iter-- >0){
        clock_t t;
    printf(" \n Enter the limit of the array ");
    int limit;
    scanf("%d",&limit);
    int no = 0;
    int *arr =(int*)malloc(sizeof(int)*limit);

    for(int i=0;i<limit;i++)
    {
        scanf("%d",arr+i);

    }
    
    printf("the unsorted array is : \n");
    printarr(arr,limit);
    t =clock();
    bubblesort(arr,limit);
    t=clock() -t;
    printf("the sorted array is : \n");
    printarr(arr,limit);

    double time_taken =((double)t)/CLOCKS_PER_SEC;
    printf("The bubblesort function took %f seconds to execute.",time_taken);
    }
    return 0;
}