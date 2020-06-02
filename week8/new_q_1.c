#include <stdio.h> 
#include <stdlib.h>
  
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) { 
        swap(&arr[i], &arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
  
// Function to build a Max-Heap from the given array 
void buildHeap(int arr[], int n) 
{ 
    // Index of last non-leaf node 
    int startIdx = (n / 2) - 1; 
  
    // Perform reverse level order traversal 
    // from last non-leaf node and heapify 
    // each node 
    for (int i = startIdx; i >= 0; i--) { 
        heapify(arr, n, i); 
    } 
} 
  
// A utility function to print the array 
// representation of Heap 
void printHeap(int arr[], int n) 
{ 
    printf("Array representation of Heap is:\n"); 
  
    for (int i = 0; i < n; ++i) 
        {
            printf("%d\n",arr[i]);
        }

}
  
// Driver Code 
int main() 
{ 
    printf("Enter the number of testcases \n");
    int testcases;
    scanf("%d",&testcases);
    while(testcases-- >0)
    {
        printf("Enter the size of the array \n");
        int size;
        scanf("%d",&size);
        printf("Now enter the eleemnts of the array \n");
        int arr[size];  
        for(int i=0;i<size;i++)
        {
            scanf("%d",&arr[i]);
        }
        printf("The original array is \n");
        printHeap(arr,size);
        printf("The array after applyting heapify is \n");
        buildHeap(arr, size); 
        printHeap(arr, size);

    }
    return 0; 
} 