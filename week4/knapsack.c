#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int knapsack(int *w,int *v,int n ,int b)
{
	int temp;
	int maxval=0,maxseq=0;
	int totweight,totval;
	int opcount=0;
	int index=0;
	///bit array generation 

	for(int i=0;i<pow(2,n);i++)
	{
		++opcount;
		//computing the total weight 
		temp=i;
		totweight=totval=0;
		index=0;
		while(temp)
		{
			if(temp & 0x1)
			{
				totweight=totweight+w[index];
				totval=totval+v[index];
			}
			index++;
			temp=temp >> 1; //shifting by bits 

		}
		if(totweight<=b && totval >maxval)
		{
			maxval =totval;
			maxseq=i;

		}

	}
	printf("\n Operation count=%d\n",opcount);
	return maxseq;	
}

int main()
{
	int *v,*w,n,knaps,b;
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	v =(int*)calloc(n,sizeof(int));
	w =(int*)calloc(n,sizeof(int));
	printf("Please enter the weights");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&w[i]);
	}
	printf("Please enter the values");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&v[i]);
		
	}
	printf("Please enter the Knapsack capacity \n");
	scanf("%d",&b);
	knaps =knapsack(w,v,n,b);
	printf("Knapsack contians the following items \n");
	int i=0;
	while(knaps)
	{
		if(knaps & 0x1)
		{
			printf("item %d value %d",(i+1),v[i]);
		
		}
			i++;
		knaps =knaps >> 1;
	}
	return 0;
}