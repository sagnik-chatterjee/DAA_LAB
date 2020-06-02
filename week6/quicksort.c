 
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int opcount=0;
int partition (int arr[], int low, int high)
{   
    int pivot = arr[high];  // selecting last element as pivot
    int i = (low - 1);  // index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If the current element is smaller than or equal to pivot
        opcount++;//cause the basic operation is the comparision bw the elements 
        if (arr[j] <= pivot)
        {  
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        
        }  
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quicksort(int a[], int p, int r)    
{  
    if(p < r)
    {
        int q;
        q = partition(a, p, r);
        quicksort(a, p, q-1);
        quicksort(a, q+1, r);
        
    }
     
}
void printArray(int a[], int size)
{
    int i;
    for (i=0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
  
}

int main()
{
    int c;
    printf("Enter the number of cases \n ");
    scanf("%d",&c);
    while(c-- >0)
    {
    int n;
    printf("Enter the number of elements \n");
    scanf("%d",&n);    
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    printf("Given array is : \n");
    printArray(arr,n);
    // call quickSort function
    quicksort(arr, 0, n-1);
    
    printf("Sorted array: \n");
    printArray(arr, n);
      printf("Opcount value is %d\n",opcount);
    
    }
    return 0;
}