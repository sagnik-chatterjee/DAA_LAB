#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif

#define min(x, y) ((x < y) ? x : y)

int conGCD(int a, int b)
{
	for(int t = min(a, b) ; t >= 0 ; t--)
		if (a%t == 0)
			if (b%t == 0)
				return t;
}

int main()
{
	int a, b;
	printf("Enter a, b: ");
	scanf("%d %d", &a, &b);

	printf("GCD IS %d \n" , conGCD(a, b));
}