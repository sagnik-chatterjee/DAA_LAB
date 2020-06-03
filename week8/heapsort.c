#include<stdio.h>
#include<stdlib.h>

int opcount = 0;

int swap(int &a, int &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

void heapify(int n, int heap[])
{
	int i = n >> 1;

	while (i > 0) 
	{
		int j = 2 * i;
		int k = (2 * i) + 1;
		int t;

		if (k <= n)
		{
			if (heap[j] > heap[k])
				t = j;
			else
				t = k;
		}
		
		else
			t = j;

		opcount++;

		if (heap[i] >= heap[t])
			i--;
		else 
		{
			swap(heap[i], heap[t]);

			if (2 * t <= n) 
			{
				if (heap[t] < heap[2 * t])
					i = t;
				else if (2 * t + 1 <= n && heap[t] < heap[2 * t + 1])
					i = t;
				else
					i--;
			}
			else
				i--;
		}
	}
}

void heapsort(int heap[], int n)
{
	int i = n;

	while (i > 1)
	{
		heapify(i, heap);
		swap(heap[i], heap[1]);
		i--;
	}
}

int main()
{
	int n;
	printf("Enter the size of heap: ");
	scanf("%d", &n);

	int heap[n + 1];

	printf("Enter the elements of heap: ");
	for (int i = 1; i <= n; i++)
		scanf("%d", &heap[i]);

	heapsort(heap, n);

	printf("The sorted array is:  ");
	for (int i = 1; i <= n; i++)
		printf("%d\t", heap[i]);

	printf("\nOperation Count: %d", opcount);
}