/***
 problem stmt for finding gcd using consecutive integer method 

 **/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int min(int a ,int b){

	if(a < b)
	{
		return a;
	}
	return b;
}

int gcd(int a, int b) {
		int t = 0;
		int opcount=0;
		int ans =0;
		if(a==0 && b==0)
		{
			t=980;
			opcount++;
		}
		else if(a==0 &&b!=0)
		{
			t = b;
			opcount++;
		}
		else if(a!=0 && b==0)
		{
			t = a ;
			opcount++;
		}
		else
		{
			t =min(a,b);
			while(1)
			{
				opcount++;
				if(a%t==0 && b%t==0)
				{
					break;
				}
				else
				{
					t--;
				}
			}
		}
		printf("opcount is : %d\n",opcount);
		return t;
	}

int main() {
                srand(time(NULL));

                printf("Enter the number of iterations \n");
                int no = 0 ; int ans =0;
                int sum=0;
                scanf("%d",&no);
                while(no-- >0)
                {
                   int no1 =rand()%101;//generates an random number everytime bt 0 to 100
                   int no2 =rand()%101; 
                        ans =gcd(no1,no2);
                     sum =no1+no2;
                    printf("The value of m+n: %d",sum);    
                }

    return 0;
}

