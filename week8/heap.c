#include<stdio.h>
#include<stdlib.h>

int opcount = 0;

int swap(int &a, int &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

int main()
{
	int n;
	printf("Enter size of heap: ");
	scanf("%d", &n);

	int heap[n + 1];
	printf("Enter elements of heap: ");

	for (int i = 1; i <= n; i++)
	{
		scanf("%d ", &heap[i]);
		int j = i >> 1;

		if (j > 0)
		{
			opcount++;

			if (heap[i] > heap[j])
				swap(heap[i], heap[j]);
`		}
	}

	printf("The heap is:  ");

	for (int i = 1; i <= n; i++)
		printf("%d\t", heap[i]);

	printf("\nOperation Count: %d", opcount);
}