#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int n;
	scanf("%d", &n);
	int arr[n];
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	sum = sum / 2;
	int flag = 0;

	for (int i = 0; i < pow(2, n); i++)
	{
		int j = i;
		int ind = 0;
		int csum = 0;

		for (int k = 0; k < n; k++)
		{
			if (j & 1)
				csum += arr[ind];

			ind++;
			j = j >> 1;  //else shift left
		}

		if (csum == sum)
		{
			printf("Subset found\n");
			j = i;
			ind = 0;
			printf("The set is: ");

			for (int k = 0; k < n; k++)
			{
				if (j & 1)
					printf("%d ", arr[ind]);

				ind++;
				j = j >> 1;  //else shift left
			}

			printf("\n");
			j = i;
			ind = 0;

			printf("The other set: ");

			for (int k = 0; k < n; k++)
			{
				if (!(j & 1))
					printf("%d ", arr[ind]);

				ind++;
				j = j >> 1;  //else shift left
			}

			printf("\n");
			flag = 1;
			break;
		}
	}



	if (!flag)
		printf("No such subset possible\n");

	return 0;
}