#include<stdio.h>
#include<stdlib.h>

typedef struct key * ptr;
typedef struct key {
	int data;
	ptr link;
} key;

int cmp = 0;

void insertR(ptr* front, int n)
{
	ptr temp, a;
	a = *front;

	temp = (ptr)malloc(sizeof(key));
	temp->data = n;

	if (*front == NULL)
	{
		temp->link = NULL;
		*front = temp;
	}
	else
	{
		while (a->link != NULL)
			a = a->link;

		temp->link = NULL;
		a->link = temp;
	}
}

void create_hash(int m, int n, ptr hash[])
{
	int a, b;
	printf("Enter hash elements: ");

	for (int i = 0; i < n; i++)
	{
		printf("Enter element %d: ", i);
		scanf("%d", &a);
		b = a % m;
		insertR(&hash[b], a);
	}
}

int search(int m, int key, ptr hash[])
{
	int a = key % m;
	ptr temp = hash[a];

	while (temp != NULL)
	{
		cmp++;

		if (temp->data == key)
			return 1;

		temp = temp->link;
	}

	return -1;
}

void print(ptr hash[], int m)
{
	for (int i = 0; i < m; i++)
	{
		printf("\n");
		ptr temp = hash[i];

		while (temp != NULL)
		{
			printf("%d\t", temp->data);
			temp = temp->link;
		}
	}
}

int main()
{
	int n, m, p, s;

	printf("Enter value of n and m: ");
	scanf("%d %d", &n, &m);

	ptr hash[m];

	for (int i = 0; i < m; i++)
	{
		hash[i] = (ptr)malloc(sizeof(key));
		hash[i]->data = i;
		hash[i]->link = NULL;
	}

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