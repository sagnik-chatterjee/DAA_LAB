#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

#define min(x, y) ((x < y) ? x : y)

freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

int GCD(int a , int b)
{
	int opcount = 0;

	int c = min(a, b);

	while (1)
	{
		opcount++;

		if (a % c == 0 && b % c == 0)
		{
			printf(" %d \n", opcount);
			return c;
		}

		c--;
	}

}

int main()
{

	int a, b, test;

	test = 99;

	while (test--)
	{
		scanf("%d %d", &a, &b);
		// printf("GCD: %d\n", GCD(a, b));
		GCD(a, b);
	}

	return 0;
}