#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int lookup_table[128], comp = 0;

int create_table(char str[])
{
	int i = 0, j;
	int n = strlen(str);

	while (str[i] != '\0')
	{
		j = str[i];
		lookup_table[j] = n - i - 1;
		i++;
	}

	lookup_table[j] = n;
}

int search(char str[], char pat[])
{
	int n = strlen(str);
	int m = strlen(pat);
	int i = m - 1;
	int j = m - 1;
	
	while (i < n && j < m)
	{
		if (j < 0)
			return i + 1;

		comp++;

		if (str[i] != pat[j])
		{
			i = i + lookup_table[str[i]];
			j = m - 1;
		} 
		else 
		{
			i--;
			j--;
		}
	}

	return -1;
}

int main()
{
	char str[50], pat[50];
	
	printf("Enter main String: ");
	scanf(" %s", str);
	
	printf("Enter String to be searched: ");
	scanf(" %s", pat);
	
	int n = strlen(pat);
	
	for (int i = 0; i < 128; i++)
		lookup_table[i] = n;

	create_table(pat);

	for (int i = 'a'; i <= 'z'; i++)
		printf("\n%c %d", i, lookup_table[i]);

	int p = search(str, pat);

	if (p == -1)
		printf("\nString not found.\n");
	else
		printf("\nString Found at Position %d.\n", p + 1);

	printf("No. of Comparisons: %d\n\n", comp);
}