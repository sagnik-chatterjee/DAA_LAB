/**
 * @Date:   2020-04-11T09:33:21+05:30
 * @Last modified time: 2020-05-03T14:14:51+05:30
 */



#include <stdio.h>
#include <stdlib.h>

void counting_sort(int A[],int size)
{
	int i,j;
	int s[15] ,c[100];
	for(i=0;i<=n-1;i++)
	{
		c[i]=0;
	}
	for(i=0;i<=n-2;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(A[i]<A[j])
				count[j]=count[j]+1;
			else count[i]=count[i]+1;
		}
	}
	for(i=0;i<=n-1;i++)
	s[c[i]]=arr[i];
	printf("The sorted array is :");
	for(i=0;i<=n-1;i++)
	printf("%d",s[i]);
}

int main()
{
		printf("Enter the number of testcases \n");
		int testcases;
		scanf("%d",&testcases);
		while(testcases-- >0)
		{
				int n,k=0,a[15],i;
				printf("Enter the number of integers: ");
				scanf("%d",&n);
				printf("\n Enter the integers to be sorted : \n");
				for(i=1;i<=n;i++)
				scanf("%d",&a[i]);
				counting_sort(a);
				printf("\n");
	}
	return 0;
}
