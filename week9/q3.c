#include<stdio.h>
#include<stdlib.h>

int cmp = 0;

void create_hash(int m, int n, int hash[])
{
	int a, b;

	printf("Enter hash elements:\n");

	for (int i = 0; i < n; i++)
	{
		printf("Enter element %d: ", i);
		scanf("%d", &a);

		b = a % m;

		int j = b, flag = 0;

		while (flag == 0)
		{
			if (hash[j] == 0)
			{
				hash[j] = a;
				flag = 1;
			}
			else
				j++;

			if (j >= m)
				j = 0;

			if (flag == 0 && j == b)
				flag = -1;
		}

		if (flag == -1)
		{
			printf("\nHash Table Full, No Space. Exiting");
			exit(0);
		}
	}
}

void print(int hash[], int m)
{
	for (int i = -0; i < m; i++)
		printf("%d\t", hash[i]);
}

int search(int m, int key, int hash[])
{
	int a = key % m;
	int flag = 0, i = a;

	while (flag == 0)
	{
		cmp++;

		if (hash[i] == key)
			return 1;

		if (hash[i] == 0)
			return -1;

		i++;

		if (i >= m)
			i = 0;

		if (i == a)
			flag = 1;
	}

	return -1;
}

int main()
{
	int n, m, p, s;

	printf("Enter value of n and m: ");
	scanf("%d %d", &n, &m);

	int hash[m];

	for (int i = 0; i < m; i++)
		hash[i] = 0;

	create_hash(m, n, hash);
	print(hash, m);

	printf("\nEnter key to be searched: ");
	scanf("%d", &s);

	p = search(m, s, hash);

	if (p == -1)
		printf("\nKey not found.\n");
	else
		printf("\nKey Found.\n");

	printf("No. of Comparisons: %d\n\n", cmp);
}