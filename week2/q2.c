#include<bits/stdc++.h>
using namespace std;

int power(int a, int b)
{
	int ans = 1;

	for (int i = 0; i < b; i++)
		ans *= a;

	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int sieve[10001];

	for (int i = 0; i < 10001; i++)
		sieve[i] = 0;

	sieve[1] = 1;
	sieve[0] = 1;
	int count = 0;

	for (int i = 2; i < 10001; i++)
		if (sieve[i] == 0)
		{
			count ++;

			for (int j = i * i; j < 10001; j += i)
				sieve[j] = 1;
		}

	// seieve done

	int primes[count];
	int j = 0;

	for (int i = 0; i < 10001; i++)
		if (sieve[i] == 0)
			primes[j++] = i;

	// storing all prime numbers in array done

	int a[count];
	int b[count];



	int test = 44;
	while (test--)
	{
		int opcount = 0;

		int c, d;
		scanf("%d %d", &c, &d);
		int x = c, y = d;

		int count1 = 0;

		while (c > 0)
		{
			int counts = 0;

			while (c > 0)
			{
				opcount++;

				if (c % primes[count1] != 0)
				{
					a[count1] = counts;
					count1++;
					break;
				}
				else
				{
					c /= primes[count1];
					counts++;
				}
			}

			if (count1 == count)
				break;
		}

		int count2 = 0;

		while (d > 0)
		{
			int counts = 0;

			while (d > 0)
			{
				opcount++;

				if (d % primes[count2] != 0)
				{
					b[count2] = counts;
					count2++;
					break;
				}
				else
				{
					d /= primes[count2];
					counts++;
				}
			}

			if (count2 == count)
				break;
		}

		int pow;
		int gcd = 1;

		for (int i = 0; i < count; i++)
		{
			if (b[i] < a[i])
				pow = b[i];
			else
				pow = a[i];

			gcd *= (power(primes[i], pow));
		}

		cout << opcount << endl;
	}

	return 0;
}