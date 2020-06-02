#include <stdio.h>
#include <stdlib.h>

void swap(int *a ,int *b)
{
    int temp ;
    temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int *arr ,int size ,int i)
{
    int largest=i;
    int l =2*i+1;
    int r= 2*i+2;

    //1.if left child greater than root 
    if(l<size && arr[l]>arr[largest])
    {
        largest=l;
    }
    //2.if right child is larger than largest so far
    if(r<size && arr[size]> arr[largest])
    {
        largest=r;
    }
    //if largest element is non-root 
    if(largest!=1)
    {
        swap(arr+i,arr+largest);


        //and then recursively heapify the affected sub-tree
        heapify(arr,size,largest);
    }

}

void buildheap(int *arr,int size)//to build max heap from the given array 
{
    int startindex = (size/2)-1; //index of the last non-leaf node 

    //form a level order traversal fromlast non -leaf node and heapify each node 
    for(int i=startindex;i>=0;i--)
    {
        heapify(arr,size,i);//to send it to heapify function which will heapigfy at each level 
    }
}


void printHeap(int *arr ,int n)
{
    printf("Tha array representation of the heap is :\n");
    for(int i=0;i<n;++i)
    {
        printf("%d\n",*arr+i);
    }
    printf("\n");
}

int main()
{
    printf("Enter the number of testcases \n");
    int testcases;
    scanf("%d",&testcases);
    while(testcases-- >0)
    {
    printf("Enter the size of the array \n");
    int size ;
    scanf("%d",&size);
    int *arr =(int *)malloc(sizeof(int)*size);
    printf("Now enter elements into the array \n");
    for(int i=0;i<size;i++)
    {
        scanf("%d",arr+i);
    }
    	buildheap(arr,size);
    	printHeap(arr,size);
    }
    return 0;
}
