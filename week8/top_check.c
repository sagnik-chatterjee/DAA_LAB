#include <stdio.h>
#include <stdlib.h>
// stores size of the heap
int end;

void swap(int *x, int *y)
{
	*x = (*x * *y) / (*y = *x);
}

// return left child of A[i]
int LEFT(int i)
{
	return (2 * i + 1);
}

// return right child of A[i]
int RIGHT(int i)
{
	return (2 * i + 2);
}

// Recursive Heapify-down algorithm
// the node at index i and its two direct children
// violates the heap property
void Heapify(int A[], int i)
{
	// get left and right child of node at index i
	int left = LEFT(i);
	int right = RIGHT(i);

	// compare A[i] with its left and right child
	// and find largest value
	int largest = i;

	if (left < end && A[left] > A[i])
		largest = left;

	if (right < end && A[right] > A[largest])
		largest = right;

	// swap with child having greater value and
	// call heapify on the child
	if (largest != i) 
	{
		swap(&A[i], &A[largest]);
		Heapify(A, largest);
	}
}

// re-arrange array elements to build max heap
void BuildHeap(int A[])
{
	// call heapify starting from last internal node all the
	// way upto the root node
	int i = (end - 2) / 2;
	while (i >= 0)
		Heapify(A, i--);
}

void HeapSort(int A[], int n)
{
	// initalize heap size as number of elements in the array
	end = n;

	// re-arrange array elements to build max heap
	BuildHeap(A);

	// (The following loop maintains the invariants that A[0: end-1]
	// is a heap and every element beyond end is greater than
	// everything before it (so A[end: n-1] is in sorted order))

	// do till only one element is left on the heap
	while (end != 1) 
	{
		// move next greatest element to the end of the
		// array (moves it in front of the sorted elements)
		swap(&A[0], &A[end - 1]);

		// decrease heap size by 1
		end--;

		// call Heapify on root node as the swap destroyed
		// the heap property
		Heapify(A, 0);
	}
}

int main(void)
{
	printf("Enter the number of testcases \n");
	int testcases;
	scanf("%d",&testcases);
	while(testcases-- >0)
	{
	printf("Enter the size of the array \n");
	int size;
	scanf("%d",&size);
	printf("Enter the elements of the array \n");
	
	int *arr =(int*)malloc(sizeof(int)*size);
	for(int i=0;i<size;i++)
	{
	scanf("%d",arr+i);
	}
	
	// perform heapsort on the array
	HeapSort(arr, size);

	// print the sorted array
	for (int i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	}
	return 0;
}
